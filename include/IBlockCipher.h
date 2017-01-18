#pragma once

#include <stdint.h>
#include <stdlib.h>

#include <vector>

class IBlockCipher
{
public:
	IBlockCipher();
	~IBlockCipher();

	virtual void EncryptBlock(std::vector<uint8_t> &ciphertext, const std::vector<uint8_t> &plaintext) = 0;
	virtual void DecryptBlock(std::vector<uint8_t> &plaintext, const std::vector<uint8_t> &ciphertext) = 0;
	virtual void SetKey(const std::vector<uint8_t> &key) = 0;

	virtual void Clear() = 0;

	virtual size_t GetKeySize() = 0;
	virtual size_t GetBlockSize() = 0;

protected:

private:
};
