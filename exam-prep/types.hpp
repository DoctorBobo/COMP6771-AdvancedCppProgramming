#ifndef TYPES_HPP
#define TYPES_HPP
template <typename T>
using value_type_t = typename T::value_type;
template <typename T>
using difference_type_t = typename T::difference_type;
#endif // TYPES_HPP