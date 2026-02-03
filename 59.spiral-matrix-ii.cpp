/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(const int n) {
        enum class Direction { LEFT, UP, DOWN, RIGHT } direction = Direction::RIGHT;
        int cnt = 1, i = 0, j = 0;
        std::array edge = {0, 1, n, n}; // {left, up, down, right}
        std::vector res(n, std::vector(n, -1));

        while (true) {
            res[i][j] = cnt++;

            switch (direction) {
            case Direction::RIGHT:
                if (j + 1 < edge[3]) {
                    j++;
                } else {
                    direction = Direction::DOWN;
                    edge[3]--;
                    i++;

                    if (i == edge[2]) {
                        return res;
                    }
                }
                break;

            case Direction::DOWN:
                if (i + 1 < edge[2]) {
                    i++;
                } else {
                    direction = Direction::LEFT;
                    edge[2]--;
                    j--;

                    if (j == edge[0] - 1) {
                        return res;
                    }
                }
                break;

            case Direction::LEFT:
                if (j - 1 >= edge[0]) {
                    j--;
                } else {
                    direction = Direction::UP;
                    edge[0]++;
                    i--;

                    if (i == edge[1] - 1) {
                        return res;
                    }
                }
                break;

            default:
                if (i - 1 >= edge[1]) {
                    i--;
                } else {
                    direction = Direction::RIGHT;
                    edge[1]++;
                    j++;

                    if (j == edge[3]) {
                        return res;
                    }
                }
            }
        }
    }
};
// @lc code=end
