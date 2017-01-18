#include "Test_Common.h"

#include <iostream>
#include <iomanip>

using namespace std;

void printHex(std::vector<uint8_t> data) {
	for (size_t i = 0; i<data.size(); i++) {
		cout << hex << setw(2) << setfill('0') << (int)data[i] << " ";
	}
	cout << endl;
}

bool compare_data(std::vector<uint8_t> a, std::vector<uint8_t> b) {
	if (a.size() != b.size()) {
		return false;
	}
	for (uint32_t i = 0; i<a.size(); i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}
