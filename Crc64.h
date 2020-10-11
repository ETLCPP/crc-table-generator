
#ifndef CRC64_INCLUDED
#define CRC64_INCLUDED

#include <array>
#include <cstdint>

#include "CrcParameters.h"

class Crc64
{
public:

  void DisplayTable() const;
  void GenerateTable(uint64_t polynomial, bool reflectIn, bool reflectOut);

private:

  uint64_t Reverse(uint64_t value) const;

  std::array<uint64_t, 256> crcTable;
};

#endif
