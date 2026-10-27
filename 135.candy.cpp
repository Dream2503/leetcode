/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    int candy(const std::vector<int>& ratings) {
        const int size = ratings.size();
        std::vector res(size, 1);

        for (int i = 0; i < size; i++) {
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                res[i] = res[i - 1] + 1;
            }
        }
        for (int i = size - 1; i >= 0; i--) {
            if (i < size - 1 && ratings[i] > ratings[i + 1]) {
                res[i] = std::max(res[i], res[i + 1] + 1);
            }
        }
        return std::ranges::fold_left(res, 0, std::plus());
    }
};
// @lc code=end
