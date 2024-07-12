#ifndef H_RANGE
#define H_RANGE
#define REVERSE_RANGE_IMPLEMENTED 
#include <iostream>

class Iterator {
 private:
  int cur_;
  int step_;
  int end_;

 public:
  Iterator(int cur, int step, int end):  cur_(cur), step_(step), end_(end) {}

  bool operator!=(const Iterator& other) const {
    if (step_ < 0) {
      return cur_ != other.cur_ && cur_ >= end_;
    }
    return cur_ != other.cur_ && cur_ <= end_;
  }

  int operator*() const {
  return cur_;
  }

  Iterator& operator++() {
  cur_ += step_;
  return *this;
}
};

class Range {
 private:
  int beginning_;
  int ending_;
  int step_;

 public:
  explicit Range(int ending): beginning_(0), ending_(ending), step_(1) {
    if (ending_ < 0) {
      ending_ = 0;
    }
  };

  Range(int beginning, int ending) : beginning_(beginning), ending_(ending), step_(1) {
    if (beginning_ > ending_) {
      ending_ = beginning_;
    }
  }

  Range(int beginning, int ending, int step) : beginning_(beginning), ending_(ending), step_(step) {
    if ((beginning_ > ending_ && step >= 0) || (ending_ > beginning && step_ < 0) || (step == 0)) {
      ending_ = beginning_;
    }
  }

  const Iterator begin() const { //NOLINT
    return { beginning_, step_, ending_ };
  }

  const Iterator end() const { //NOLINT
    return { ending_, step_, beginning_ };
  }
  Iterator begin() { //NOLINT
    return { beginning_, step_, ending_ };
  }

  Iterator end() { //NOLINT
   return { ending_, step_, beginning_ };
  }

  Iterator rbegin() const { //NOLINT
    if (step_ != 0 && (ending_ - beginning_) % step_ == 0) {
      return { ending_ - step_, -step_, beginning_ - step_};
    }
    if (step_ != 0 && (ending_ - beginning_) % step_ != 0) {
      return { beginning_ + (ending_ - beginning_ + step_ - 1) / step_ * step_ - step_, -step_, beginning_ };
    }
    if (step_ == 0) {
      return {ending_, -step_, ending_};
    }
    return { ending_ - step_, -step_, beginning_ - step_ };
  }

  Iterator rend() const { //NOLINT
    return { beginning_ - step_, -step_, ending_ - step_ };
  }
};

#endif