/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(const std::vector<int>& nums, const int indexDiff, const int valueDiff) {
        const int size = nums.size();
        int i = 0, j = indexDiff;
        std::multiset window(nums.begin(), nums.begin() + std::min(size, indexDiff));

        for (auto itr = window.begin(); itr != window.end(); ++itr) {
            auto next = std::next(itr);

            if (next == window.end()) {
                break;
            }
            if (*next - *itr <= valueDiff) {
                return true;
            }
        }
        while (j <= size) {
            if (j < size) {
                auto itr = window.insert(nums[j]);

                if (itr != window.begin() && *itr - *std::prev(itr) <= valueDiff ||
                    itr != std::prev(window.end()) && *std::next(itr) - *itr <= valueDiff) {
                    return true;
                }
            }
            j++;
            window.erase(window.find(nums[i++]));
        }
        return false;
    }
};
// @lc code=end
