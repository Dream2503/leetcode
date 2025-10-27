/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution {
public:
    std::vector<bool> kidsWithCandies(const std::vector<int>& candies, const int extraCandies) {
        const int max = *std::ranges::max_element(candies), size = candies.size();
        std::vector<bool> res;
        res.reserve(size);

        for (int i = 0; i < size; i++) {
            res.push_back(candies[i] + extraCandies >= max);
        }
        return res;
    }
};
// @lc code=end
