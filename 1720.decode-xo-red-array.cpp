
/*
 * @lc app=leetcode id=1720 lang=cpp
 *
 * [1720] Decode XORed Array
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& decode(std::vector<int>& encoded, const int first) {
        const int size = encoded.size() + 1;
        encoded.insert(encoded.begin(), first);

        for (int i = 1; i < size; i++) {
            encoded[i] ^= encoded[i - 1];
        }
        return encoded;
    }
};
// @lc code=end
