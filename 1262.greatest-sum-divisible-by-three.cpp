/*
 * @lc app=leetcode id=1262 lang=cpp
 *
 * [1262] Greatest Sum Divisible by Three
 */

// @lc code=start
class Solution {
public:
    int maxSumDivThree(const std::vector<int>& nums) {
        int sum = 0;
        std::pair<int, int> mod1 = {INT32_MAX, INT32_MAX}, mod2 = {INT32_MAX, INT32_MAX};

        for (const int num : nums) {
            sum += num;

            if (num % 3 == 1) {
                if (num < mod1.first) {
                    mod1.second = mod1.first;
                    mod1.first = num;
                } else if (num < mod1.second) {
                    mod1.second = num;
                }
            } else if (num % 3 == 2) {
                if (num < mod2.first) {
                    mod2.second = mod2.first;
                    mod2.first = num;
                } else if (num < mod2.second) {
                    mod2.second = num;
                }
            }
        }
        if (sum % 3 == 1) {
            return std::max(mod1.first != INT32_MAX ? sum - mod1.first : 0, mod2.second != INT32_MAX ? sum - mod2.first - mod2.second : 0);
        }
        if (sum % 3 == 2) {
            return std::max(mod2.first != INT32_MAX ? sum - mod2.first : 0, mod1.second != INT32_MAX ? sum - mod1.first - mod1.second : 0);
        }
        return sum;
    }
};
// @lc code=end
