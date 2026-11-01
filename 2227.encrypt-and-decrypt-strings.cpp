/*
 * @lc app=leetcode id=2227 lang=cpp
 *
 * [2227] Encrypt and Decrypt Strings
 */

// @lc code=start
class Encrypter {
    struct TrieNode {
        char letter;
        int end_count = 0;
        std::vector<TrieNode> children;

        TrieNode(const char letter) noexcept : letter(letter) {}
        bool operator==(const TrieNode& rhs) const noexcept { return letter == rhs.letter; }
    };
    std::unordered_map<char, std::string> encrypter;
    std::multimap<std::string, char> decrypter;
    std::vector<TrieNode> dictionary;

public:
    Encrypter(const std::vector<char>& keys, const std::vector<std::string>& values, const std::vector<std::string>& dictionary) :
        encrypter(std::views::zip(keys, values) | std::ranges::to<std::unordered_map<char, std::string>>()),
        decrypter(std::views::zip(values, keys) | std::ranges::to<std::multimap<std::string, char>>()) {
        for (const std::string& word : dictionary) {
            std::vector<TrieNode>* children = &this->dictionary;
            TrieNode* node = nullptr;

            for (const char ch : word) {
                auto itr = std::ranges::find(*children, TrieNode(ch));

                if (itr == children->end()) {
                    children->emplace_back(ch);
                    itr = children->end() - 1;
                }
                node = &*itr;
                children = &node->children;
            }
            node->end_count++;
        }
    }

    std::string encrypt(const std::string& word1) {
        std::string res;
        res.reserve(word1.size() * 2);

        for (const char ch : word1) {
            res.append(encrypter[ch]);
        }
        return res;
    }

    int decrypt(const std::string& word2) {
        bool first = true;
        int res = 0;
        std::vector<const TrieNode*> search_space = dictionary |
            std::views::transform([](const TrieNode& node) -> const TrieNode* { return &node; }) | std::ranges::to<std::vector<const TrieNode*>>();

        for (const std::string& key : word2 | std::views::chunk(2) | std::ranges::to<std::vector<std::string>>()) {
            const auto [begin, end] = decrypter.equal_range(key);
            std::vector<const TrieNode*> next;

            if (first) [[unlikely]] {
                for (auto itr = begin; itr != end; ++itr) {
                    if (auto node = std::ranges::find(dictionary, TrieNode(itr->second)); node != dictionary.end()) {
                        next.push_back(&*node);
                    }
                }
                first = false;
            } else {
                for (const TrieNode* node : search_space) {
                    for (auto itr = begin; itr != end; ++itr) {
                        if (auto child = std::ranges::find(node->children, TrieNode(itr->second)); child != node->children.end()) {
                            next.push_back(&*child);
                        }
                    }
                }
            }
            if ((search_space = std::move(next)).empty()) {
                return 0;
            }
        }
        for (const TrieNode* node : search_space) {
            res += node->end_count;
        }
        return res;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
// @lc code=end
