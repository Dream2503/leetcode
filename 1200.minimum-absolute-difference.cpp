/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
        const int size = arr.size();
        int min = INT32_MAX;
        std::vector<std::vector<int>> res;
        std::sort(arr.begin(), arr.end());

        for (int i = 1; i < size; i++) {
            const int diff = std::abs(arr[i - 1] - arr[i]);

            if (diff < min) {
                min = diff;
                res.clear();
            }
            if (diff == min) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;
    }
};
// @lc code=end
