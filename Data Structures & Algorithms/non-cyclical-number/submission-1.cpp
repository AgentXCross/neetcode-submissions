class Solution {
private:
    int sumOfSquaresDigits(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            sum += digit * digit;
        }

        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while(seen.find(n) == seen.end()) {
            // while n is not in seen
            seen.insert(n);
            n = sumOfSquaresDigits(n);
            if (n == 1) {
                return true;
            }
        }

        return false;
    }
};
