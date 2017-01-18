#include "ECB.h"

using namespace std;

ECB::ECB()
{
}

ECB::ECB(IBlockCipher * cipher) : IBlockCipherMode(cipher)
{
}


ECB::~ECB()
{
}

void ECB::EncryptBlock(vector<uint8_t>& cipher_block, const vector<uint8_t>& plain_block)
{
	cipher_->EncryptBlock(cipher_block, plain_block);
}

void ECB::DecryptBlock(vector<uint8_t>& plain_block, const vector<uint8_t>& cipher_block)
{
	cipher_->DecryptBlock(plain_block, cipher_block);
}
