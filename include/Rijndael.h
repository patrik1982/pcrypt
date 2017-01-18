#pragma once
#include "IAESCandidate.h"

class Rijndael :
	public IAESCandidate
{
public:
	Rijndael();
	~Rijndael();

	void EncryptBlock(std::vector<uint8_t> &ciphertext, const std::vector<uint8_t> &plaintext);
	void DecryptBlock(std::vector<uint8_t> &plaintext, const std::vector<uint8_t> &ciphertext);
	void SetKey(const std::vector<uint8_t> &key);

	void Clear();

private:
	bool use_sse4_aes_ni_ = false;

	size_t number_of_rounds_;

	std::vector<uint32_t> encryption_keys_;
	std::vector<uint32_t> decryption_keys_;

	void CalculateRoundKeys(const uint32_t *key);

	static uint32_t g(const uint32_t w, const uint8_t rc);
	static uint32_t h(const uint32_t w);

	static void InvMixColumns(uint32_t *data);

	static const uint8_t RC[];

	static const uint8_t  Sbox[];
	static const uint32_t TBox0[];
	static const uint32_t TBox1[];
	static const uint32_t TBox2[];
	static const uint32_t TBox3[];

	static const uint8_t  invSbox[];
	static const uint32_t invTBox0[];
	static const uint32_t invTBox1[];
	static const uint32_t invTBox2[];
	static const uint32_t invTBox3[];

	static const uint8_t  GFmult0x09[];
	static const uint8_t  GFmult0x0b[];
	static const uint8_t  GFmult0x0d[];
	static const uint8_t  GFmult0x0e[];
};
