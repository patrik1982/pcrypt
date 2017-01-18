#pragma once
#include "IBlockCipherMode.h"
class ECB :
	public IBlockCipherMode
{
public:
	ECB();
	ECB(IBlockCipher *cipher);
	~ECB();

	void EncryptBlock(std::vector<uint8_t> &cipher_block, const std::vector<uint8_t> &plain_block);
	void DecryptBlock(std::vector<uint8_t> &plain_block, const std::vector<uint8_t> &cipher_block);
};

