#pragma once
#include "IBlockCipherMode.h"
class CFB :
	public IBlockCipherMode
{
public:
	CFB();
	CFB(IBlockCipher *cipher);
	CFB(IBlockCipher *cipher, const std::vector<uint8_t>);
	~CFB();

	void EncryptBlock(std::vector<uint8_t> &cipher_block, const std::vector<uint8_t> &plain_block);
	void DecryptBlock(std::vector<uint8_t> &plain_block, const std::vector<uint8_t> &cipher_block);
	void SetIV(const std::vector<uint8_t> IV);

private:
	std::vector<uint8_t> state_;
};

