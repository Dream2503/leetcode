/*
 * @lc app=leetcode id=1640 lang=cpp
 *
 * [1640] Check Array Formation Through Concatenation
 */

// @lc code=start
class Solution {
public:
    bool canFormArray(const std::vector<int>& arr, const std::vector<std::vector<int>>& pieces) {
        const int size = arr.size();
        std::unordered_map<int, int> hash;

        for (int i = 0; i < size; i++) {
            hash[arr[i]] = i;
        }
        for (const std::vector<int>& piece : pieces) {
            if (!hash.contains(piece[0])) {
                return false;
            }
            const int piece_size = piece.size();
            int prev = hash[piece[0]];

            for (int i = 1; i < piece_size; i++) {
                if (!hash.contains(piece[i]) || hash[piece[i]] != prev + 1) {
                    return false;
                }
                prev++;
            }
        }
        return true;
    }
};
// @lc code=end
