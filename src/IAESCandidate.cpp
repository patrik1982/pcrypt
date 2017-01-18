#include "IAESCandidate.h"


IAESCandidate::IAESCandidate() : variant_(InvalidKey)
{
}

IAESCandidate::~IAESCandidate()
{
}

size_t IAESCandidate::GetKeySize()
{
	switch (variant_) {
	case Key128:
		return 16;
	case Key192:
		return 24;
	case Key256:
		return 32;
	default:
		return 0;
	}
}

size_t IAESCandidate::GetBlockSize()
{
	return 16;
}

