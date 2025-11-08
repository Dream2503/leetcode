/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {

public:
    int evalRPN(const std::vector<std::string>& tokens) {
        std::stack<int> stack;

        for (const std::string& str : tokens) {
            if (std::isdigit(str.back())) {
                stack.push(std::stoi(str));
            } else {
                const int rhs = stack.top();
                stack.pop();
                const int lhs = stack.top();
                stack.pop();

                switch (str.front()) {
                case '+':
                    stack.push(lhs + rhs);
                    break;

                case '-':
                    stack.push(lhs - rhs);
                    break;

                case '*':
                    stack.push(lhs * rhs);
                    break;

                case '/':
                    stack.push(lhs / rhs);
                    break;

                default:
                    break;
                }
            }
        }
        return stack.top();
    }
};
// @lc code=end
