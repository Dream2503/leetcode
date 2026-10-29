/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
class Solution {
public:
    std::string pushDominoes(std::string dominoes) {
        bool changed = true;
        const int size = static_cast<int>(dominoes.size());
        std::unordered_map<int, char> dom;

        for (int i = 0; i < size; i++) {
            if (dominoes[i] == 'L' || dominoes[i] == 'R') {
                dom.emplace(i, dominoes[i]);
            }
        }

        while (changed) {
            changed = false;
            std::unordered_map<int, char> next;

            for (const auto& [index, direction] : dom) {
                if (direction == 'L') {
                    if (dom.contains(index - 2) && dominoes[index - 2] == 'R') {
                        continue;
                    }
                    if (index > 0 && dominoes[index - 1] == '.') {
                        next[index - 1] = 'L';
                        changed = true;
                    }
                } else {
                    if (dom.contains(index + 2) && dominoes[index + 2] == 'L') {
                        continue;
                    }
                    if (index + 1 < size && dominoes[index + 1] == '.') {
                        next[index + 1] = 'R';
                        changed = true;
                    }
                }
            }
            for (const auto& [index, direction] : next) {
                dominoes[index] = direction;
            }
            dom = std::move(next);
        }
        return dominoes;
    }
};
// @lc code=end
