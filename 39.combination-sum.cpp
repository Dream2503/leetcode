/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
    void combination(const std::vector<int>& candidates, const int idx, const int target, std::vector<int>& current,
                     std::vector<std::vector<int>>& res) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            res.push_back(current);
            return;
        }
        if (target >= candidates[idx]) {
            current.push_back(candidates[idx]);
            combination(candidates, idx, target - current.back(), current, res);
            current.pop_back();
        }
        combination(candidates, idx + 1, target, current, res);
    }

public:
    std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, const int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> current;
        combination(candidates, 0, target, current, res);
        return res;
    }
};
// @lc code=end
