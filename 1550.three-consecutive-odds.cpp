/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 */

// @lc code=start
class Solution {
public:
    bool threeConsecutiveOdds(const std::vector<int>& arr) {
        const int size = arr.size();

        for (int i = 0; i < size - 2; i++) {
            if (arr[i] % 2 && arr[i + 1] % 2 && arr[i + 2] % 2) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
