/*
 * @lc app=leetcode id=2032 lang=cpp
 *
 * [2032] Two Out of Three
 */

// @lc code=start
class Solution {
public:
    std::vector<int> twoOutOfThree(const std::vector<int>& nums1, const std::vector<int>& nums2, const std::vector<int>& nums3) {
        std::unordered_set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end()), set3(nums3.begin(), nums3.end()), res;

        for (const int num : set1) {
            if (set2.contains(num) || set3.contains(num)) {
                res.insert(num);
            }
        }
        for (const int num : set2) {
            if (set3.contains(num) || set1.contains(num)) {
                res.insert(num);
            }
        }
        for (const int num : set3) {
            if (set1.contains(num) || set2.contains(num)) {
                res.insert(num);
            }
        }
        return std::vector(res.begin(), res.end());
    }
};
// @lc code=end
