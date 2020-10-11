
#include "Crc64.h"
#include "CrcParameters.h"

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <array>

//*****************************************************************************
void Crc64::DisplayTable() const
{
  int index = 0;

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 16; ++j)
    {
      std::cout << "0x" << std::uppercase << std::hex << std::setfill('0') << std::setw(16) << crcTable[index++] << ", ";
    }

    std::cout << "\n";
  }
}

//*****************************************************************************
void Crc64::GenerateTable(uint64_t polynomial, bool reflectIn, bool reflectOut)
{
  for (int byte = 0; byte < 256; ++byte)
  {
    uint64_t crc = (reflectIn ? (Reverse(uint64_t(byte)) >> 56) : byte);

    for (int bit = 0; bit < 64; ++bit)
    {
      if (crc & 0x8000000000000000)
      {
        crc = (crc << 1) ^ polynomial;
      }
      else
      {
        crc <<= 1;
      }
    }

    crcTable[byte] = (reflectOut ? Reverse(crc) : crc);
  }
}

//*****************************************************************************
uint64_t Crc64::Reverse(uint64_t value) const
{
  value = ((value & 0xAAAAAAAAAAAAAAAA) >> 1) | ((value & 0x5555555555555555) << 1);
  value = ((value & 0xCCCCCCCCCCCCCCCC) >> 2) | ((value & 0x3333333333333333) << 2);
  value = ((value & 0xF0F0F0F0F0F0F0F0) >> 4) | ((value & 0x0F0F0F0F0F0F0F0F) << 4);
  value = ((value & 0xFF00FF00FF00FF00) >> 8) | ((value & 0x00FF00FF00FF00FF) << 8);
  value = ((value & 0xFFFF0000FFFF0000) >> 16) | ((value & 0x0000FFFF0000FFFF) << 16);
  value = (value >> 32) | (value << 32);

  return value;
}


