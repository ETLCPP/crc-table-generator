
#ifndef CRC32_INCLUDED
#define CRC32_INCLUDED

#include <array>
#include <cstdint>

#include "CrcParameters.h"

class Crc32
{
public:

  void DisplayTable() const;
  void GenerateTable(uint32_t polynomial, bool reflectIn, bool reflectOut);

private:

  uint32_t Reverse(uint32_t value) const;

  std::array<uint32_t, 256> crcTable;
};

#endif
