#include "BlockCipherTest.h"

#include <iostream>
#include <ctime>

#include "Test_Common.h"

using namespace std;

BlockCipherTest::BlockCipherTest(string name)
{
	this->name = name;

	key128 = vector<uint8_t>({
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
	});
	key192 = vector<uint8_t>({
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
		0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17
	});
	key256 = vector<uint8_t>({
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
		0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
		0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F
	});

	plaintext128 = vector<uint8_t>({
		0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	});
	plaintext192 = vector<uint8_t>({
		0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	});
	plaintext256 = vector<uint8_t>({
		0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00, 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	});

	ciphertext128 = vector<uint8_t>({
		0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
		0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF
	});
	ciphertext192 = vector<uint8_t>({
		0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
		0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF
	});
	ciphertext256 = vector<uint8_t>({
		0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
		0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF
	});
}


BlockCipherTest::~BlockCipherTest()
{
}

void BlockCipherTest::Test128()
{
	vector<uint8_t> ciphertext;
	vector<uint8_t> plaintext;
	ciphertext.resize(plaintext128.size());
	plaintext.resize(ciphertext128.size());

	cipher->SetKey(key128);
	cipher->EncryptBlock(ciphertext, plaintext128);
	VERIFY2(compare_data(ciphertext, ciphertext128), name + " 128-bit block encrypt");
	cipher->DecryptBlock(plaintext, ciphertext128);
	VERIFY2(compare_data(plaintext, plaintext128), name + " 128-bit block decrypt");
}

void BlockCipherTest::Test192()
{
	vector<uint8_t> ciphertext;
	vector<uint8_t> plaintext;
	ciphertext.resize(plaintext192.size());
	plaintext.resize(ciphertext192.size());

	cipher->SetKey(key192);
	cipher->EncryptBlock(ciphertext, plaintext192);
	VERIFY2(compare_data(ciphertext, ciphertext192), name + " 192-bit block encrypt");
	cipher->DecryptBlock(plaintext, ciphertext192);
	VERIFY2(compare_data(plaintext, plaintext192), name + " 192-bit block decrypt");
}

void BlockCipherTest::Test256()
{
	vector<uint8_t> ciphertext;
	vector<uint8_t> plaintext;
	ciphertext.resize(plaintext256.size());
	plaintext.resize(ciphertext256.size());

	cipher->SetKey(key256);
	cipher->EncryptBlock(ciphertext, plaintext256);
	VERIFY2(compare_data(ciphertext, ciphertext256), name + " 256-bit block encrypt");
	cipher->DecryptBlock(plaintext, ciphertext256);
	VERIFY2(compare_data(plaintext, plaintext256), name + " 256-bit block decrypt");
}

void BlockCipherTest::MeasureExecutionTime()
{
	vector<uint8_t> c128;
	vector<uint8_t> p128;
	vector<uint8_t> c192;
	vector<uint8_t> p192;
	vector<uint8_t> c256;
	vector<uint8_t> p256;
	c128.resize(plaintext128.size());
	p128.resize(ciphertext128.size());
	c192.resize(plaintext192.size());
	p192.resize(ciphertext192.size());
	c256.resize(plaintext256.size());
	p256.resize(ciphertext256.size());

	size_t n;
	size_t i;
	clock_t begin, end;
	double encrypt_elapsed_secs, decrypt_elapsed_secs;
	double encrypt_speed, decrypt_speed;
	n = 1000000L;

	cipher->SetKey(key128);

	begin = clock();
	for (i = 0L; i<n; i++) {
		cipher->EncryptBlock(c128, plaintext128);
	}
	end = clock();
	encrypt_elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	begin = clock();
	for (i = 0L; i < n; i++) {
		cipher->DecryptBlock(c128, ciphertext128);
	}
	end = clock();
	decrypt_elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	encrypt_speed = 16.0 * n / (encrypt_elapsed_secs * 1024*1024);
	decrypt_speed = 16.0 * n / (decrypt_elapsed_secs * 1024 * 1024);
	end = clock();
	cout << "Timing (128-bit) : encrypt: " << encrypt_speed << " Mb/s, decrypt: " << decrypt_speed << " Mb/s." << endl;

	cipher->SetKey(key192);
	begin = clock();
	for (i = 0L; i<n; i++) {
		cipher->EncryptBlock(c192, plaintext192);
	}
	end = clock();
	encrypt_elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	begin = clock();
	for (i = 0L; i < n; i++) {
		cipher->DecryptBlock(p192, ciphertext192);
	}
	end = clock();
	decrypt_elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	encrypt_speed = 16.0 * n / (encrypt_elapsed_secs * 1024 * 1024);
	decrypt_speed = 16.0 * n / (decrypt_elapsed_secs * 1024 * 1024);
	end = clock();
	cout << "Timing (192-bit) : encrypt: " << encrypt_speed << " Mb/s, decrypt: " << decrypt_speed << " Mb/s." << endl;

	cipher->SetKey(key256);
	begin = clock();
	for (i = 0L; i<n; i++) {
		cipher->EncryptBlock(c256, plaintext256);
	}
	end = clock();
	encrypt_elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	begin = clock();
	for (i = 0L; i < n; i++) {
		cipher->DecryptBlock(p256, ciphertext256);
	}
	end = clock();
	decrypt_elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	encrypt_speed = 16.0 * n / (encrypt_elapsed_secs * 1024 * 1024);
	decrypt_speed = 16.0 * n / (decrypt_elapsed_secs * 1024 * 1024);
	end = clock();
	cout << "Timing (256-bit) : encrypt: " << encrypt_speed << " Mb/s, decrypt: " << decrypt_speed << " Mb/s." << endl;
}

void BlockCipherTest::setCipher(IBlockCipher * cipher)
{
	this->cipher = cipher;
}
void BlockCipherTest::setCipherName(string name)
{
	this->name = name;
}

void BlockCipherTest::setKey128(vector<uint8_t> key) { key128 = key; }
void BlockCipherTest::setKey192(vector<uint8_t> key) { key192 = key; }
void BlockCipherTest::setKey256(vector<uint8_t> key) { key256 = key; }

void BlockCipherTest::setPlaintext128(vector<uint8_t> key) { plaintext128 = key; }
void BlockCipherTest::setPlaintext192(vector<uint8_t> key) { plaintext192 = key; }
void BlockCipherTest::setPlaintext256(vector<uint8_t> key) { plaintext256 = key; }

void BlockCipherTest::setCiphertext128(vector<uint8_t> key) { ciphertext128 = key; }
void BlockCipherTest::setCiphertext192(vector<uint8_t> key) { ciphertext192 = key; }
void BlockCipherTest::setCiphertext256(vector<uint8_t> key) { ciphertext256 = key; }

void BlockCipherTest::TestAll()
{
	cout << endl << "* " << name << endl;

	Test128();
	Test192();
	Test256();

	MeasureExecutionTime();
}
