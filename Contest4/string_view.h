#ifndef H_STRING_VIEW
#define H_STRING_VIEW
#include <cstring>
#include <iostream>

class StringView {
private:
  const char* data_;
  size_t len_;
public:
  StringView();
  StringView(const char* data); //NOLINT
  StringView(const char* data, size_t len);
  char operator[](size_t index) const;
  char At(size_t index) const;
  char Front() const;
  char Back() const;
  size_t Size() const;
  size_t Length() const;
  bool Empty() const;
  const char* Data() const;
  void Swap(StringView& value);
  void RemovePrefix(size_t prefix_size);
  void RemoveSuffix(size_t suffix_size);
  StringView Substr(size_t pos, size_t count = -1) const;
};

class StringViewOutOfRange {

};

#endif