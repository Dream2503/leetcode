/*
 * @lc app=leetcode id=3510 lang=cpp
 *
 * [3510] Minimum Pair Removal to Sort Array II
 */

// @lc code=start
class Solution {
    void remove(const int i, const std::map<int, int64_t>& array, std::map<int64_t, std::set<int>>& sum) {
        auto itr = array.find(i);
        if (itr == array.end() || std::next(itr) == array.end()) {
            return;
        }
        const int64_t s = itr->second + std::next(itr)->second;
        const auto it = sum.find(s);
        it->second.erase(i);

        if (it->second.empty()) {
            sum.erase(it);
        }
    }

    void insert(const int i, const std::map<int, int64_t>& array, std::map<int64_t, std::set<int>>& sum) {
        auto itr = array.find(i);
        if (itr != array.end() && std::next(itr) != array.end()) {
            sum[itr->second + std::next(itr)->second].insert(i);
        }
    }

public:
    int minimumPairRemoval(const std::vector<int>& nums) {
        const int size = nums.size();
        int bad = 0, res = 0;
        std::map<int, int64_t> array;
        std::map<int64_t, std::set<int>> sum;

        for (int i = 0; i < size; i++) {
            array[i] = nums[i];
            if (i + 1 < size) {
                sum[array[i] + nums[i + 1]].insert(i);
                bad += nums[i] > nums[i + 1];
            }
        }
        while (bad) {
            const auto itr = sum.begin();
            const int i = *itr->second.begin();
            auto current = array.find(i);
            const auto next = std::next(current);
            auto prev = current == array.begin() ? array.end() : std::prev(current);
            auto after = std::next(next);
            const int j = next->first, p = prev == array.end() ? -1 : prev->first;
            const int64_t merged = current->second + next->second;
            remove(p, array, sum);
            remove(i, array, sum);
            remove(j, array, sum);

            if (prev != array.end()) {
                bad -= prev->second > current->second;
            }
            bad -= current->second > next->second;

            if (after != array.end()) {
                bad -= next->second > after->second;
            }
            current->second = merged;
            array.erase(next);

            if (prev != array.end()) {
                bad += prev->second > current->second;
            }
            if (after != array.end()) {
                bad += current->second > after->second;
            }
            insert(p, array, sum);
            insert(i, array, sum);
            res++;
        }
        return res;
    }
};
// @lc code=end
