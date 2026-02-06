/*
 * @lc app=leetcode id=1863 lang=cpp
 *
 * [1863] Sum of All Subset XOR Totals
 */

// @lc code=start
class Solution {
public:
    int subsetXORSum(const std::vector<int>& nums) {
        const int size = nums.size();
        int res = 0;

        for (int i = 0; i < 1 << size; i++) {
            int temp = 0, j = 0;

            for (int idx = i; idx != 0; idx >>= 1, j++) {
                if (idx & 1) {
                    temp ^= nums[j];
                }
            }
            res += temp;
        }
        return res;
    }
};
// @lc code=end
