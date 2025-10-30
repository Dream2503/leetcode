/*
 * @lc app=leetcode id=1526 lang=cpp
 *
 * [1526] Minimum Number of Increments on Subarrays to Form a Target Array
 */

// @lc code=start
class Solution {
public:
    int minNumberOperations(const std::vector<int>& target) {
        const int size = target.size();
        int res = target[0];

        for (int i = 1; i < size; i++) {
            if (target[i] > target[i - 1]) {
                res += target[i] - target[i - 1];
            }
        }
        return res;
    }
};
// @lc code=end
