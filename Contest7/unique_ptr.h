#ifndef H_UNIQUE_PTR
#define H_UNIQUE_PTR

#include <iostream>

template <typename T>

class UniquePtr {
 private:
  T* ptr_;

 public:
  // Конструкторы и присваивания.

  UniquePtr() {
    ptr_ = nullptr;
  }

  explicit UniquePtr(T* ptr) {
    ptr_ = ptr;
  }

  UniquePtr(const UniquePtr& other) = delete;

  UniquePtr& operator=(const UniquePtr& other) = delete;

  UniquePtr(UniquePtr&& other) noexcept {
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
  }

  UniquePtr& operator=(UniquePtr&& other) noexcept {
    delete ptr_;
    ptr_ = other.ptr_;
    other.ptr_ = nullptr;
    return *this;
  }

  // Методы из задания.

  T* Release() {
    T* new_ptr = ptr_;
    ptr_ = nullptr;
    return new_ptr;
  }

  void Reset(T* ptr = nullptr) {
    delete ptr_;
    ptr_ = ptr;
  }

  void Swap(UniquePtr& other) {
    T* tmp = other.ptr_;
    other.ptr_ = ptr_;
    ptr_ = tmp;
  }

  T* Get() const {
    return ptr_;
  }

  T& operator*() const {
    return *ptr_;
  }

  T* operator->() const {
    return ptr_;
  }

  explicit operator bool() const {
    return ptr_ != nullptr;
  }

  // Деструктор.
  ~UniquePtr() {
    delete ptr_;
  }
};

#endif