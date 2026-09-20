/*
 * @lc app=leetcode id=1904 lang=cpp
 *
 * [1904] The Number of Full Rounds You Have Played
 */

// @lc code=start
class Solution {
public:
    int numberOfRounds(const std::string& loginTime, const std::string& logoutTime) {
        std::pair<int, int> login_time, logout_time;
        std::sscanf(loginTime.c_str(), "%d:%d", &login_time.first, &login_time.second);
        std::sscanf(logoutTime.c_str(), "%d:%d", &logout_time.first, &logout_time.second);

        if (login_time > logout_time) {
            logout_time.first += 24;
        }
        int res = std::floor(logout_time.second / 15.0);
        res += 4 - std::ceil(login_time.second / 15.0);
        login_time.first++;
        return std::max(0, res + (logout_time.first - login_time.first) * 4);
    }
};
// @lc code=end
