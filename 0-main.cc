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
    int bfs(const std::vector<std::vector<int>>& graph, const int source) {
        static std::vector<int> distances(graph.size());
        int min = INT32_MAX;
        std::queue<std::pair<int, int>> queue;
        std::ranges::fill(distances, -1);
        queue.emplace(source, 0);

        while (!queue.empty()) {
            const auto [node, distance] = queue.front();
            queue.pop();

            if (distances[node] != -1) {
                if (distances[node] - distance != 2) {
                    return distances[node] + distance + 1;;
                } else {
                    continue;
                }
            }
            distances[node] = distance;

            for (const int neighbour : graph[node]) {
                queue.emplace(neighbour, distance + 1);
            }
        }
        return INT32_MAX;
    }

public:
    int findShortestCycle(const int n, const std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> graph(n);

        for (const std::vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int min = INT32_MAX;

        for (int i = 0; i < n; i++) {
            min = std::min(min, bfs(graph, i));
        }
        return min == INT32_MAX ? -1 : min;
    }
};


int main() {
    Solution sol;
    const std::chrono::time_point<std::chrono::system_clock> start = std::chrono::high_resolution_clock::now();

    sol.findShortestCycle(8, {{1,3},{3,5},{5,7},{7,1},{0,2},{2,4},{4,0}});

    const std::chrono::duration<double> time = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Total time taken: " << time.count();
    return 0;
}

#include "all_in_one.hpp"
