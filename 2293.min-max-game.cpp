/*
 * @lc app=leetcode id=2293 lang=cpp
 *
 * [2293] Min Max Game
 */

// @lc code=start
class Solution {
public:
    int minMaxGame(std::vector<int>& nums) {
        int size = nums.size();
        std::vector<int> next;
        next.reserve(size / 2);

        while (size > 1) {
            size /= 2;

            for (int i = 0; i < size; i++) {
                next.push_back(i % 2 == 0 ? std::min(nums[2 * i], nums[2 * i + 1]) : std::max(nums[2 * i], nums[2 * i + 1]));
            }
            nums.swap(next);
            next.clear();
        }
        return nums.front();
    }
};
// @lc code=end
