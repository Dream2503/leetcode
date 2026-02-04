/*
 * @lc app=leetcode id=1725 lang=cpp
 *
 * [1725] Number Of Rectangles That Can Form The Largest Square
 */

// @lc code=start
class Solution {
public:
    int countGoodRectangles(const std::vector<std::vector<int>>& rectangles) {
        int res = 0, max = 0;

        for (const std::vector<int>& rectangle : rectangles) {
            max = std::max(max, std::min(rectangle[0], rectangle[1]));
        }
        for (const std::vector<int>& rectangle : rectangles) {
            res += max == std::min(rectangle[0], rectangle[1]);
        }
        return res;
    }
};
// @lc code=end
