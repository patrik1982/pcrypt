#include "Test_Serpent.h"

#include "BlockCipherTest.h"
#include "Serpent.h"
#include "Test_Common.h"

using namespace std;

namespace TestSerpent {

	void TestAll() {

		BlockCipherTest t("Serpent");

		vector<uint8_t> plaintext128 = {
			0x33, 0xB3, 0xDC, 0x87, 0xED, 0xDD, 0x9B, 0x0F,
			0x6A, 0x1F, 0x40, 0x7D, 0x14, 0x91, 0x93, 0x65
		};
		vector<uint8_t> plaintext192 = {
			0x45, 0x28, 0xCA, 0xCC, 0xB9, 0x54, 0xD4, 0x50,
			0x65, 0x5E, 0x8C, 0xFD, 0x71, 0xCB, 0xFA, 0xC7
		};
		vector<uint8_t> plaintext256 = {
			0x3D, 0xA4, 0x6F, 0xFA, 0x6F, 0x4D, 0x6F, 0x30,
			0xCD, 0x25, 0x83, 0x33, 0xE5, 0xA6, 0x13, 0x69
		};
		t.setPlaintext128(plaintext128);
		t.setPlaintext192(plaintext192);
		t.setPlaintext256(plaintext256);

		t.setCipher(new Serpent());

		t.TestAll();
	}

}
