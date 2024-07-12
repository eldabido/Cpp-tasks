#ifndef H_UNORDERED_SET
#define H_UNORDERED_SET

#include <iostream>
#include <functional>
#include <list>
#include <vector>

template <typename KeyT>
class UnorderedSet {
 private:
  std::vector<std::list<KeyT>> buckets_;
  size_t n_elements_;

 public:
  UnorderedSet() : buckets_(0), n_elements_(0) {
  }

  explicit UnorderedSet(size_t count) : buckets_(count), n_elements_(0) {
  }

  template <typename ForwardIt>
  UnorderedSet(ForwardIt first, ForwardIt last) : n_elements_(0) {
    size_t count = std::distance(first, last);
    buckets_.resize(count);
    for (auto it = first; it != last; ++it) {
      Insert(*it);
    }
  }

  UnorderedSet(const UnorderedSet& other) {
    buckets_ = other.buckets_;
    n_elements_ = other.n_elements_;
  }

  UnorderedSet& operator=(const UnorderedSet& other) {
    buckets_ = other.buckets_;
    n_elements_ = other.n_elements_;
    return *this;
  }

  UnorderedSet(UnorderedSet&& other) {
    buckets_ = other.buckets_;
    n_elements_ = other.n_elements_;
    other.buckets_.clear();
    other.n_elements_ = 0;
  }

  UnorderedSet& operator=(UnorderedSet&& other) {
    buckets_ = other.buckets_;
    n_elements_ = other.n_elements_;
    other.buckets_.clear();
    other.n_elements_ = 0;
    return *this;
  }

  ~UnorderedSet() {
    buckets_.clear();
  }

  size_t Size() const {
    return n_elements_;
  }

  bool Empty() const {
    return n_elements_ == 0;
  }

  void Clear() {
    buckets_.clear();
    buckets_.resize(0);
    n_elements_ = 0;
  }

  void Insert(const KeyT& key) {
    if (!buckets_.empty()) {
      size_t index = std::hash<KeyT>{}(key) % buckets_.size();
      auto& bucket = buckets_[index];
      if (std::find(bucket.begin(), bucket.end(), key) == bucket.end()) {
        bucket.push_back(key);
        ++n_elements_;
        if (n_elements_ > buckets_.size()) {
          Rehash(buckets_.size() * 2);
        }
      }
    } else {
      Rehash(1);
      buckets_[0].push_back(key);
      ++n_elements_;
      if (n_elements_ > buckets_.size()) {
        Rehash(buckets_.size() * 2);
      }
    }
  }

  void Insert(KeyT&& key) {
    if (!buckets_.empty()) {
      size_t index = std::hash<KeyT>{}(key) % buckets_.size();
      auto& bucket = buckets_[index];
      if (std::find(bucket.begin(), bucket.end(), key) == bucket.end()) {
        bucket.push_back(key);
        ++n_elements_;
        if (n_elements_ > buckets_.size()) {
          Rehash(buckets_.size() * 2);
        }
      }
    } else {
      Rehash(1);
      buckets_[0].push_back(key);
      ++n_elements_;
      if (n_elements_ > buckets_.size()) {
        Rehash(buckets_.size() * 2);
      }
    }
  }

  void Erase(const KeyT& key) {
    size_t index = 0;
    if (!buckets_.empty()) {
      index = std::hash<KeyT>{}(key) % buckets_.size();
    } else {
      index = 0;
    }
    auto& bucket = buckets_[index];
    auto it = std::find(bucket.begin(), bucket.end(), key);
    if (it != bucket.end()) {
      bucket.erase(it);
      --n_elements_;
    }
  }

  bool Find(const KeyT& key) const {
    if (buckets_.empty()) {
      return !buckets_.empty();
    }
    size_t index = std::hash<KeyT>{}(key) % buckets_.size();
    const auto& bucket = buckets_[index];
    return std::find(bucket.begin(), bucket.end(), key) != bucket.end();
  }

  void Rehash(size_t new_bucket_count) {
    if (new_bucket_count == buckets_.size() || new_bucket_count < n_elements_) {
      return;
    }
    std::vector<std::list<KeyT>> new_buckets(new_bucket_count);
    for (auto bucket : buckets_) {
      for (auto key : bucket) {
        size_t index = 0;
        if (!buckets_.empty()) {
          index = std::hash<KeyT>{}(key) % new_buckets.size();
        }
        new_buckets[index].push_back(key);
      }
    }
    buckets_ = new_buckets;
    new_buckets.clear();
  }

  void Reserve(size_t new_bucket_count) {
    if (new_bucket_count > buckets_.size()) {
      std::vector<std::list<KeyT>> new_buckets(new_bucket_count);
      for (auto& bucket : buckets_) {
        for (auto& key : bucket) {
          size_t index = 0;
          if (!buckets_.empty()) {
            index = std::hash<KeyT>{}(key) % new_buckets.size();
          }
          new_buckets[index].push_back(key);
        }
      }
      buckets_ = new_buckets;
      new_buckets.clear();
    }
  }

  size_t BucketCount() const {
    return buckets_.size();
  }

  size_t BucketSize(size_t id) const {
    if (id < buckets_.size()) {
      return buckets_[id].size();
    }
    return 0;
  }

  size_t Bucket(const KeyT& key) const {
    size_t index = 0;
    if (!buckets_.empty()) {
      index = std::hash<KeyT>{}(key) % buckets_.size();
    }
    return index;
  }

  double LoadFactor() const {
    if (!buckets_.empty()) {
      return static_cast<double>(n_elements_) / static_cast<double>(buckets_.size());
    }
    return 0;
  }
};

#endif