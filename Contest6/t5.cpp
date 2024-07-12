#include <algorithm>
#include <iostream>
#include <vector>

class Team {
 private:
  int tasks_;
  int number_;
  int time_;

 public:
  explicit Team(int t = 0, int tim = 0, int n = 0) {
    tasks_ = t;
    time_ = tim;
    number_ = n;
  }

  int GetNum() {
    return number_;
  }

  bool operator<(const Team& sec) const {
    if (tasks_ != sec.tasks_) {
      return tasks_ < sec.tasks_;
    }
    if (time_ != sec.time_) {
      return time_ > sec.time_;
    }
    return number_ > sec.number_;
  }
};

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<Team> teams(n);
  int tasks = 0;
  int time = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> tasks >> time;
    teams[i] = Team(tasks, time, i + 1);
  }
  std::sort(teams.begin(), teams.end());
  for (int i = 0; i < n; ++i) {
    std::cout << teams[n - i - 1].GetNum() << "\n";
  }
}