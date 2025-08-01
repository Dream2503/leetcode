/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
 */

// @lc code=start
class Solution {
public:
    int minCostToMoveChips(const std::vector<int>& position) {
        int odd = 0, even = 0;

        for (const int element : position) {
            if (element % 2) {
                odd++;
            } else {
                even++;
            }
        }
        return std::min(even, odd);
    }
};
// @lc code=end

