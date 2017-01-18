#include "IBlockCipherMode.h"


IBlockCipherMode::IBlockCipherMode() : cipher_(nullptr)
{
}

IBlockCipherMode::IBlockCipherMode(IBlockCipher * cipher) : cipher_(cipher)
{
}


IBlockCipherMode::~IBlockCipherMode()
{
}
