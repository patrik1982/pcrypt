// pcrypt_test.cpp : Defines the entry point for the console application.
// Test vectors from: https://www.cosic.esat.kuleuven.be/nessie/testvectors/

#include <iostream>

#include "Test_Rijndael.h"
#include "Test_Serpent.h"
#include "Test_RC6.h"
#include "Test_Twofish.h"

#include "Test_EncryptionMode.h"
#include <vector>
#include "RC6.h"
using namespace std;

int main()
{
	TestRijndael::TestAll();
	TestSerpent::TestAll();
	TestRC6::TestAll();
	//TestTwofish::TestAll();
	return 1;
	RC6 *cipher = new RC6();

	vector<uint8_t> key128 = {
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
	};
	vector<uint8_t> plaintext128 = {
		0xB8, 0x4E, 0x1F, 0x38, 0x06, 0x24, 0xFE, 0xD8,
		0xC8, 0xC6, 0x40, 0xCB, 0x28, 0xB6, 0xD9, 0xED
	};
	vector<uint8_t> ciphertext128 = vector<uint8_t>{
		0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
		0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF
	};

	vector<uint8_t> ciphertext;
	vector<uint8_t> plaintext;
	ciphertext.resize(plaintext128.size());
	plaintext.resize(ciphertext128.size());

	cipher->SetKey(key128);
	cipher->EncryptBlock(ciphertext, plaintext128);
	//cipher->DecryptBlock(plaintext, ciphertext128);

	//cout << endl << "* Encryption modes" << endl;
	//TestEncryptionMode::TestAll();
}
