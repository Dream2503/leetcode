/*
 * @lc app=leetcode id=3304 lang=cpp
 *
 * [3304] Find the K-th Character in String Game I
 */

// @lc code=start
class Solution {
public:
    char kthCharacter(const int k) {
        std::string word = "a";

        while (word.size() < k) {
            std::string temp = word;

            for (char& ch : temp) {
                if (ch == 'z') {
                    ch = 'a';
                } else {
                    ch++;
                }
            }
            word.append(std::move(temp));
        }
        return word[k - 1];
    }
};
// @lc code=end
