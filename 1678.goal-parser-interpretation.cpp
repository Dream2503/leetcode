/*
 * @lc app=leetcode id=1678 lang=cpp
 *
 * [1678] Goal Parser Interpretation
 */

// @lc code=start
class Solution {
public:
    std::string interpret(const std::string& command) {
        const int size = command.size();
        std::string res;

        for (int i = 0; i < size; i++) {
            if (command[i] == 'G') {
                res.push_back('G');
            } else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    res.push_back('o');
                    i++;
                } else {
                    res.append("al");
                    i += 3;
                }
            }
        }
        return res;
    }
};
// @lc code=end
