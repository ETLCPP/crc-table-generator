
#ifndef CRC_PARAMETERS_INCLUDED
#define CRC_PARAMETERS_INCLUDED

#include <cstdint>
#include <string>
#include <map>
#include <variant>

//*****************************************************************************
struct CrcParameters
{
  std::variant<uint8_t, uint16_t, uint32_t, uint64_t> polynomial;
  bool reflectIn;
  bool reflectOut;

  enum class Type : int
  {
    CRC8,
    CRC16,
    CRC32,
    CRC64
  };
};

using CrcTypes = std::map <std::string, CrcParameters>;

#endif
