/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
    struct TrieNode {
        std::unordered_map<char, TrieNode*> children;
        bool word = false;
    }* root;

public:
    Trie() : root(new TrieNode) {}

    void insert(const std::string& word) {
        TrieNode* current = root;

        for (const char ch : word) {
            auto itr = current->children.find(ch);

            if (itr != current->children.end()) {
                current = itr->second;
            } else {
                current = current->children.emplace(ch, new TrieNode).first->second;
            }
        }
        current->word = true;
    }

    bool search(const std::string& word) {
        TrieNode* current = root;

        for (const char ch : word) {
            auto itr = current->children.find(ch);

            if (itr != current->children.end()) {
                current = itr->second;
            } else {
                return false;
            }
        }
        return current->word;
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* current = root;

        for (const char ch : prefix) {
            auto itr = current->children.find(ch);

            if (itr != current->children.end()) {
                current = itr->second;
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
