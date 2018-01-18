
#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::map;

class Solution {
private:
  vector<int> temp_results;
  vector<vector<int>> results;
public:
  vector<int> removeBiggerThanTarget(vector<int> &candidates, int target) {
    vector<int> ret;
    for (auto &ii : candidates) {
      if (ii <= target) {
        ret.push_back(ii);
      }
    }
    return ret;
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    auto real_candidates = this->removeBiggerThanTarget(candidates, target);
    this->temp_results.clear();
    this->results.clear();
    combinationSumCore(real_candidates, target, 0);
    return this->results;
  }
  void combinationSumCore(vector<int>& candidates, int target, int index) {
    for (int i = index; i < candidates.size(); i++) {
      if (candidates[i] == target) {
        cout << "match target " << target << endl;
        vector<int> result;
        for (int j = 0; j <= i; j++) {
          result.push_back(candidates[j]);
        }
        this->results.push_back(result);
      } else if (candidates[i] > target) {
        break;
      } else if (candidates[i] < target) {
        combinationSumCore(candidates, target - candidates[i], i + 1);
      }
    }
  }
};

int main() {
  auto solution = Solution();
  vector<int> vec = {10, 1, 2, 7, 6, 1, 5};
  auto ret = solution.combinationSum2(vec, 8);

  for (auto &ii : ret) {
    for (auto &jj : ii) {
      cout << jj << ' ';
    }
    cout << endl;
  }

}