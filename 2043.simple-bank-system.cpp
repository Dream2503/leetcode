/*
 * @lc app=leetcode id=2043 lang=cpp
 *
 * [2043] Simple Bank System
 */

// @lc code=start
class Bank {
    std::vector<long long> balance;

public:
    Bank(const std::vector<long long>& balance) : balance(balance) {}

    bool transfer(const int account1, const int account2, const long long money) {
        if (account1 <= balance.size() && account2 <= balance.size() && withdraw(account1, money)) {
            return deposit(account2, money);
        }
        return false;
    }

    bool deposit(const int account, const long long money) {
        if (account <= balance.size()) {
            balance[account - 1] += money;
            return true;
        }
        return false;
    }

    bool withdraw(const int account, const long long money) {
        if (account <= balance.size() && balance[account - 1] >= money) {
            balance[account - 1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// @lc code=end
