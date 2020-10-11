
#include "Crc32.h"
#include "CrcParameters.h"

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <array>

//*****************************************************************************
void Crc32::DisplayTable() const
{
  int index = 0;

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 16; ++j)
    {
      std::cout << "0x" << std::uppercase << std::hex << std::setfill('0') << std::setw(8) << crcTable[index++] << ", ";
    }

    std::cout << "\n";
  }
}

//*****************************************************************************
void Crc32::GenerateTable(uint32_t polynomial, bool reflectIn, bool reflectOut)
{
  for (int byte = 0; byte < 256; ++byte)
  {
    uint32_t crc = (reflectIn ? (Reverse(uint32_t(byte)) >> 24) : byte);

    for (int bit = 32; bit > 0; --bit)
    {
      if (crc & 0x80000000)
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
uint32_t Crc32::Reverse(uint32_t value) const
{
  value = ((value & 0xAAAAAAAA) >> 1) | ((value & 0x55555555) << 1);
  value = ((value & 0xCCCCCCCC) >> 2) | ((value & 0x33333333) << 2);
  value = ((value & 0xF0F0F0F0) >> 4) | ((value & 0x0F0F0F0F) << 4);
  value = ((value & 0xFF00FF00) >> 8) | ((value & 0x00FF00FF) << 8);
  value = (value >> 16) | (value << 16);

  return value;
}


