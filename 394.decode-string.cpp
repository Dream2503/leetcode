/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
    int i = 0;

public:
    std::string decodeString(const std::string& s) {
        const int size = s.length();
        int times = 0;
        std::string res;

        while (i < size) {
            if (std::isdigit(s[i])) {
                times = times * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                i++;
                std::string temp = decodeString(s);
                res.reserve(res.size() + temp.size() * times);

                for (int j = 0; j < times; j++) {
                    res.append(temp);
                }
                times = 0;
            } else if (s[i] == ']') {
                return res;
            } else {
                res.push_back(s[i]);
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
