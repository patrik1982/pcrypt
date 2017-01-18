#include "Utils.h"

#include <iostream>
#include <iomanip>

using namespace std;

namespace Utils
{

	void print8(uint8_t *data, int n) {
		for (size_t i = 0; i < n; i++) {
			cout << hex << setw(2) << setfill('0') << (int)data[i] << " ";
		}
		cout << endl;
	}

	void print32(uint32_t *data, int n) {
		for (size_t i = 0; i < n; i++) {
			cout << hex << setw(8) << setfill('0') << (int)data[i] << " ";
		}
		cout << endl;
	}

}
