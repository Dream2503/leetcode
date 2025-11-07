/*
 * @lc app=leetcode id=2528 lang=cpp
 *
 * [2528] Maximize the Minimum Powered City
 */

// @lc code=start
class Solution {
    bool can(const std::vector<long long>& power, const long long min_power, const int r, const int k, std::vector<long long>& add) {
        const int size = power.size();
        long long used = 0, extra = 0;
        std::ranges::fill(add, 0);

        for (int i = 0; i < size; i++) {
            extra += add[i];

            if (power[i] + extra < min_power) {
                const long long need = min_power - (power[i] + extra);
                used += need;
                extra += need;

                if (used > k) {
                    return false;
                }
                if (i + 2 * r + 1 < size) {
                    add[i + 2 * r + 1] -= need;
                }
            }
        }
        return true;
    }

public:
    long long maxPower(const std::vector<int>& stations, const int r, const int k) {
        const int size = stations.size();
        std::vector<long long> prefix, add(size + 1);
        prefix.reserve(size + 1);
        prefix.push_back(0);

        for (const int station : stations) {
            prefix.push_back(prefix.back() + station);
        }
        std::vector<long long> power;
        power.reserve(size);

        for (int i = 0; i < size; i++) {
            power.push_back(prefix[std::min(size, i + r + 1)] - prefix[std::max(0, i - r)]);
        }
        long long low = *std::ranges::min_element(power), high = *std::ranges::max_element(prefix) + k, res = low;

        while (low <= high) {
            const long long mid = low + (high - low) / 2;

            if (can(power, mid, r, k, add)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};
// @lc code=end
