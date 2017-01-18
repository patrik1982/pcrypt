#pragma once
#include "IAESCandidate.h"

class RC6 :
	public IAESCandidate
{
public:
	RC6();
	~RC6();

	void EncryptBlock(std::vector<uint8_t> &ciphertext, const std::vector<uint8_t> &plaintext);
	void DecryptBlock(std::vector<uint8_t> &plaintext, const std::vector<uint8_t> &ciphertext);
	void SetKey(const std::vector<uint8_t> &key);

	void Clear();

private:
	const size_t w=32;			// Word size
	const size_t r=20;			// Number of rounds

	std::vector<uint32_t> S;	// Keys

	uint32_t *S_opt;
};

