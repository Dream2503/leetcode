/*
 * @lc app=leetcode id=3867 lang=cpp
 *
 * [3867] Sum of GCD of Formed Pairs
 */

// @lc code=start
class Solution {
public:
    long long gcdSum(const std::vector<int>& nums) {
        const int size = nums.size();
        int max = nums.front();
        uint64_t res = 0;
        std::vector<int> prefix_gcd;
        prefix_gcd.reserve(size);

        for (const int element : nums) {
            prefix_gcd.push_back(std::gcd(max = std::max(max, element), element));
        }
        std::ranges::sort(prefix_gcd);

        for (int i = 0, j = size - 1; i < j; i++, j--) {
            res += std::gcd(prefix_gcd[i], prefix_gcd[j]) ;
        }
        return res;
    }
};
// @lc code=end

