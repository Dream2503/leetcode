/*
 * @lc app=leetcode id=1995 lang=cpp
 *
 * [1995] Count Special Quadruplets
 */

// @lc code=start
class Solution {
public:
    int countQuadruplets(const std::vector<int>& nums) {
        const int size = nums.size();
        int res = 0;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                for (int k = j + 1; k < size; k++) {
                    for (int l = k + 1; l < size; l++) {
                        res += nums[i] + nums[j] + nums[k] == nums[l];
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
