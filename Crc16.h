
#ifndef CRC16_INCLUDED
#define CRC16_INCLUDED

#include <array>
#include <cstdint>

#include "CrcParameters.h"

class Crc16
{
public:

  void DisplayTable() const;
  void GenerateTable(uint16_t polynomial, bool reflectIn, bool reflectOut);

private:

  uint16_t Reverse(uint16_t value) const;

  std::array<uint16_t, 256> crcTable;
};

#endif
