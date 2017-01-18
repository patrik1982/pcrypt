#pragma once
#include "IAESCandidate.h"

class MARS :
	public IAESCandidate
{
public:
	MARS();
	~MARS();

	void EncryptBlock(std::vector<uint8_t> &ciphertext, const std::vector<uint8_t> &plaintext);
	void DecryptBlock(std::vector<uint8_t> &plaintext, const std::vector<uint8_t> &ciphertext);
	void SetKey(const std::vector<uint8_t> &key);

	void Clear();

private:

};

