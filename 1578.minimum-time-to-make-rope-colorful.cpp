/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution {
public:
    int minCost(const std::string& colors, const vector<int>& neededTime) {
        const int size = colors.length();
        int i = 0, res = 0;

        while (i < size) {
            int j = i + 1, max = neededTime[i];

            while (j < size && colors[j] == colors[i]) {
                j++;
            }
            for (int k = i; k < j; k++) {
                res += neededTime[k];
                max = std::max(max, neededTime[k]);
            }
            res -= max;
            i = j;
        }
        return res;
    }
};
// @lc code=end
