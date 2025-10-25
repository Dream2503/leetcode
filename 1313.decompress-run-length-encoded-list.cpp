/*
 * @lc app=leetcode id=1313 lang=cpp
 *
 * [1313] Decompress Run-Length Encoded List
 */

// @lc code=start
class Solution {
public:
    std::vector<int> decompressRLElist(const std::vector<int>& nums) {
        const int size = nums.size();
        int res_size = 0, k = 0;

        for (int i = 0; i < size; i += 2) {
            res_size += nums[i];
        }
        std::vector<int> res(res_size);

        for (int i = 0; i < size; i += 2) {
            for (int j = 0; j < nums[i]; j++) {
                res[k++] = nums[i + 1];
            }
        }
        return res;
    }
};
// @lc code=end
