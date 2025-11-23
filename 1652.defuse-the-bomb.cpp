/*
 * @lc app=leetcode id=1652 lang=cpp
 *
 * [1652] Defuse the Bomb
 */

// @lc code=start
class Solution {
public:
    std::vector<int> decrypt(const std::vector<int>& code, const int k) {
        const int size = code.size();
        int sum = 0, i, j = 0;

        if (k > 0) {
            for (i = 1, j = 0; j < k; i = (i + 1) % size, j++) {
                sum += code[i];
            }
            j = i;
            i = 1;
        } else if (k < 0) {
            for (i = size - 1, j = 0; j < -k; i = (size + i - 1) % size, j++) {
                sum += code[i];
            }
            i = (i + 1) % size;
            j = 0;
        } else {
            return std::vector(size, 0);
        }
        std::vector<int> res;
        res.reserve(size);

        for (int l = 0; l < size; l++) {
            res.push_back(sum);
            sum -= code[i];
            sum += code[j];
            i = (i + 1) % size;
            j = (j + 1) % size;
        }
        return res;
    }
};
// @lc code=end
