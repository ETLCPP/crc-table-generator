
#include <iostream>
#include <iomanip>
#include <algorithm>

#include "CrcParameters.h"
#include "Crc8.h"
#include "Crc16.h"
#include "Crc32.h"
#include "Crc64.h"

CrcTypes crcTypes;
Crc8  crc8;
Crc16 crc16;
Crc32 crc32;
Crc64 crc64;

//*****************************************************************************
void ListTypes()
{
  std::cout << "Valid CRC types:\n";

  // List CRC-8 types
  for (CrcTypes::const_iterator itr = crcTypes.begin(); itr != crcTypes.end(); ++itr)
  {
    if (itr->first.substr(0, 4) == "crc8")
    {
      const CrcParameters& parameters = itr->second;
      std::cout << std::left << std::setfill(' ') << std::setw(20) << itr->first
                << " : " 
                << "0x" << std::uppercase << std::hex << std::setfill('0') << std::setw(2) << int(std::get<uint8_t>(parameters.polynomial)) << " : "
                << std::boolalpha << std::left << std::setw(5) << std::setfill(' ')
                << parameters.reflectIn << " : "
                << parameters.reflectOut
                << "\n";
    }
  }

  std::cout << "\n";

  // List CRC-16 types
  for (CrcTypes::const_iterator itr = crcTypes.begin(); itr != crcTypes.end(); ++itr)
  {
    
    if (itr->first.substr(0, 5) == "crc16")
    {
      const CrcParameters& parameters = itr->second;
      std::cout << std::left << std::setfill(' ') << std::setw(20) << itr->first
                << " : "
                << "0x" << std::uppercase << std::hex << std::setfill('0') << std::setw(4) << std::get<uint16_t>(parameters.polynomial) << " : "
                << std::boolalpha << std::left << std::setw(5) << std::setfill(' ')
                << parameters.reflectIn << " : "
                << parameters.reflectOut
                << "\n";
    }
  }

  std::cout << "\n";

  // List CRC-32 types
  for (CrcTypes::const_iterator itr = crcTypes.begin(); itr != crcTypes.end(); ++itr)
  {
    if (itr->first.substr(0, 5) == "crc32")
    {
      const CrcParameters& parameters = itr->second;
      std::cout << std::left << std::setfill(' ') << std::setw(20) << itr->first
                << " : "
                << "0x" << std::uppercase << std::hex << std::setfill('0') << std::setw(8) << std::get<uint32_t>(parameters.polynomial) << " : "
                << std::boolalpha << std::left << std::setw(5) << std::setfill(' ')
                << parameters.reflectIn << " : "
                << parameters.reflectOut
        << "\n";
    }
  }

  std::cout << "\n";

  // List CRC-64 types
  for (CrcTypes::const_iterator itr = crcTypes.begin(); itr != crcTypes.end(); ++itr)
  {
    if (itr->first.substr(0, 5) == "crc64")
    {
      const CrcParameters& parameters = itr->second;
      std::cout << std::left << std::setfill(' ') << std::setw(20) << itr->first
                << " : "
                << "0x" << std::uppercase << std::hex << std::setfill('0') << std::setw(16) << std::get<uint64_t>(parameters.polynomial) << " : "
                << std::boolalpha << std::left << std::setw(5) << std::setfill(' ')
                << parameters.reflectIn << " : "
                << parameters.reflectOut
                << "\n";
    }
  }

  std::cout << "\n";
}

//*****************************************************************************
void Initialise()
{
  crcTypes["crc8-ccitt"]    = { uint8_t(0x07), false, false };
  crcTypes["crc8-rohc"]     = { uint8_t(0x07), true,  true };
  crcTypes["crc8-cdma2000"] = { uint8_t(0x9B), false, false };
  crcTypes["crc8-wcdma"]    = { uint8_t(0x9B), true,  true };
  crcTypes["crc8-ebu"]      = { uint8_t(0x1D), true,  true };
  crcTypes["crc8-i-code"]   = { uint8_t(0x1D), false, false };
  crcTypes["crc8-darc"]     = { uint8_t(0x39), true,  true };
  crcTypes["crc8-dvb-s2"]   = { uint8_t(0xD5), false, false };
  crcTypes["crc8-itu"]      = { uint8_t(0x07), false, false };
  crcTypes["crc8-maxim"]    = { uint8_t(0x31), true,  true };

  crcTypes["crc16-ccitt"]     = { uint16_t(0x1021), false, false };
  crcTypes["crc16-aug-ccitt"] = { uint16_t(0x1021), false, false };
  crcTypes["crc16-genibus"]   = { uint16_t(0x1021), false, false };
  crcTypes["crc16-xmodem"]    = { uint16_t(0x1021), false, false };
  crcTypes["crc16-mcrf4xx"]   = { uint16_t(0x1021), true,  true };
  crcTypes["crc16-riello"]    = { uint16_t(0x1021), true,  true };
  crcTypes["crc16-tms37157"]  = { uint16_t(0x1021), true,  true };
  crcTypes["crc16-a"]         = { uint16_t(0x1021), true,  true };
  crcTypes["crc16-kermit"]    = { uint16_t(0x1021), true,  true };
  crcTypes["crc16-x25"]       = { uint16_t(0x1021), true,  true };
  crcTypes["crc16-buypass"]   = { uint16_t(0x8005), false, false };
  crcTypes["crc16-dds-110"]   = { uint16_t(0x8005), false, false };
  crcTypes["crc16-arc"]       = { uint16_t(0x8005), true,  true };
  crcTypes["crc16-maxim"]     = { uint16_t(0x8005), true,  true };
  crcTypes["crc16-usb"]       = { uint16_t(0x8005), true,  true };
  crcTypes["crc16-modbus"]    = { uint16_t(0x8005), true,  true };
  crcTypes["crc16-dect-r"]    = { uint16_t(0x0589), false, false };
  crcTypes["crc16-dect-x"]    = { uint16_t(0x0589), false, false };
  crcTypes["crc16-en-13757"]  = { uint16_t(0x3D65), false, false };
  crcTypes["crc16-dnp"]       = { uint16_t(0x3D65), true,  true };
  crcTypes["crc16-cdma2000"]  = { uint16_t(0xC857), false, false };
  crcTypes["crc16-teledisk"]  = { uint16_t(0xA097), false, false };

  crcTypes["crc32-bzip2"]  = { uint32_t(0x04C11DB7), false, false };
  crcTypes["crc32-mpeg2"]  = { uint32_t(0x04C11DB7), false, false };
  crcTypes["crc32-posix"]  = { uint32_t(0x04C11DB7), false, false };
  crcTypes["crc32"]        = { uint32_t(0x04C11DB7), true,  true };
  crcTypes["crc32-jamcrc"] = { uint32_t(0x04C11DB7), true,  true };
  crcTypes["crc32-q"]      = { uint32_t(0x814141AB), false, false };
  crcTypes["crc32-xfr"]    = { uint32_t(0x000000AF), false, false };
  crcTypes["crc32-c"]      = { uint32_t(0x1EDC6F41), false, false };
  crcTypes["crc32-d"]      = { uint32_t(0xA833982B), false, false };

  crcTypes["crc64-ecma"] = { uint64_t(0x42F0E1EBA9EA3693), false, false };
}

//*****************************************************************************
int main(int argc, char* argv[])
{
  Initialise();

  if (argc > 1)
  {
    std::string crcTypeName(argv[1]);

    CrcTypes::const_iterator itr = crcTypes.find(crcTypeName);

    if (itr != crcTypes.end())
    {
      std::cout << "Generating CRC table for " << crcTypeName << "\n\n";

      const CrcParameters& parameters = itr->second;

      // What size of CRC is it?
      CrcParameters::Type crcType = CrcParameters::Type(parameters.polynomial.index());

      switch (crcType)
      {
        case CrcParameters::Type::CRC8:
        {
          crc8.GenerateTable(std::get<uint8_t>(parameters.polynomial), parameters.reflectIn, parameters.reflectOut);
          crc8.DisplayTable();
          break;
        }

        case CrcParameters::Type::CRC16:
        {
          crc16.GenerateTable(std::get<uint16_t>(parameters.polynomial), parameters.reflectIn, parameters.reflectOut);
          crc16.DisplayTable();
          break;
        }

        case CrcParameters::Type::CRC32:
        {
          crc32.GenerateTable(std::get<uint32_t>(parameters.polynomial), parameters.reflectIn, parameters.reflectOut);
          crc32.DisplayTable();
          break;
        }

        case CrcParameters::Type::CRC64:
        {
          crc64.GenerateTable(std::get<uint64_t>(parameters.polynomial), parameters.reflectIn, parameters.reflectOut);
          crc64.DisplayTable();
          break;
        }

        default:
        {
          std::cout << "Unsupported CRC size\n\n";
          break;
        }
      }
    }
    else
    {
      std::cout << "Unknown CRC type : " << crcTypeName << "\n";
      ListTypes();
    }
  }
  else
  {
    std::cout << "\nSyntax: crc-table <crc name>\n";
    std::cout << "Example: crc-table crc8-ccitt\n\n";
    ListTypes();
  }
}