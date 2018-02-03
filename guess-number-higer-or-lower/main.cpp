// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

int answer;

int guess(int num) {
  
  if (num > answer) {
    return -1;
  } else if (num < answer) {
    return 1;
  } else {
    return 0;
  }
}

class Solution {
public:
    int guessNumber(int n) {
      return guessNumberCoreNonRecursive(n);
    }
    int guessNumberCore(int from, int to) {
      if (from == to) {
        return from;
      }
      int middle = (to - from) / 2 + from;
      int guess_middle = guess(middle);
      if (guess_middle == -1) {
        return guessNumberCore(from, middle - 1);
      } else if (guess_middle == 1) {
        return guessNumberCore(middle + 1, to);
      } else {
        return middle;
      }
    }
    int guessNumberCoreNonRecursive(int n) {
      int from = 1;
      int to = n;
      while (true) {
        int middle = (to - from) / 2 + from;
        int guess_middle = guess(middle);
        if (guess_middle == 0) {
          return middle;
        } else if (guess_middle == -1) {
          to = middle - 1;
        } else {
          // static_assert(guess_middle == 1);
          from = middle + 1;
        }
      }
    }
};

#include <iostream>

using std::cout;
using std::endl;

int main() {
  Solution x = Solution();
  for (int i = 1; i < 100; i++) {
    for (int j = 1; j <= i; j++) {
      answer = j;
      cout << x.guessNumber(i) << endl;
    }
  }
}