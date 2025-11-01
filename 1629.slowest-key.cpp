/*
 * @lc app=leetcode id=1629 lang=cpp
 *
 * [1629] Slowest Key
 */

// @lc code=start
class Solution {
public:
    char slowestKey(const std::vector<int>& releaseTimes, const std::string& keysPressed) {
        const int size = releaseTimes.size();
        int prev = 0;
        std::pair<int, char> res;

        for (int i = 0; i < size; i++) {
            res = std::max(res, {releaseTimes[i] - prev, keysPressed[i]});
            prev = releaseTimes[i];
        }
        return res.second;
    }
};
// @lc code=end