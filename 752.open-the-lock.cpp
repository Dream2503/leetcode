/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution {
public:
    int openLock(const std::vector<std::string>& deadends, const std::string& target) {
        std::unordered_set seen(deadends.begin(), deadends.end());
        std::queue<std::pair<std::string, int>> queue;

        if (seen.insert("0000").second) {
            queue.emplace("0000", 0);
        }
        while (!queue.empty()) {
            const auto [key, itr] = std::move(queue.front());
            queue.pop();

            if (key == target) {
                return itr;
            }
            std::string next = key;

            for (int i = 0; i < 4; i++) {
                next[i] = key[i] == '0' ? '9' : key[i] - 1;

                if (seen.insert(next).second) {
                    queue.emplace(next, itr + 1);
                }
                next[i] = key[i] == '9' ? '0' : key[i] + 1;

                if (seen.insert(next).second) {
                    queue.emplace(next, itr + 1);
                }
                next[i] = key[i];
            }
        }
        return -1;
    }
};
// @lc code=end
