#include "CBC.h"

#include "Utils.h"

using namespace std;

CBC::CBC()
{
}

CBC::CBC(IBlockCipher * cipher) : IBlockCipherMode(cipher)
{
}

CBC::CBC(IBlockCipher * cipher, const std::vector<uint8_t> IV) : IBlockCipherMode(cipher), state_(IV)
{
}

CBC::~CBC()
{
}

void CBC::EncryptBlock(std::vector<uint8_t>& cipher_block, const std::vector<uint8_t>& plain_block)
{
	std::vector<uint8_t> input_block;
	input_block.resize(cipher_->GetBlockSize());

	BYTEVECTOR_XOR(input_block, plain_block, state_);
	cipher_->EncryptBlock(cipher_block, input_block);

	state_ = cipher_block;
}
void CBC::DecryptBlock(std::vector<uint8_t>& plain_block, const std::vector<uint8_t>& cipher_block)
{
	std::vector<uint8_t> output_block;
	output_block.resize(cipher_->GetBlockSize());

	cipher_->DecryptBlock(output_block, cipher_block);
	BYTEVECTOR_XOR(plain_block, output_block, state_);

	state_ = cipher_block;
}

void CBC::SetIV(const std::vector<uint8_t> IV)
{
	state_ = IV;
}
