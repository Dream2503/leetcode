/*
 * @lc app=leetcode id=2917 lang=cpp
 *
 * [2917] Find the K-or of an Array
 */

// @lc code=start
class Solution {
public:
    int findKOr(const std::vector<int>& nums, const int k) {
        int res = 0;
        std::array<int, 31> hash{};

        for (int num : nums) {
            for (int i = 30; i >= 0 && num; i--) {
                hash[i] += num & 1;
                num /= 2;
            }
        }
        for (const int num : hash) {
            res = (res << 1) | num >= k;
        }
        return res;
    }
};
// @lc code=end
