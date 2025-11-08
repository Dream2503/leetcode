/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

// @lc code=start
#include <ranges>

class Solution {
    struct TrieNode {
        std::unordered_map<char, TrieNode*> children;
        bool word = false;
    };

public:
    std::string replaceWords(const std::vector<std::string>& dictionary, const std::string& sentence) {
        const auto root = new TrieNode;
        std::string res;

        for (const std::string& key : dictionary) {
            TrieNode* current = root;

            for (const char ch : key) {
                auto itr = current->children.find(ch);

                if (itr != current->children.end()) {
                    current = itr->second;
                } else {
                    current = current->children.emplace(ch, new TrieNode).first->second;
                }
            }
            current->word = true;
        }
        for (auto&& word : std::views::split(sentence, ' ')) {
            bool found = true;
            TrieNode* current = root;
            std::string temp;

            for (const char ch : word) {
                auto itr = current->children.find(ch);

                if (itr != current->children.end()) {
                    temp.push_back(ch);
                    current = itr->second;

                    if (current->word) {
                        break;
                    }
                } else {
                    found = false;
                    break;
                }
            }
            if (found && current->word) {
                res.append(temp);
            } else {
                res.append(word.begin(), word.end());
            }
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end
