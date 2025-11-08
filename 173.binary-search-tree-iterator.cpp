/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    std::stack<const TreeNode*> stack;

    void push_left(const TreeNode* node) {
        while (node) {
            stack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(const TreeNode* root) { push_left(root); }

    int next() {
        const TreeNode* node = stack.top();
        stack.pop();
        const int res = node->val;
        push_left(node->right);
        return res;
    }

    bool hasNext() { return !stack.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
