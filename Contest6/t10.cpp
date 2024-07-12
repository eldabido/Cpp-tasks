#include <iostream>
#include <queue>
#include <unordered_map>

class Cache {
 private:
  std::unordered_map<int, int> caches_;
  std::queue<int> id_;
  size_t m_;
  int unique_ = 0;

 public:
  explicit Cache(size_t m) {
    m_ = m;
  }

  int GetUser(int user_id) {
    if (caches_.find(user_id) != caches_.end() && caches_[user_id] != 0) {
      ++caches_[user_id];
      id_.push(user_id);
      return 0;
    }
    if (unique_ >= m_) {
      while (!id_.empty()) {
        int last = id_.front();
        --caches_[last];
        id_.pop();
        if (caches_[last] == 0) {
          break;
        }
      }
      --unique_;
    }
    caches_[user_id] = 1;
    id_.push(user_id);
    ++unique_;
    return 1;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  size_t m = 0;
  std::cin >> m;
  Cache cache = Cache(m);
  int user_id = 0;
  while (std::cin >> user_id) {
    std::cout << cache.GetUser(user_id) << " ";
  };
  return 0;
}