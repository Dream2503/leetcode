/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 */

// @lc code=start
class StreamChecker {
    struct TrieNode {
        char letter;
        bool is_end = false;
        std::vector<TrieNode> children;

        TrieNode(const char letter) noexcept : letter(letter) {}
        bool operator==(const TrieNode& other) const noexcept { return this->letter == other.letter; }
    };
    std::vector<TrieNode> words;
    std::string word;

public:
    StreamChecker(const std::vector<std::string>& words) {
        for (const std::string& current : words) {
            std::vector<TrieNode>* children = &this->words;
            TrieNode* node = nullptr;

            for (const char ch : current | std::views::reverse) {
                auto itr = std::ranges::find(*children, TrieNode(ch));

                if (itr == children->end()) {
                    children->emplace_back(ch);
                    itr = children->end() - 1;
                }
                node = &*itr;
                children = &node->children;
            }
            node->is_end = true;
        }
    }

    bool query(const char letter) {
        word.push_back(letter);
        const std::vector<TrieNode>* children = &words;

        for (const char ch : word | std::views::reverse) {
            auto itr = std::ranges::find(*children, TrieNode(ch));

            if (itr == children->end()) {
                return false;
            }
            if (itr->is_end) {
                return true;
            }
            children = &itr->children;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
// @lc code=end
