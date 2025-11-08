/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
#include <ranges>

class WordDictionary {
    struct TrieNode {
        std::unordered_map<char, TrieNode*> children;
        bool word = false;
    }* root;

    bool search(const TrieNode* node, const std::string& word, const int i) {
        if (node) {
            if (i == word.size()) {
                return node->word;
            }
            if (word[i] == '.') {
                for (const TrieNode* child : node->children | std::views::values) {
                    if (search(child, word, i + 1)) {
                        return true;
                    }
                }
                return false;
            }
            const auto itr = node->children.find(word[i]);
            return search(itr != node->children.end() ? itr->second : nullptr, word, i + 1);
        }
        return false;
    }

public:
    WordDictionary() : root(new TrieNode) {}

    void addWord(const std::string& word) {
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

    bool search(const std::string& word) { return search(root, word, 0); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
