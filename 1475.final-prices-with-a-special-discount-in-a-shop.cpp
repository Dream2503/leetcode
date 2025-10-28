/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& finalPrices(std::vector<int>& prices) {
        const int size = prices.size();

        for (int i = 0; i < size - 1; i++) {
            int j = i + 1;

            while (j < size && prices[j] > prices[i]) {
                j++;
            }
            if (j < size) {
                prices[i] -= prices[j];
            }
        }
        return prices;
    }
};
// @lc code=end
