#include "CFB.h"

#include "Utils.h"

using namespace std;

CFB::CFB()
{
}

CFB::CFB(IBlockCipher * cipher) : IBlockCipherMode(cipher)
{
}

CFB::CFB(IBlockCipher * cipher, const std::vector<uint8_t> IV) : IBlockCipherMode(cipher), state_(IV)
{
}

CFB::~CFB()
{
}

void CFB::EncryptBlock(std::vector<uint8_t>& cipher_block, const std::vector<uint8_t>& plain_block)
{
	std::vector<uint8_t> output_block;
	output_block.resize(cipher_->GetBlockSize());

	cipher_->EncryptBlock(output_block, state_);
	BYTEVECTOR_XOR(cipher_block, output_block, plain_block);

	state_ = cipher_block;
}

void CFB::DecryptBlock(std::vector<uint8_t>& plain_block, const std::vector<uint8_t>& cipher_block)
{
	std::vector<uint8_t> output_block;
	output_block.resize(cipher_->GetBlockSize());

	cipher_->EncryptBlock(output_block, state_);
	BYTEVECTOR_XOR(plain_block, output_block, cipher_block);

	state_ = cipher_block;
}

void CFB::SetIV(const std::vector<uint8_t> IV)
{
	state_ = IV;
}
