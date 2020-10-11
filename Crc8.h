
#ifndef CRC8_INCLUDED
#define CRC8_INCLUDED

#include <array>
#include <cstdint>

#include "CrcParameters.h"

class Crc8
{
public:

  void DisplayTable() const;
  void GenerateTable(uint8_t polynomial, bool reflectIn, bool reflectOut);

private:

  uint8_t Reverse(uint8_t value) const;

  std::array<uint8_t, 256> crcTable;
};

#endif
