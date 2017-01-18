#include "OFB.h"

#include "Utils.h"

using namespace std;

OFB::OFB()
{
}

OFB::OFB(IBlockCipher * cipher) : IBlockCipherMode(cipher)
{
}

OFB::OFB(IBlockCipher * cipher, const std::vector<uint8_t> IV) : IBlockCipherMode(cipher), state_(IV)
{
}

OFB::~OFB()
{
}

void OFB::EncryptBlock(std::vector<uint8_t>& cipher_block, const std::vector<uint8_t>& plain_block)
{
	std::vector<uint8_t> output_block;
	output_block.resize(cipher_->GetBlockSize());

	cipher_->EncryptBlock(output_block, state_);
	BYTEVECTOR_XOR(cipher_block, output_block, plain_block);

	state_ = output_block;
}

void OFB::DecryptBlock(std::vector<uint8_t>& plain_block, const std::vector<uint8_t>& cipher_block)
{
	std::vector<uint8_t> output_block;
	output_block.resize(cipher_->GetBlockSize());

	cipher_->EncryptBlock(output_block, state_);
	BYTEVECTOR_XOR(plain_block, output_block, cipher_block);

	state_ = output_block;
}

void OFB::SetIV(const std::vector<uint8_t> IV)
{
	state_ = IV;
}
