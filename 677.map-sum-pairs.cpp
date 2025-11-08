/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 */

// @lc code=start
#include <ranges>

class MapSum {
    struct TrieNode {
        std::unordered_map<char, TrieNode*> children;
        int data = 0;
    }* root;

    int sum(const TrieNode* node) {
        if (node) {
            int res = node->data;

            for (const TrieNode* child : node->children | std::views::values) {
                res += sum(child);
            }
            return res;
        }
        return 0;
    }

public:
    MapSum() : root(new TrieNode) {}

    void insert(const std::string& key, const int val) {
        TrieNode* current = root;

        for (const char ch : key) {
            auto itr = current->children.find(ch);

            if (itr != current->children.end()) {
                current = itr->second;
            } else {
                current = current->children.emplace(ch, new TrieNode).first->second;
            }
        }
        current->data = val;
    }

    int sum(const std::string& prefix) {
        bool found = true;
        TrieNode* current = root;

        for (const char ch : prefix) {
            auto itr = current->children.find(ch);

            if (itr != current->children.end()) {
                current = itr->second;
            } else {
                found = false;
                break;
            }
        }
        if (found) {
            return sum(current);
        }
        return 0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end
