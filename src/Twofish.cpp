#include "Twofish.h"

using namespace std;

Twofish::Twofish() : IAESCandidate()
{
}

Twofish::~Twofish()
{
	Clear();
}

void Twofish::EncryptBlock(vector<uint8_t> &ciphertext, const vector<uint8_t> &plaintext)
{
}

void Twofish::DecryptBlock(vector<uint8_t> &plaintext, const vector<uint8_t> &ciphertext)
{
}

void Twofish::SetKey(const vector<uint8_t> &key)
{
}

void Twofish::Clear()
{
}

