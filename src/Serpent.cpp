#include "Serpent.h"

#include <string.h>

#include <iostream>
#include <iomanip>

#include "Utils.h"

#define ROUNDS  32
#define PHI		0x9e3779b9

using namespace std;

#include "Serpent_macros.inc"

Serpent::Serpent() : IAESCandidate()
{
	keys_ = vector<uint32_t>((ROUNDS + 1) * 4);
}

Serpent::~Serpent()
{
	Clear();
}
/* Ref:
Timing (128-bit) : encrypt: 72.2426 Mb/s, decrypt: 78.5636 Mb/s.
Timing (192-bit) : encrypt: 71.5039 Mb/s, decrypt: 78.88 Mb/s.
Timing (256-bit) : encrypt: 71.8456 Mb/s, decrypt: 79.0648 Mb/s.
 */
void Serpent::EncryptBlock(vector<uint8_t> &ciphertext, const vector<uint8_t> &plaintext)
{
	uint32_t *cbuf = (uint32_t*)ciphertext.data();
	uint32_t *pbuf = (uint32_t*)plaintext.data();
	uint32_t tmp1[4];
	uint32_t tmp2[4];

	uint32_t t01, t02, t03, t04, t05, t06, t07, t08, t09, t10;
	uint32_t t11, t12, t13, t14, t15, t16, t17, t18;

	int round;

	/*BLOCK_COPY(tmp1, pbuf);
	//*(__m128i*)tmp1 = _mm_xor_si128(*(__m128i*)pbuf, *(__m128i*)&keys_[0]);
	for (round = 0; round < ROUNDS - 1; round++) {
		BLOCK_XOR(tmp1, (keys_.data() + round*4));
		switch (round % 8) {
		case 0:
			SBOX(0, tmp2, tmp1, 0); break;
		case 1:
			SBOX(1, tmp2, tmp1, 0); break;
		case 2:
			SBOX(2, tmp2, tmp1, 0); break;
		case 3:
			SBOX(3, tmp2, tmp1, 0); break;
		case 4:
			SBOX(4, tmp2, tmp1, 0); break;
		case 5:
			SBOX(5, tmp2, tmp1, 0); break;
		case 6:
			SBOX(6, tmp2, tmp1, 0); break;
		case 7:
			SBOX(7, tmp2, tmp1, 0); break;
		}
		LINEAR_TRANSFORMATION(tmp2);
		BLOCK_COPY(tmp1, tmp2);
		BLOCK_XOR(tmp1, (keys_.data() + round*4+4));
	}*/
	BLOCK_COPY(tmp1, pbuf);

	BLOCK_XOR(tmp1, (&keys_[0]));
	SBOX(0, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[4]));
	SBOX(1, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[8]));
	SBOX(2, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[12]));
	SBOX(3, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[16]));
	SBOX(4, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[20]));
	SBOX(5, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[24]));
	SBOX(6, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[28]));
	SBOX(7, tmp2, tmp1, 0);
	BLOCK_COPY(tmp1, tmp2);

	BLOCK_XOR(tmp1, (&keys_[32]));
	SBOX(0, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[36]));
	SBOX(1, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[40]));
	SBOX(2, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[44]));
	SBOX(3, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[48]));
	SBOX(4, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[52]));
	SBOX(5, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[56]));
	SBOX(6, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[60]));
	SBOX(7, tmp2, tmp1, 0);
	BLOCK_COPY(tmp1, tmp2);

	BLOCK_XOR(tmp1, (&keys_[64]));
	SBOX(0, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[68]));
	SBOX(1, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[72]));
	SBOX(2, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[76]));
	SBOX(3, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[80]));
	SBOX(4, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[84]));
	SBOX(5, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[88]));
	SBOX(6, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[92]));
	SBOX(7, tmp2, tmp1, 0);
	BLOCK_COPY(tmp1, tmp2);

	BLOCK_XOR(tmp1, (&keys_[96]));
	SBOX(0, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[100]));
	SBOX(1, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[104]));
	SBOX(2, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[108]));
	SBOX(3, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[112]));
	SBOX(4, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[116]));
	SBOX(5, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);
	BLOCK_XOR(tmp1, (&keys_[120]));
	SBOX(6, tmp2, tmp1, 0);
	LINEAR_TRANSFORMATION(tmp2);
	BLOCK_COPY(tmp1, tmp2);

	BLOCK_XOR(tmp1, (&keys_[124]));
	SBOX(7, tmp2, tmp1, 0);
	//BLOCK_XOR(tmp1, (keys_.data() + (ROUNDS-1) * 4));
	//SBOX(7, tmp2, tmp1, 0);
	//round++;
	BLOCK_COPY(cbuf, tmp2);
	BLOCK_XOR(cbuf, (&keys_[128]));
	//*(__m128i*)cbuf = _mm_xor_si128(*(__m128i*)tmp2, *(__m128i*)&keys_[ROUNDS*4]);
}

void Serpent::DecryptBlock(vector<uint8_t> &plaintext, const vector<uint8_t> &ciphertext)
{
	uint32_t *cbuf = (uint32_t*)ciphertext.data();
	uint32_t *pbuf = (uint32_t*)plaintext.data();
	uint32_t tmp1[4];
	uint32_t tmp2[4];

	uint32_t t01, t02, t03, t04, t05, t06, t07, t08, t09, t10;
	uint32_t t11, t12, t13, t14, t15, t16, t17, t18;

	int round = ROUNDS;

	BLOCK_COPY(tmp1, cbuf);

	BLOCK_XOR(tmp1, (keys_.data() + round * 4));
	SBOX_INVERSE(7, tmp2, tmp1, 0);
	round--;
	BLOCK_XOR(tmp2, (keys_.data() + round * 4));

	for (round--;  round >= 0; round--) {
		BLOCK_COPY(tmp1, tmp2);
		LINEAR_TRANSFORMATION_INVERSE(tmp1);
		switch (round % 8) {
		case 0:
			SBOX_INVERSE(0, tmp2, tmp1, 0); break;
		case 1:
			SBOX_INVERSE(1, tmp2, tmp1, 0); break;
		case 2:
			SBOX_INVERSE(2, tmp2, tmp1, 0); break;
		case 3:
			SBOX_INVERSE(3, tmp2, tmp1, 0); break;
		case 4:
			SBOX_INVERSE(4, tmp2, tmp1, 0); break;
		case 5:
			SBOX_INVERSE(5, tmp2, tmp1, 0); break;
		case 6:
			SBOX_INVERSE(6, tmp2, tmp1, 0); break;
		case 7:
			SBOX_INVERSE(7, tmp2, tmp1, 0); break;
		}
		BLOCK_XOR(tmp2, (keys_.data() + round * 4));
	}
	BLOCK_COPY(pbuf, tmp2);
}

void Serpent::SetKey(const vector<uint8_t> &key)
{
	uint32_t key_prepared[8];
	uint8_t *key8;

	size_t i;
	key8 = (uint8_t*)key_prepared;

	memcpy(key8, key.data(), key.size());
	if (key.size() < 32) {
		key8[key.size()] = 0x01;
	}
	if (key.size() < 31) {
		for (i = key.size() + 1; i < 32; i++) {
			key8[i] = 0;
		}
	}

	uint32_t w_real[140];		/* The `prekey'.  */
	uint32_t k[132];
	uint32_t *w = &w_real[8];

	uint32_t t01, t02, t03, t04, t05, t06, t07, t08, t09, t10;
	uint32_t t11, t12, t13, t14, t15, t16, t17, t18;

	for (i = 0; i < 8; i++) {
		w[i - 8] = key_prepared[i];
	}
	for (i = 0; i < 132; i++) {
		w[i] = rol32(w[i - 8] ^ w[i - 5] ^ w[i - 3] ^ w[i - 1] ^ PHI ^ (uint32_t)i, 11);
	}

	SBOX(3, k, w, 0);
	SBOX(2, k, w, 4);
	SBOX(1, k, w, 8);
	SBOX(0, k, w, 12);
	SBOX(7, k, w, 16);
	SBOX(6, k, w, 20);
	SBOX(5, k, w, 24);
	SBOX(4, k, w, 28);
	SBOX(3, k, w, 32);
	SBOX(2, k, w, 36);
	SBOX(1, k, w, 40);
	SBOX(0, k, w, 44);
	SBOX(7, k, w, 48);
	SBOX(6, k, w, 52);
	SBOX(5, k, w, 56);
	SBOX(4, k, w, 60);
	SBOX(3, k, w, 64);
	SBOX(2, k, w, 68);
	SBOX(1, k, w, 72);
	SBOX(0, k, w, 76);
	SBOX(7, k, w, 80);
	SBOX(6, k, w, 84);
	SBOX(5, k, w, 88);
	SBOX(4, k, w, 92);
	SBOX(3, k, w, 96);
	SBOX(2, k, w, 100);
	SBOX(1, k, w, 104);
	SBOX(0, k, w, 108);
	SBOX(7, k, w, 112);
	SBOX(6, k, w, 116);
	SBOX(5, k, w, 120);
	SBOX(4, k, w, 124);
	SBOX(3, k, w, 128);

	memcpy(keys_.data(), k, 132 * 4);
}

void Serpent::Clear()
{
}

