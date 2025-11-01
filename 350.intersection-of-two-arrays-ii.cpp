/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::ranges::sort(nums1);
        std::ranges::sort(nums2);
        std::vector<int> res;
        res.reserve(nums1.size() + nums2.size());
        std::ranges::set_intersection(nums1, nums2, std::back_inserter(res));
        return res;
    }
};
// @lc code=end
