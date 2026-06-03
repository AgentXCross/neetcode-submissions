class Solution {
public:
    int hammingWeight(uint32_t n) {
        int one_bits = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                one_bits += 1;
            }
        }
        return one_bits;
    }
};
