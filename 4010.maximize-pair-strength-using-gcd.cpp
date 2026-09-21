/*
 * @lc app=leetcode id=4010 lang=cpp
 *
 * [4010] Maximize Pair Strength Using GCD
 */

// @lc code=start
class Solution {
public:
    long long maxPairStrength(const std::vector<int>& nums) {
        const int size = nums.size();
        uint64_t res = 0;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                res = std::max(res, static_cast<uint64_t>(nums[i]) * nums[j] / static_cast<uint64_t>(std::pow(std::gcd(nums[i], nums[j]), 2)));
            }
        }
        return res;
    }
};
// @lc code=end
