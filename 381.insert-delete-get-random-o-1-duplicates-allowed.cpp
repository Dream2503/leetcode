/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */

// @lc code=start
class RandomizedCollection {
    std::vector<int> multi_set;
    std::unordered_multimap<int, int> hash;

public:
    RandomizedCollection() noexcept = default;

    bool insert(const int val) noexcept {
        const bool res = !hash.contains(val);
        multi_set.push_back(val);
        hash.emplace(val, multi_set.size() - 1);
        return res;
    }

    bool remove(const int val) noexcept {
        if (hash.contains(val)) {
            auto [begin, end] = hash.equal_range(val);
            const int idx = begin->second, last_idx = multi_set.size() - 1, last_val = multi_set.back();
            multi_set[idx] = last_val;

            if (idx != last_idx) {
                auto [b2, e2] = hash.equal_range(last_val);

                for (auto it = b2; it != e2; ++it) {
                    if (it->second == last_idx) {
                        it->second = idx;
                        break;
                    }
                }
            }
            multi_set.pop_back();
            hash.erase(begin);
            return true;
        }
        return false;
    }

    int getRandom() const noexcept { return multi_set.size() ? multi_set[std::rand() % multi_set.size()] : 0; }
};


/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
