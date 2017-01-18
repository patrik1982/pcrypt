#pragma once

#include <assert.h>

#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>


#define ror32(x,n) ( ((x) >> (n)) | ((x) << (32-(n))) )
#define rol32(x,n) ( ((x) << (n)) | ((x) >> (32-(n))) )

/*#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
*/
#define BYTEVECTOR_XOR(RESULT, OP1, OP2) { std::transform(OP1.begin(), OP1.end(), OP2.begin(), std::begin(RESULT), std::bit_xor<uint8_t>()); }

/*template <typename T>
std::vector<T> operator+(const std::vector<T>& a, const std::vector<T>& b)
{
	assert(a.size() == b.size());

	std::vector<T> result;
	result.reserve(a.size());

	std::transform(a.begin(), a.end(), b.begin(),
		std::back_inserter(result), std::bit_xor<T>());
	return result;
}*/

namespace Utils
{
	void print8(uint8_t *data, int n);
	void print32(uint32_t *data, int n);
}

