/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
    std::string infix_to_postfix(const std::string& infix) {
        const int size = infix.size();
        std::string postfix;
        std::stack<char> stack;
        postfix.reserve(size);
        stack.push('(');

        for (int i = 0; i < size; i++) {
            switch (infix[i]) {
            case '(':
                stack.push('(');
                break;

            case ')':
                {
                    char ch = stack.top();
                    stack.pop();

                    while (ch != '(') {
                        postfix.push_back(ch);
                        ch = stack.top();
                        stack.pop();
                    }
                    break;
                }

            case '+':
            case '-':
                {
                    int j = i - 1;
                    while (j >= 0 && infix[j] == ' ') {
                        j--;
                    }
                    if (j < 0 || infix[j] == '(' || infix[j] == '+' || infix[j] == '-') {
                        postfix += "0#";
                    }
                    while (stack.top() != '(') {
                        postfix.push_back(stack.top());
                        stack.pop();
                    }
                    stack.push(infix[i]);
                    break;
                }

            case ' ':
                break;

            default:
                while (isdigit(infix[i])) {
                    postfix.push_back(infix[i++]);
                }
                postfix.push_back('#');
                i--;
            }
        }
        while (stack.top() != '(') {
            postfix.push_back(stack.top());
            stack.pop();
        }
        return postfix;
    }

    int postfix_evaluation(const std::string& postfix) {
        const int size = postfix.size();
        int i = 0;
        std::stack<int> stack;

        while (i < size) {
            std::string number;

            while (isdigit(postfix[i])) {
                number.push_back(postfix[i++]);
            }
            if (!number.empty()) {
                stack.push(std::stoi(number));
            } else {
                const int element2 = stack.top();
                stack.pop();
                const int element1 = stack.top();
                stack.pop();
                stack.push(postfix[i] == '+' ? element1 + element2 : element1 - element2);
            }
            i++;
        }
        return stack.top();
    }

public:
    int calculate(const std::string& s) { return postfix_evaluation(infix_to_postfix(s)); }
};
// @lc code=end
