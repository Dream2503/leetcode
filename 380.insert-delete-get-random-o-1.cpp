/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
    std::vector<int> set;
    std::unordered_map<int, int> hash;

public:
    RandomizedSet() noexcept = default;

    bool insert(const int val) noexcept {
        if (!hash.contains(val)) {
            set.push_back(val);
            hash[val] = set.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(const int val) noexcept {
        if (hash.contains(val)) {
            const int idx = hash[val];
            set[idx] = set.back();
            hash[set.back()] = idx;
            set.pop_back();
            hash.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() const noexcept { return set[std::rand() % set.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
