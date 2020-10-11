
#include "Crc8.h"
#include "CrcParameters.h"

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <array>

//*****************************************************************************
void Crc8::DisplayTable() const
{
  int index = 0;

  for (int i = 0; i < 16; ++i)
  {
    for (int j = 0; j < 16; ++j)
    {
      std::cout << "0x" << std::uppercase << std::hex << std::setfill('0') << std::setw(2) << int(crcTable[index++]) << ", ";
    }

    std::cout << "\n";
  }
}

//*****************************************************************************
void Crc8::GenerateTable(uint8_t polynomial, bool reflectIn, bool reflectOut)
{
  for (int byte = 0; byte < 256; ++byte)
  {
    uint8_t crc = (reflectIn ? Reverse(uint8_t(byte)) : byte);

    for (int bit = 8; bit > 0; --bit)
    {
      if (crc & 0x80)
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
uint8_t Crc8::Reverse(uint8_t value) const
{
  value = ((value & 0xAA) >> 1) | ((value & 0x55) << 1);
  value = ((value & 0xCC) >> 2) | ((value & 0x33) << 2);
  value = (value >> 4) | (value << 4);

  return value;
}


