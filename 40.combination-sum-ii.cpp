/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
    void combination(const std::vector<int>& candidates, const int idx, const int target, std::vector<int>& current,
                     std::vector<std::vector<int>>& res) {
        if (idx == candidates.size()) {
            if (target == 0) {
                res.push_back(current);
            }
            return;
        }
        if (target >= candidates[idx]) {
            current.push_back(candidates[idx]);
            combination(candidates, idx + 1, target - current.back(), current, res);
            current.pop_back();
        }
        int next = idx + 1;

        while (next < candidates.size() && candidates[next] == candidates[idx]) {
            next++;
        }
        combination(candidates, next, target, current, res);
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, const int target) {
        std::vector<std::vector<int>> res;
        std::vector<int> current;
        std::ranges::sort(candidates);
        combination(candidates, 0, target, current, res);
        return res;
    }
};
// @lc code=end
