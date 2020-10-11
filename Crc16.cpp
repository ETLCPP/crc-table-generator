
#include "Crc16.h"
#include "CrcParameters.h"

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <array>

//*****************************************************************************
void Crc16::DisplayTable() const
{
  int index = 0;

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 16; ++j)
    {
      std::cout << "0x" << std::uppercase << std::hex << std::setfill('0') << std::setw(4) << crcTable[index++] << ", ";
    }

    std::cout << "\n";
  }
}

//*****************************************************************************
void Crc16::GenerateTable(uint16_t polynomial, bool reflectIn, bool reflectOut)
{
  for (int byte = 0; byte < 256; ++byte)
  {
    uint16_t crc = (reflectIn ? (Reverse(uint16_t(byte)) >> 8) : byte);

    for (int bit = 16; bit > 0; --bit)
    {
      if (crc & 0x8000)
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
uint16_t Crc16::Reverse(uint16_t value) const
{
  value = ((value & 0xAAAA) >> 1) | ((value & 0x5555) << 1);
  value = ((value & 0xCCCC) >> 2) | ((value & 0x3333) << 2);
  value = ((value & 0xF0F0) >> 4) | ((value & 0x0F0F) << 4);
  value = (value >> 8) | (value << 8);

  return value;
}


