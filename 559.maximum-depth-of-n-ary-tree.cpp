/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void resolve(const Node* root, const int current, int& max) {
        if (root) {
            for (const Node* node : root->children) {
                resolve(node, current + 1, max);
            }
            max = std::max(max, current + 1);
        }
    }

public:
    int maxDepth(const Node* root) {
        int max = 0;
        resolve(root, 0, max);
        return max;
    }
};
// @lc code=end
