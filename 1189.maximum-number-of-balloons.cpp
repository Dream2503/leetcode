/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
class Solution {
public:
    int maxNumberOfBalloons(const std::string& text) {
        static std::array<int, 5> balloon; // b a l o n
        balloon.fill(0);

        for (const char ch : text) {
            switch (ch) {
            case 'b':
                balloon[0]++;
                break;

            case 'a':
                balloon[1]++;
                break;

            case 'l':
                balloon[2]++;
                break;

            case 'o':
                balloon[3]++;
                break;

            case 'n':
                balloon[4]++;
                break;

            default:
            }
        }
        balloon[2] /= 2;
        balloon[3] /= 2;
        return *std::min_element(balloon.begin(), balloon.end());
    }
};
// @lc code=end
