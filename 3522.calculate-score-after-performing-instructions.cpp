/*
 * @lc app=leetcode id=3522 lang=cpp
 *
 * [3522] Calculate Score After Performing Instructions
 */

// @lc code=start
class Solution {
public:
    long long calculateScore(const std::vector<std::string>& instructions, const std::vector<int>& values) {
        const int size = instructions.size();
        int64_t res = 0;
        int ip = 0;
        std::vector<uint8_t> seen(size, 0);

        while (ip >= 0 && ip < size && !seen[ip]) {
            seen[ip] = true;

            if (instructions[ip] == "add") {
                res += values[ip++];
            } else {
                ip += values[ip];
            }
        }
        return res;
    }
};
// @lc code=end
