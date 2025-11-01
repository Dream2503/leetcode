/*
 * @lc app=leetcode id=1588 lang=cpp
 *
 * [1588] Sum of All Odd Length Subarrays
 */

// @lc code=start
class Solution {
public:
    int sumOddLengthSubarrays(const std::vector<int>& arr) {
        const int size = arr.size();
        int res = 0;

        for (int i = 0; i < size; i++) {
            res += arr[i] * (((i + 1) * (size - i) + 1) / 2);
        }
        return res;
    }
};
// @lc code=end
