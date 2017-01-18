#pragma once
#include "IBlockCipherMode.h"
class PCBC :
	public IBlockCipherMode
{
public:
	PCBC();
	PCBC(IBlockCipher *cipher);
	PCBC(IBlockCipher *cipher, const std::vector<uint8_t>);
	~PCBC();

	void EncryptBlock(std::vector<uint8_t> &cipher_block, const std::vector<uint8_t> &plain_block);
	void DecryptBlock(std::vector<uint8_t> &plain_block, const std::vector<uint8_t> &cipher_block);
	void SetIV(const std::vector<uint8_t> IV);

private:
	std::vector<uint8_t> state_;
};

