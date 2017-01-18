#include "PCBC.h"

#include "Utils.h"

using namespace std;

PCBC::PCBC()
{
}

PCBC::PCBC(IBlockCipher * cipher) : IBlockCipherMode(cipher)
{
}

PCBC::PCBC(IBlockCipher * cipher, const std::vector<uint8_t> IV) : IBlockCipherMode(cipher), state_(IV)
{
}

PCBC::~PCBC()
{
}

void PCBC::EncryptBlock(std::vector<uint8_t>& cipher_block, const std::vector<uint8_t>& plain_block)
{
	std::vector<uint8_t> input_block;
	std::vector<uint8_t> output_block;
	input_block.resize(cipher_->GetBlockSize());
	output_block.resize(cipher_->GetBlockSize());

	BYTEVECTOR_XOR(input_block, plain_block, state_);
	cipher_->EncryptBlock(cipher_block, input_block);

	BYTEVECTOR_XOR(state_, cipher_block, plain_block);
}
void PCBC::DecryptBlock(std::vector<uint8_t>& plain_block, const std::vector<uint8_t>& cipher_block)
{
	std::vector<uint8_t> output_block;
	output_block.resize(cipher_->GetBlockSize());

	cipher_->DecryptBlock(output_block, cipher_block);
	BYTEVECTOR_XOR(plain_block, output_block, state_);

	BYTEVECTOR_XOR(state_, cipher_block, plain_block);
}

void PCBC::SetIV(const std::vector<uint8_t> IV)
{
	state_ = IV;
}
