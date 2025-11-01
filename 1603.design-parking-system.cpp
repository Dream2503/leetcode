/*
 * @lc app=leetcode id=1603 lang=cpp
 *
 * [1603] Design Parking System
 */

// @lc code=start
class ParkingSystem {
    int big, medium, small;

public:
    ParkingSystem(const int big, const int medium, const int small) : big(big), medium(medium), small(small) {}

    bool addCar(const int carType) {
        switch (carType) {
        case 1:
            if (big) {
                big--;
                return true;
            }
            return false;

        case 2:
            if (medium) {
                medium--;
                return true;
            }
            return false;

        case 3:
            if (small) {
                small--;
                return true;
            }
            return false;

        default:
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end
