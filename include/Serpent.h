#pragma once
#include "IAESCandidate.h"

class Serpent :
	public IAESCandidate
{
public:
	Serpent();
	~Serpent();

	void EncryptBlock(std::vector<uint8_t> &ciphertext, const std::vector<uint8_t> &plaintext);
	void DecryptBlock(std::vector<uint8_t> &plaintext, const std::vector<uint8_t> &ciphertext);
	void SetKey(const std::vector<uint8_t> &key);

	void Clear();

private:
	std::vector<uint32_t> keys_;
};
