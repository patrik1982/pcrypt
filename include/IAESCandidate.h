#pragma once
#include "IBlockCipher.h"

typedef enum {
	InvalidKey,
	Key128,
	Key192,
	Key256
} Key_Variant;

class IAESCandidate :
	public IBlockCipher
{
public:
	IAESCandidate();
	~IAESCandidate();

	virtual void EncryptBlock(std::vector<uint8_t> &ciphertext, const std::vector<uint8_t> &plaintext) = 0;
	virtual void DecryptBlock(std::vector<uint8_t> &plaintext, const std::vector<uint8_t> &ciphertext) = 0;
	virtual void SetKey(const std::vector<uint8_t> &key) = 0;

	virtual void Clear() = 0;

	size_t GetKeySize();
	size_t GetBlockSize();

protected:
	Key_Variant variant_;
private:
};

