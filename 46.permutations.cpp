/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        res.push_back(nums);

        while (true) {
            std::ranges::next_permutation(nums);

            if (res.front() == nums) {
                break;
            }
            res.push_back(nums);
        }
        return res;
    }
};
// @lc code=end
