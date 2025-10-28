/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 */

// @lc code=start
// Boost Hash Combine algo - https://www.boost.org/doc/libs/1_89_0/libs/container_hash/doc/html/hash.html#notes_hash_combine
template <typename T, typename U>
struct std::hash<std::pair<T, U>> {
    size_t operator()(const std::pair<T, U>& pair) const noexcept {
        const size_t hash1 = std::hash<T>()(pair.first), hash2 = std::hash<U>()(pair.second);
        return hash1 ^ ((hash2 + 0x9e3779b97f4a7c15) + (hash1 << 6) + (hash1 >> 2));
    }
};

class Solution {
public:
    bool isPathCrossing(const std::string& path) {
        std::pair current(0, 0);
        std::unordered_set seen{current};

        for (const char ch : path) {
            std::pair next = current;

            switch (ch) {
            case 'N':
                next.second++;
                break;

            case 'S':
                next.second--;
                break;

            case 'E':
                next.first++;
                break;

            case 'W':
                next.first--;
                break;

            default:
                break;
            }
            if (!seen.insert(next).second) {
                return true;
            }
            current = next;
        }
        return false;
    }
};
// @lc code=end
