#pragma once
#include "IBlockCipher.h"

#include <vector>

class IBlockCipherMode
{
public:
	IBlockCipherMode();
	IBlockCipherMode(IBlockCipher *cipher);
	~IBlockCipherMode();

	virtual void EncryptBlock(std::vector<uint8_t> &cipher_block, const std::vector<uint8_t> &plain_block) = 0;
	virtual void DecryptBlock(std::vector<uint8_t> &plain_block, const std::vector<uint8_t> &cipher_block) = 0;

protected:
	IBlockCipher *cipher_;
};

