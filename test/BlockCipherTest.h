#pragma once

#include <stdint.h>
#include <vector>
#include <string>

#include <IBlockCipher.h>

class BlockCipherTest
{
public:
	BlockCipherTest(std::string name="");
	~BlockCipherTest();

	void Test128();
	void Test192();
	void Test256();
	void MeasureExecutionTime();

	void setCipher(IBlockCipher *cipher);

	void setCipherName(std::string name);

	void setKey128(std::vector<uint8_t> key);
	void setKey192(std::vector<uint8_t> key);
	void setKey256(std::vector<uint8_t> key);

	void setPlaintext128(std::vector<uint8_t> plaintext);
	void setPlaintext192(std::vector<uint8_t> plaintext);
	void setPlaintext256(std::vector<uint8_t> plaintext);

	void setCiphertext128(std::vector<uint8_t> ciphertext);
	void setCiphertext192(std::vector<uint8_t> ciphertext);
	void setCiphertext256(std::vector<uint8_t> ciphertext);

	void TestAll();

protected:
	IBlockCipher *cipher;

	std::string name;

	std::vector<uint8_t> key128;
	std::vector<uint8_t> key192;
	std::vector<uint8_t> key256;

	std::vector<uint8_t> plaintext128;
	std::vector<uint8_t> plaintext192;
	std::vector<uint8_t> plaintext256;

	std::vector<uint8_t> ciphertext128;
	std::vector<uint8_t> ciphertext192;
	std::vector<uint8_t> ciphertext256;
};

