/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    std::unordered_map<const Node*, Node*> visited;

public:
    Node* cloneGraph(const Node* node) {
        if (node) {
            const auto res = new Node(node->val);
            visited.emplace(node, res);
            res->neighbors.reserve(node->neighbors.size());

            for (const Node* adj : node->neighbors) {
                if (!visited.contains(adj)) {
                    res->neighbors.push_back(cloneGraph(adj));
                } else {
                    res->neighbors.push_back(visited[adj]);
                }
            }
            return res;
        }
        return nullptr;
    }
};
// @lc code=end
