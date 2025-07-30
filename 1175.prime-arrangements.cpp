/*
 * @lc app=leetcode id=1175 lang=cpp
 *
 * [1175] Prime Arrangements
 */

// @lc code=start
constexpr int MOD = 1'000'000'007;

constexpr int factorial(const int n) {
    int res = 1;

    for (int i = 2; i <= n; ++i) {
        res = 1l * res * i % MOD;
    }
    return res;
}
constexpr __uint128_t compute_prime_mask() {
    __uint128_t mask = 0;

    for (int i = 2; i <= 100; i++) {
        bool is_prime = true;

        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            mask |= (static_cast<__uint128_t>(1) << i);
        }
    }
    return mask;
}
constexpr __uint128_t PRIME_MASK = compute_prime_mask();

constexpr std::array<int, 101> compute_answers() {
    std::array<int, 101> res{};

    for (int n = 0; n <= 100; ++n) {
        int prime_count = 0;

        for (int i = 2; i <= n; ++i) {
            if (PRIME_MASK >> i & 1) {
                prime_count++;
            }
        }
        res[n] = 1l * factorial(prime_count) * factorial(n - prime_count) % MOD;
    }
    return res;
}

class Solution {
    static constexpr std::array<int, 101> res = compute_answers();

public:
    int numPrimeArrangements(const int n) { return res[n]; }
};
// @lc code=end
