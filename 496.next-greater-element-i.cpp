/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& nextGreaterElement(std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::unordered_map<int, int> hash;
        hash.reserve(nums2.size());
        std::stack<int> stack;

        for (const int num : nums2) {
            while (!stack.empty() && num > stack.top()) {
                hash[stack.top()] = num;
                stack.pop();
            }
            stack.push(num);
        }
        while (!stack.empty()) {
            hash[stack.top()] = -1;
            stack.pop();
        }
        for (int& num : nums1) {
            num = hash[num];
        }
        return nums1;
    }
};
// @lc code=end
