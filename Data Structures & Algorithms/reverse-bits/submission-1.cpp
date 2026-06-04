class Solution {
private:
    bool ith_is_set(uint32_t n, int i) {
        return n & (1 << i);
    }
public:
    uint32_t reverseBits(uint32_t n) {
        int right = 0;
        int left = 31;

        while (left > right) {
            bool left_is_set = ith_is_set(n, left);
            bool right_is_set = ith_is_set(n, right);

            if (left_is_set) {
                n |= (1 << right);
            } else {
                n &= ~(1 << right);
            }

            if (right_is_set) {
                n |= (1 << left);
            } else {
                n &= ~(1 << left);
            }

            right++;
            left--;
        }

        return n;
    }
};
