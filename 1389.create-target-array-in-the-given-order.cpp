/*
 * @lc app=leetcode id=1389 lang=cpp
 *
 * [1389] Create Target Array in the Given Order
 */

// @lc code=start
class Solution {
public:
    std::vector<int> createTargetArray(const std::vector<int>& nums, const std::vector<int>& index) {
        const int size = index.size();
        std::vector<int> res;
        res.reserve(size);

        for (int i = 0; i < size; i++) {
            res.insert(res.begin() + index[i], nums[i]);
        }
        return res;
    }
};
// @lc code=end
