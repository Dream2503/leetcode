#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : ListNode(0, nullptr) {}
    ListNode(const int val) : ListNode(val, nullptr) {}
    ListNode(const int val, ListNode* next) : val(val), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode() : TreeNode(0, nullptr, nullptr) {}
    TreeNode(const int val) : TreeNode(val, nullptr, nullptr) {}
    TreeNode(const int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

// class Node {
// public:
//     int val;
//     Node *next, random;
//
//     Node(const int val) : val(val), next(nullptr), random(nullptr) {}
// };

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() = default;
    Node(const int val) : val(val) {}
    Node(const int val, const std::vector<Node*>& children) : val(val), children(children) {}
};


ListNode* create(const std::vector<int>& vec) {
    [[unlikely]] ListNode *head = new ListNode(vec[0]), *current = head;

    for (const int num : vec) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return head->next;
}

void free(const ListNode* head) {
    while (head) {
        const ListNode* next = head->next;
        delete head;
        head = next;
    }
}

void print(const ListNode* head) {
    std::cout << '[';

    while (head->next) {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << head->val << ']';
}

class Solution {
public:
    std::vector<int> luckyNumbers(const std::vector<std::vector<int>> matrix) {
        const int col_size = matrix.front().size();
        std::vector<int> min_cols, res;
        min_cols.reserve(col_size);

        for (int i = 0; i < col_size; i++) {
            min_cols.push_back(std::ranges::max_element(matrix, {}, [i](const std::vector<int>& col) -> int { return col[i]; })->at(i));
        }
        for (const std::vector<int>& row : matrix) {
            const int idx = std::ranges::min_element(row) - row.begin();

            if (row[idx] == min_cols[idx]) {
                res.push_back(row[idx]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    const std::chrono::time_point<std::chrono::system_clock> start = std::chrono::high_resolution_clock::now();

    sol.luckyNumbers({{3, 7, 8}, {9, 11, 13}, {15, 16, 17}});

    const std::chrono::duration<double> time = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Total time taken: " << time.count();
    return 0;
}

#include "all_in_one.hpp"
