#include "string_view.h"

// Конструктор по умолчанию.
StringView::StringView() {
  data_ = nullptr;
  len_ = 0;
}

// Конструктор от const char*.
StringView::StringView(const char* data) {
  data_ = data;
  len_ = strlen(data);
}

// Конструктор от const char* и size_t.
StringView::StringView(const char* data, size_t len) {
  data_ = data;
  len_ = len;
}

// Оператор [].
char StringView::operator[](size_t index) const {
  if (index >= len_) {
      throw StringViewOutOfRange();
  }
  return data_[index];
}

// Метод At().
char StringView::At(size_t index) const {
  if (index >= len_) {
    throw StringViewOutOfRange();
  }
  return data_[index];
}

// Метод Front().
char StringView::Front() const {
  if (len_ == 0) {
    throw StringViewOutOfRange();
  }
  return data_[0];
}

// Метод Back().
char StringView::Back() const {
  if (len_ == 0) {
    throw StringViewOutOfRange();
  }
  return data_[len_ - 1];
}

// Метод Size().
size_t StringView::Size() const {
  return len_;
}

// Метод Length().
size_t StringView::Length() const {
  return len_;
}

// Метод Empty().
bool StringView::Empty() const {
  return len_ == 0;
}

// Метод Data().
const char* StringView::Data() const {
  return data_;
}

// Метод Swap().
void StringView::Swap(StringView& value) {
  std::swap(data_, value.data_);
  std::swap(len_, value.len_);
}

// Метод RemovePrefix().
void StringView::RemovePrefix(size_t prefix_size) {
  if (prefix_size > len_) {
    throw StringViewOutOfRange();
  }
  data_ += prefix_size;
  len_ -= prefix_size;
}

// Метод RemoveSuffix().
void StringView::RemoveSuffix(size_t suffix_size) {
  if (suffix_size > len_) {
    throw StringViewOutOfRange();
  }
  len_ -= suffix_size;
}

// Метод Substr().
StringView StringView::Substr(size_t pos, size_t count) const {
  if (pos >= len_) {
    throw StringViewOutOfRange();
  }
  count = std::min(count, Size() - pos);
  return { data_ + pos, count };
}