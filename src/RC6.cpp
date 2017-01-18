#include "RC6.h"

#include <string.h>

#include "Utils.h"

#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define P32 0xB7E15163  // Derived from the binary expansion of e-2
#define Q32 0x9E3779B9  // Derived from the binary expansion of phi-1

using namespace std;

RC6::RC6() : IAESCandidate()
{
	S_opt = nullptr;
}

RC6::~RC6()
{
  Clear();
}

/* Note: The fastest way of calculating A*(2*A+1) is to calculate
 *  A*A first, add it to itself (yielding 2*A*A) and finally
 *  adding A (yielding the final result A*(2*A+1) = 2*A*A + A.
 *  This makes the compiler laying ot code with only one IMULL
 * */
#define RC6_ENCRYPT_ROUND(x,y,z,w,rk1,rk2) {	\
	tmp = y*y;									\
	t = rol32(2*tmp+y, 5);						\
	tmp = w*w;									\
	u = rol32(2*tmp+w, 5);						\
	x = rol32(x ^ t, u) + rk1;					\
	z = rol32(z ^ u, t) + rk2;					\
}

void RC6::EncryptBlock(vector<uint8_t> &ciphertext, const vector<uint8_t> &plaintext)
{
  uint32_t *cbuf = (uint32_t*)ciphertext.data();
  uint32_t *pbuf = (uint32_t*)plaintext.data();

  ((uint64_t*)cbuf)[0] = ((uint64_t*)pbuf)[0];
  ((uint64_t*)cbuf)[1] = ((uint64_t*)pbuf)[1];

  uint32_t &A = cbuf[0];
  uint32_t &B = cbuf[1];
  uint32_t &C = cbuf[2];
  uint32_t &D = cbuf[3];
  register uint32_t t, u;

  B += S[0];
  D += S[1];

  register uint32_t tmp;

  RC6_ENCRYPT_ROUND(A, B, C, D, S[2], S[3]);
  RC6_ENCRYPT_ROUND(B, C, D, A, S[4], S[5]);
  RC6_ENCRYPT_ROUND(C, D, A, B, S[6], S[7]);
  RC6_ENCRYPT_ROUND(D, A, B, C, S[8], S[9]);

  RC6_ENCRYPT_ROUND(A, B, C, D, S[10], S[11]);
  RC6_ENCRYPT_ROUND(B, C, D, A, S[12], S[13]);
  RC6_ENCRYPT_ROUND(C, D, A, B, S[14], S[15]);
  RC6_ENCRYPT_ROUND(D, A, B, C, S[16], S[17]);

  RC6_ENCRYPT_ROUND(A, B, C, D, S[18], S[19]);
  RC6_ENCRYPT_ROUND(B, C, D, A, S[20], S[21]);
  RC6_ENCRYPT_ROUND(C, D, A, B, S[22], S[23]);
  RC6_ENCRYPT_ROUND(D, A, B, C, S[24], S[25]);

  RC6_ENCRYPT_ROUND(A, B, C, D, S[26], S[27]);
  RC6_ENCRYPT_ROUND(B, C, D, A, S[28], S[29]);
  RC6_ENCRYPT_ROUND(C, D, A, B, S[30], S[31]);
  RC6_ENCRYPT_ROUND(D, A, B, C, S[32], S[33]);

  RC6_ENCRYPT_ROUND(A, B, C, D, S[34], S[35]);
  RC6_ENCRYPT_ROUND(B, C, D, A, S[36], S[37]);
  RC6_ENCRYPT_ROUND(C, D, A, B, S[38], S[39]);
  RC6_ENCRYPT_ROUND(D, A, B, C, S[40], S[41]);

  A += S[42];
  C += S[43];
}

void RC6::DecryptBlock(vector<uint8_t> &plaintext, const vector<uint8_t> &ciphertext)
{
  uint32_t *cbuf = (uint32_t*)ciphertext.data();
  uint32_t *pbuf = (uint32_t*)plaintext.data();

  uint32_t A, B, C, D, tmp;
  uint32_t t, u;
  int i;

  A = cbuf[0];
  B = cbuf[1];
  C = cbuf[2];
  D = cbuf[3];

  C -= S[43];
  A -= S[42];
  for (i = 20; i >= 1; i--) {
    tmp = A;
    A = D;
    D = C;
    C = B;
    B = tmp;

    u = rol32((D * (2 * D + 1)), 5);
    t = rol32((B * (2 * B + 1)), 5);
    C = ror32(C - S[2 * i + 1], t % 32) ^ u;
    A = ror32(A - S[2 * i], u % 32) ^ t;
  }
  D -= S[1];
  B -= S[0];

  pbuf[0] = A;
  pbuf[1] = B;
  pbuf[2] = C;
  pbuf[3] = D;
}

void RC6::SetKey(const vector<uint8_t> &key)
{
  uint32_t L[8];
  size_t c;
  size_t key_length;

  uint32_t A, B;
  uint32_t i, j;

  key_length = key.size();
  memset(L, 0, 32);
  memcpy(L, key.data(), key_length);
  if (key_length > 0) {
    c = (key_length + 3) / 4;
  }
  else {
    c = 1;
  }

  S = vector<uint32_t>(44);
  S_opt = (uint32_t*)malloc((44+4)*sizeof(uint32_t));
  S[0] = P32;
  for (i = 1; i <= 43; i++) {
    S[i] = S[i - 1] + Q32;
  }

  A = B = i = j = 0;

  size_t v = 3 * MAX(c, 44);
  for (int s = 1; s <= v; s++) {
    A = S[i] = rol32(S[i] + A + B, 3);
    B = L[j] = rol32(L[j] + A + B, (A + B) % 32);

    i = (i + 1) % 44;
    j = (j + 1) % c;
  }
}

void RC6::Clear()
{
}

