/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
    std::vector<int> asteroidCollision(const std::vector<int>& asteroids) {
        std::vector<int> res;

        for (const int asteroid : asteroids) {
            bool add = true;

            while (!res.empty() && res.back() > 0 && asteroid < 0) {
                if (res.back() < -asteroid) {
                    res.pop_back();
                } else if (res.back() > -asteroid) {
                    add = false;
                    break;
                } else {
                    res.pop_back();
                    add = false;
                    break;
                }
            }
            if (add) {
                res.push_back(asteroid);
            }
        }
        return res;
    }
};
// @lc code=end
