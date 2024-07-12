#ifndef H_SHARED_PTR
#define H_SHARED_PTR

#include <iostream>
#include <utility>

template <typename T>
class SharedPtr {
 private:
  T* ptr_;
  int* strong_counter_;

 public:

  SharedPtr() {
    ptr_ = nullptr;
    strong_counter_ = new int(1);
  }

  explicit SharedPtr(T* p) {
    ptr_ = p;
    strong_counter_ = new int(1);
  }

  // Конструктор копирования
  SharedPtr(const SharedPtr& other) {
    ptr_ = other.ptr_;
    strong_counter_ = other.strong_counter_;
    if (strong_counter_ != nullptr) {
      ++(*strong_counter_);
    } else {
      strong_counter_ = new int(1);
    }
  }

  SharedPtr& operator=(const SharedPtr& other) {
    if (this != &other) {
      if (strong_counter_ != nullptr) {
        --(*strong_counter_);
        if (*strong_counter_ == 0) {
          delete ptr_;
          delete strong_counter_;
        }
      }
      strong_counter_ = other.strong_counter_;
      ptr_ = other.ptr_;
      if (strong_counter_ != nullptr) {
        ++(*strong_counter_);
      } else {
        strong_counter_ = new int(1);
      }
    }
    return *this;
  }
  // Конструктор перемещения
  SharedPtr(SharedPtr&& other) noexcept {
    ptr_ = other.ptr_;
    strong_counter_ = other.strong_counter_;
    other.ptr_ = nullptr;
    other.strong_counter_ = nullptr;
  }

  SharedPtr& operator=(SharedPtr&& other) noexcept {
    if (strong_counter_ != nullptr) {
      --(*strong_counter_);
      if (*strong_counter_ == 0) {
        delete strong_counter_;
        delete ptr_;
      }
    }
    strong_counter_ = other.strong_counter_;
    ptr_ = other.ptr_;
    other.strong_counter_ = nullptr;
    other.ptr_ = nullptr;
    return *this;
  }

  ~SharedPtr() {
    if ((strong_counter_ != nullptr)) {
      --(*strong_counter_);
      if (*strong_counter_ == 0) {
        delete ptr_;
        delete strong_counter_;
      }
    }
    strong_counter_ = nullptr;
    ptr_ = nullptr;
  }

  // Метод Reset
  void Reset(T* p = nullptr) {
    if (ptr_ != p) {
      if ((strong_counter_ != nullptr)) {
        --(*strong_counter_);
        if (*strong_counter_ == 0) {
          delete ptr_;
          delete strong_counter_;
        }
      }
      ptr_ = p;
      strong_counter_ = new int(1);
    }
  }
  // Метод Swap
  void Swap(SharedPtr& other) {
    std::swap(ptr_, other.ptr_);
    std::swap(strong_counter_, other.strong_counter_);
  }

  // Метод Get
  T* Get() const {
    return ptr_;
  }

  // Метод UseCount
  int UseCount() const {
    if (ptr_ == nullptr) {
      return 0;
    }
    return *strong_counter_;
  }

  // Оператор разыменовывания
  T& operator*() const {
    return *ptr_;
  }

  // Оператор "стрелочка"
  T* operator->() const {
    return ptr_;
  }

  // Явный оператор приведения к bool
  explicit operator bool() const {
    return ptr_ != nullptr;
  }
};
#endif