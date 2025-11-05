/*
 * @lc app=leetcode id=3321 lang=cpp
 *
 * [3321] Find X-Sum of All K-Long Subarrays II
 */

// @lc code=start
class Solution {
    void balance(long long& top_sum, std::multiset<std::pair<int, int>>& top, std::multiset<std::pair<int, int>>& rest, const int x) {
        while (top.size() < x && !rest.empty()) {
            auto itr = prev(rest.end());
            top.insert(*itr);
            top_sum += 1ll * itr->first * itr->second;
            rest.erase(itr);
        }
        while (top.size() > x) {
            auto itr = top.begin();
            top_sum -= 1ll * itr->first * itr->second;
            rest.insert(*itr);
            top.erase(itr);
        }
        while (!rest.empty() && !top.empty() && *prev(rest.end()) > *top.begin()) {
            auto itr1 = prev(rest.end()), itr2 = top.begin();
            top_sum += 1ll * itr1->first * itr1->second - 1LL * itr2->first * itr2->second;
            rest.insert(*itr2);
            top.insert(*itr1);
            rest.erase(itr1);
            top.erase(itr2);
        }
    }

    void add(const int num, long long& top_sum, std::map<int, int>& hash, std::multiset<std::pair<int, int>>& top,
             std::multiset<std::pair<int, int>>& rest, const int x) {
        const std::pair prev = {hash[num], num};

        if (top.contains(prev)) {
            top.erase(top.find(prev));
            top_sum -= 1ll * prev.first * prev.second;
        } else if (rest.contains(prev)) {
            rest.erase(rest.find(prev));
        }
        hash[num]++;
        rest.insert({hash[num], num});
        balance(top_sum, top, rest, x);
    }

    void remove(const int num, long long& top_sum, std::map<int, int>& hash, std::multiset<std::pair<int, int>>& top,
                std::multiset<std::pair<int, int>>& rest, const int x) {
        const std::pair prev = {hash[num], num};

        if (top.contains(prev)) {
            top.erase(top.find(prev));
            top_sum -= 1ll * prev.first * prev.second;
        } else {
            rest.erase(rest.find(prev));
        }
        hash[num]--;

        if (hash[num] > 0) {
            rest.insert({hash[num], num});
        } else {
            hash.erase(num);
        }
        balance(top_sum, top, rest, x);
    }

public:
    std::vector<long long> findXSum(const std::vector<int>& nums, const int k, const int x) {
        const int size = nums.size();
        long long top_sum = 0;
        std::vector<long long> res;
        std::map<int, int> hash;
        std::multiset<std::pair<int, int>> top, rest;

        for (int i = 0; i < k; i++) {
            add(nums[i], top_sum, hash, top, rest, x);
        }
        res.push_back(top_sum);

        for (int i = k; i < size; i++) {
            remove(nums[i - k], top_sum, hash, top, rest, x);
            add(nums[i], top_sum, hash, top, rest, x);
            res.push_back(top_sum);
        }
        return res;
    }
};
// @lc code=end
