/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
class Solution {
    struct TrieNode {
        std::array<TrieNode*, 2> child = {nullptr, nullptr};
    };

public:
    int findMaximumXOR(const std::vector<int>& nums) {
        int res = 0;
        const auto root = new TrieNode();

        for (const int num : nums) {
            TrieNode* node = root;

            for (int i = 31; i >= 0; i--) {
                int b = num >> i & 1;

                if (!node->child[b]) {
                    node->child[b] = new TrieNode();
                }
                node = node->child[b];
            }
        }
        for (const int num : nums) {
            int max = 0;
            TrieNode* node = root;

            for (int i = 31; i >= 0; --i) {
                int bit = num >> i & 1;

                if (node->child[!bit]) {
                    max |= 1 << i;
                    node = node->child[!bit];
                } else {
                    node = node->child[bit];
                }
            }
            res = std::max(res, max);
        }
        return res;
    }
};
// @lc code=end
