#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <string>

/**
 * @brief: Conversione da valore numerico a rappresentazione litterale
 * @param: const T a_value (valore da convertire)
 * @returns: stringa contenente la rappresentazione litterale di a_value
 */
template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 2) {
  std::ostringstream out;
  out.precision(n);
  out << std::fixed << a_value;
  return out.str();
}

#endif  // UTILS_H
