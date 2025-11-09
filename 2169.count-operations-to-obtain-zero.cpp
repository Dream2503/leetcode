/*
 * @lc app=leetcode id=2169 lang=cpp
 *
 * [2169] Count Operations to Obtain Zero
 */

// @lc code=start
class Solution {
public:
    int countOperations(int num1, int num2) {
        int res = 0;

        while (num1 && num2) {
            (num1 > num2 ? num1 : num2) -= std::min(num1, num2);
            res++;
        }
        return res;
    }
};
// @lc code=end
