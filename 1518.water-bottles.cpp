/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

// @lc code=start
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0, remaining = 0;

        while (numBottles) {
            res += numBottles;
            numBottles += remaining;
            remaining = numBottles % numExchange;
            numBottles /= numExchange;
        }
        return res;
    }
};
// @lc code=end
