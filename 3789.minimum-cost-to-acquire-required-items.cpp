/*
 * @lc app=leetcode id=3789 lang=cpp
 *
 * [3789] Minimum Cost to Acquire Required Items
 */

// @lc code=start
class Solution {
public:
    int64_t minimumCost(const int cost1, const int cost2, const int costBoth, const int need1, const int need2) {
        return std::min({cost1 * static_cast<int64_t>(need1) + cost2 * static_cast<int64_t>(need2),
                         cost1 * static_cast<int64_t>(std::max(0, need1 - need2)) + costBoth * static_cast<int64_t>(need2),
                         costBoth * static_cast<int64_t>(need1) + cost2 * static_cast<int64_t>(std::max(0, need2 - need1))});
    }
};
// @lc code=end
