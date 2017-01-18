#pragma once

#include <vector>
#include <stdint.h>

#include <iostream>
#define VERIFY2(a,s) if (!a) std::cout << (s) << " : FAILED !!" << std::endl; else std::cout << (s) << " : Passed" << std::endl;

void printHex(std::vector<uint8_t> data);
bool compare_data(std::vector<uint8_t> a, std::vector<uint8_t> b);

