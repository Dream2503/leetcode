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
    std::pair<int, int> bfs(const int V, const std::vector<std::vector<int>>& graph, const int start) {
        int farthest_node = start;
        std::vector dist(V, -1);
        std::queue<int> queue;
        queue.push(start);
        dist[start] = 0;

        while (!queue.empty()) {
            const int node = queue.front();
            queue.pop();

            for (int adjacent : graph[node]) {
                if (dist[adjacent] == -1) {
                    dist[adjacent] = dist[node] + 1;
                    queue.push(adjacent);

                    if (dist[adjacent] > dist[farthest_node]) {
                        farthest_node = adjacent;
                    }
                }
            }
        }
        return {farthest_node, dist[farthest_node]};
    }

public:
    int diameter(const int V, const std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> graph(V);

        for (const std::vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        auto [node, _] = bfs(V, graph, 0);
        auto [farthest, diameter] = bfs(V, graph, node);
        return diameter;
    }
};


int main() {
    Solution sol;
    const std::chrono::time_point<std::chrono::system_clock> start = std::chrono::high_resolution_clock::now();

    // sol.luckyNumbers({{3, 7, 8}, {9, 11, 13}, {15, 16, 17}});

    const std::chrono::duration<double> time = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Total time taken: " << time.count();
    return 0;
}

#include "all_in_one.hpp"
