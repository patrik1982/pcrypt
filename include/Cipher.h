#pragma once

#include "IBlockCipher.h"
#include "IBlockCipherMode.h"

class Cipher
{
public:
	Cipher();
	~Cipher();

	void Encrypt(std::vector<uint8_t> ciphertext, std::vector<uint8_t> plaintext);
	void Decrypt(std::vector<uint8_t> plaintext, std::vector<uint8_t> ciphertext);
	void SetKey(std::vector<uint8_t> key);

private:
	IBlockCipher *cipher_;
	IBlockCipherMode *mode_;
};

