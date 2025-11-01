/*
 * @lc app=leetcode id=1619 lang=cpp
 *
 * [1619] Mean of Array After Removing Some Elements
 */

// @lc code=start
class Solution {
public:
    double trimMean(std::vector<int>& arr) {
        const int size = arr.size();
        std::ranges::sort(arr);
        const auto left = arr.begin() + .05 * size, right = arr.end() - .05 * size;
        return std::reduce(left, right, 0) / static_cast<double>(right - left);
    }
};
// @lc code=end
