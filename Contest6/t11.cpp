#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

// Структура Track для обработки песен.

struct Track {
 private:
  int id_;
  int score_;
  // Это поле обозначает, сколько раз трек был поставлен.
  int count_of_play_;

 public:
  int GetId() const {
    return id_;
  }

  int GetScore() const {
    return score_;
  }

  int CountOfPlay() const {
    return count_of_play_;
  }

  Track(int id, int score, int count_of_play) {
    id_ = id;
    score_ = score;
    count_of_play_ = count_of_play;
  }

  // Оператор сравнения для приоритетной очереди. Пришлось делать наоборот, чтобы грамотно обрабатывалось.
  bool operator>(const Track& other) const {
    if (GetScore() == other.GetScore()) {
      return GetId() > other.GetId();
    }
    return GetScore() < other.GetScore();
  }
};

int main() {
  // Для ускорения.
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // time_of_votes содержит время голоса каждого компьютера.
  std::unordered_map<std::string, int> time_of_votes;
  // score_of_tracks содержит очки каждой песни.
  std::map<int, int> score_of_tracks;
  // count_of_plays содержит, сколько раз была поставлена песня.
  std::unordered_map<int, int> count_of_plays;
  // Очередь треков.
  std::priority_queue<Track, std::vector<Track>, std::greater<Track>> queue_of_tracks;
  // Множество треков с 0 очков.
  std::set<int> zero_score_tracks;

  std::string command;
  std::string ip;

  int track_id = 0;
  int score = 0;
  int time = 0;
  // count_of_pos - счетчик песен с положительными очками.
  // Если таких нет, то надо выводить песню с 0 очков.
  int count_of_pos = 0;
  // Индекс нулевой песни, если не оглядываться назад.
  int ind_of_zero = 1;
  while (std::cin >> command) {
    if (command == "VOTE") {
      std::cin >> ip >> track_id >> score >> time;
      if (time - time_of_votes[ip] >= 600 || time_of_votes[ip] == 0) {
        time_of_votes[ip] = time;
        // Если знак числа очков изменился, то кол-во положительных элементов изменилось.
        if (score_of_tracks[track_id] <= 0 && score_of_tracks[track_id] + score > 0) {
          ++count_of_pos;
        } else if (score_of_tracks[track_id] > 0 && score_of_tracks[track_id] + score <= 0) {
          --count_of_pos;
        }
        score_of_tracks[track_id] += score;
        // Если очки равны 0, то закидываем в множество.
        if (score_of_tracks[track_id] == 0) {
          zero_score_tracks.insert(track_id);
        } else {
          zero_score_tracks.erase(track_id);
        }
        queue_of_tracks.emplace(track_id, score_of_tracks[track_id], count_of_plays[track_id]);
      }
      std::cout << score_of_tracks[track_id] << "\n";

    } else if (command == "GET") {
      if (!queue_of_tracks.empty() && count_of_pos > 0) {
        Track track = queue_of_tracks.top();
        int track_id = track.GetId();
        // Проверяем, что полученная песня с очереди - это конечный результат очков.
        // Ведь мы же закидываем туда и промежуточные результаты.
        while (track.CountOfPlay() != count_of_plays[track_id] || track.GetScore() != score_of_tracks[track_id]) {
          queue_of_tracks.pop();
          track = queue_of_tracks.top();
          track_id = track.GetId();
        }
        // Вывод и обнуление.
        std::cout << track_id << " " << score_of_tracks[track_id] << "\n";
        score_of_tracks[track_id] = -1;
        queue_of_tracks.pop();
        --count_of_pos;
        ++count_of_plays[track_id];
      } else {
        // Если нет положительных элементов, то надо выводить песню с 0 очками.
        // Ищем первый 0, к которому даже не обращались.
        while (score_of_tracks[ind_of_zero] != 0) {
          ++ind_of_zero;
        }
        int i = ind_of_zero;
        // И в множестве проверяем, есть ли 0, который был раньше.
        if (!zero_score_tracks.empty() && i > *zero_score_tracks.begin()) {
          i = *zero_score_tracks.begin();
        }
        // Вывод и обнуление.
        ++count_of_plays[i];
        score_of_tracks[i] = -1;
        zero_score_tracks.erase(i);
        std::cout << i << " 0\n";
      }

    } else {
      std::cout << "OK\n";
      break;
    }
  }
}