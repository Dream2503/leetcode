/*
 * @lc app=leetcode id=2960 lang=cpp
 *
 * [2960] Count Tested Devices After Test Operations
 */

// @lc code=start
class Solution {
public:
    int countTestedDevices(const std::vector<int>& batteryPercentages) {
        int res = 0;

        for (const int battery_percentage : batteryPercentages) {
            if (battery_percentage - res > 0) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
