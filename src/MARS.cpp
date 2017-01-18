#include "MARS.h"

using namespace std;

MARS::MARS() : IAESCandidate()
{
}

MARS::~MARS()
{
	Clear();
}

void MARS::EncryptBlock(vector<uint8_t> &ciphertext, const vector<uint8_t> &plaintext)
{
}

void MARS::DecryptBlock(vector<uint8_t> &plaintext, const vector<uint8_t> &ciphertext)
{
}

void MARS::SetKey(const vector<uint8_t> &key)
{
}

void MARS::Clear()
{
}

