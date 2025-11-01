/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::ranges::sort(nums1);
        nums1.erase(std::ranges::unique(nums1).begin(), nums1.end());
        std::ranges::sort(nums2);
        nums2.erase(std::ranges::unique(nums2).begin(), nums2.end());
        std::vector<int> res;
        res.reserve(nums1.size() + nums2.size());
        std::ranges::set_intersection(nums1, nums2, std::back_inserter(res));
        return res;
    }
};
// @lc code=end
