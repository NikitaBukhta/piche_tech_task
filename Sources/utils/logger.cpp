#include "logger.hpp"

#include <codecvt>
#include <locale>

namespace utils {
  
  std::string to_string(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
  }

}