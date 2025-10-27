/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(const std::vector<int>& nums1, const std::vector<int>& nums2, const int k) {
        const int size1 = nums1.size(), size2 = nums2.size();
        std::priority_queue heap(
            [](const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) -> bool { return std::get<0>(a) > std::get<0>(b); },
            std::vector<std::tuple<int, int, int>>());

        for (int i = 0; i < size1 && i < k; i++) {
            heap.emplace(nums1[i] + nums2[0], i, 0);
        }
        std::vector<std::vector<int>> result;

        while (!heap.empty() && result.size() < k) {
            const auto [sum, i, j] = heap.top();
            heap.pop();
            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < size2) {
                heap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }
        return result;
    }
};
// @lc code=end
