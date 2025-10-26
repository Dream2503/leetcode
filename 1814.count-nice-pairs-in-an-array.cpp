/*
 * @lc app=leetcode id=1814 lang=cpp
 *
 * [1814] Count Nice Pairs in an Array
 */

// @lc code=start
class Solution {
public:
    int countNicePairs(const std::vector<int>& nums) {
        const int size = nums.size();
        int res = 0;
        std::vector reversed(size, 0);
        std::ranges::transform(nums, reversed.begin(), [](int num) -> int {
            int rev = 0;

            while (num) {
                rev = rev * 10 + num % 10;
                num /= 10;
            }
            return rev;
        });
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] + reversed[j] == nums[j] + reversed[i]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
