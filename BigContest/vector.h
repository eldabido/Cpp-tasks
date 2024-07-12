#ifndef H_VECTOR
#define H_VECTOR

#include <iostream>
#include <memory>
#include <stdexcept>
#include <iterator>

template<typename T>
class Vector {
 private:
  size_t size_;
  size_t capacity_;
  T* vector_;
 public:
  // Типы-члены.
  using ValueType = T;
  using Pointer = T*;
  using ConstPointer = const T*;
  using Reference = T&;
  using ConstReference = const T&;
  using SizeType = size_t;
  using Iterator = T*;
  using ConstIterator = const T*;
  using ReverseIterator = std::reverse_iterator<T>;
  using ConstReverseIterator = std::reverse_iterator<T>;

  // Конструкторы.
  Vector() {
    size_ = 0;
    capacity_ = 0;
    vector_ = nullptr;
  }

  explicit Vector(SizeType size) {
    size_ = size;
    capacity_ = size; 
    std::fill(vector_, vector_ + size_, T());
  }

  Vector(SizeType size, const T& value) {
    size_ = size;
    capacity_ = size; 
    std::fill(vector_, vector_ + size_, value);
  }

  template <class Iterator, class = std::enable_if_t<std::is_base_of_v<std::forward_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>>>
  Vector(Iterator first, Iterator last) {
    size_ = last - first;
    capacity_ = last - first;
    vector_ = new T[size_];
    std::copy(first, last, vector_);
  }

  Vector(std::initializer_list<T> initializer) {
    size_ = initializer.size();
    capacity_ = size_;
    vector_ = new T[size_];
    std::copy(initializer.begin(), initializer.end(), vector_);
  }

  // Правило пяти.
  Vector(const Vector& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    std::copy(other.vector_, other.vector_ + size_, vector_);
  }

  Vector& operator=(const Vector& other) {
    if (this != &other) {
      size_ = other.size_;
      capacity_ = other.capacity_;
      vector_ = other.vector_;
    }
    return *this;
  }

  Vector(Vector&& other) noexcept {
    size_ = other.size_;
    capacity_ = other.capacity_;
    vector_ = std::move(other.vector_);
    other.size_ = 0;
    other.capacity_ = 0;
  }

  Vector& operator=(Vector&& other) noexcept {
    if (this != &other) {
      size_ = other.size_;
      capacity_ = other.capacity_;
      vector_ = std::move(other.vector_);
      other.size_ = 0;
      other.capacity_ = 0;
    }
    return *this;
  }

  ~Vector() = default;

  // Методы.

  SizeType Size() {
    return size_;
  }

  const SizeType Size() const {
    return size_;
  }

  SizeType Capacity() {
    return capacity_;
  }

  const SizeType Capacity() const {
    return capacity_;
  }

  bool Empty() {
    return size_ == 0;
  }

  const bool Empty() const {
    return size_ == 0;
  }

  T& operator[](size_t i) {
    return vector_[i];
  }

  const T& operator[](size_t i) const {
    return vector_[i];
  }

  T& At(size_t i) {
    if (i >= size_) {
      throw std::out_of_range("error");
    }
    return vector_[i];
  }

  const T& At(size_t i) const {
    if (i >= size_) {
      throw std::out_of_range("error");
    }
    return vector_[i];
  }

  T& Front() {
    return vector_[0];
  }

  const T& Front() const {
    return vector_[0];
  }

  T& Back() {
    return vector_[size_ - 1];
  }

  const T& Back() const {
    return vector_[size_ - 1];
  }

  T* Data() {
    return vector_;
  }

  const T* Data() const {
    return vector_;
  }

  void Swap(Vector<T>& other) {
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(vector_, other.vector_);
  }

  template<typename = typename std::enable_if<std::is_integral<SizeType>::value>::type>
  void Resize(SizeType new_size) {
    for (SizeType i = new_size; i < size_; ++i) {
      vector_[i].~T();
    }
    size_ = new_size;
  }

  template<typename = typename std::enable_if<std::is_integral<SizeType>::value>::type>
  void Resize(SizeType new_size, const T& value) {
    if (new_size > size_) {
      Reserve(new_size);
      std::fill(vector_ + size_, vector_ + new_size, value);
    } else if (new_size < size_) {
        for (SizeType i = new_size; i < size_; ++i) {
          vector_[i].~T();
        }
    }
    size_ = new_size;
  }

  void Reserve(SizeType new_capacity) {
    if (new_capacity > capacity_) {
      T* new_vector = new T[new_capacity];
      std::copy(vector_, vector_+ size_, new_vector);
      vector_ = std::move(new_vector);
      capacity_ = new_capacity;
    }
  }

  void ShrinkToFit() {
    if (size_ < capacity_) {
      T* new_vector = new T[size_];
      std::copy(vector_, vector_ + size_, new_vector);
      vector_ = std::move(new_vector);
      capacity_ = size_;
    }
  }

  void Clear() {
    for (SizeType i = 0; i < size_; ++i) {
      vector_[i].~T();
    }
    size_ = 0;
  }

  void PushBack(const T& value) {
    if (size_ == capacity_) {
      Reserve(capacity_ == 0 ? 1 : 2 * capacity_);
    }
    vector_[size_] = value;
    ++size_;
  }

  void PopBack() {
    if (size_ > 0) {
      vector_[size_ - 1].~T();
      --size_;
    } else {
      throw std::out_of_range("error");
    }
  }

  // Операции.

  bool operator<(const Vector& other) const {
    return std::lexicographical_compare(vector_, vector_ + size_, other.vector_, other.vector_ + other.size_);
  }

  bool operator>(const Vector& other) const {
    return other < *this;
  }

  bool operator<=(const Vector& other) const {
    return !(*this > other);
  }

  bool operator>=(const Vector& other) const {
    return !(*this < other);
  }

  bool operator==(const Vector& other) const {
    return size_ == other.size_ && std::equal(vector_, vector_ + size_, other.vector_);
  }

  bool operator!=(const Vector& other) const {
    return !(*this = other);
  }

  T* begin() { // NOLINT
    return vector_;
  }

  const T* begin() const { // NOLINT
    return vector_;
  }

  T* end() { // NOLINT
    return vector_ + size_;
  }

  const T* end() const { // NOLINT
    return vector_ + size_;
  }

  T* rbegin() { // NOLINT
      ReverseIterator(end(vector_));
  }

  const T* rbegin() const { // NOLINT
      return ConstReverseIterator(end(vector_));
  }

  T* rend() { // NOLINT
      return ReverseIterator(begin(vector_));
  }

  const T* rend() const { // NOLINT
      return ConstReverseIterator(begin(vector_));
  }

  const T* cbegin() const { // NOLINT
      return begin();
  }

  const T* cend() const { // NOLINT
      return end();
  }

  const T* crbegin() const { // NOLINT
      return rbegin();
  }

  const T* crend() const { // NOLINT
      return rend();
  }

};

#endif