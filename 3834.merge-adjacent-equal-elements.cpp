/*
 * @lc app=leetcode id=3834 lang=cpp
 *
 * [3834] Merge Adjacent Equal Elements
 */

// @lc code=start
class Solution {
public:
    std::vector<long long> mergeAdjacent(const std::vector<int>& nums) {
        std::vector<long long> res;
        res.push_back(nums.front());

        for (const int num : nums | std::views::drop(1)) {
            res.push_back(num);

            while (res.size() > 1 && res.back() == *(res.end() - 2)) {
                res.pop_back();
                res.back() *= 2;
            }
        }
        return res;
    }
};
// @lc code=end
