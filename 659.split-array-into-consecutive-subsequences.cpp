/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
#include <ranges>

class Solution {
public:
    bool isPossible(const std::vector<int>& nums) {
        std::unordered_map<int, std::priority_queue<int, std::vector<int>, std::greater<int>>> seen;

        for (const int value : nums) {
            auto itr = seen.find(value - 1);

            if (itr == seen.end()) {
                seen[value].push(1);
            } else {
                seen[value].push(itr->second.top() + 1);
                itr->second.pop();

                if (!itr->second.size()) {
                    seen.erase(itr);
                }
            }
        }
        for (std::priority_queue<int, std::vector<int>, std::greater<int>>& heap : seen | std::views::values) {
            while (heap.size()) {
                if (heap.top() < 3) {
                    return false;
                }
                heap.pop();
            }
        }
        return true;
    }
};
// @lc code=end
