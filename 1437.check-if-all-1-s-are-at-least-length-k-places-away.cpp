/*
 * @lc app=leetcode id=1437 lang=cpp
 *
 * [1437] Check If All 1's Are at Least Length K Places Away
 */

// @lc code=start
class Solution {
public:
    bool kLengthApart(const std::vector<int>& nums, const int k) {
        auto last = std::ranges::find(nums, 1);

        while (last != nums.end()) {
            auto next = std::find(last + 1, nums.end(), 1);

            if (next != nums.end() && next - last <= k) {
                return false;
            }
            last = next;
        }
        return true;
    }
};
// @lc code=end
