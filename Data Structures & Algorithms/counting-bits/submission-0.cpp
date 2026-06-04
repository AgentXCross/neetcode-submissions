class Solution {
private:
    int num_ones(int x) {
        int number_of_ones = 0;
        for (int i = 0; i < 32; i++) {
            if (x & (1 << i)) {
                number_of_ones++;
            }
        }
        return number_of_ones;
    }
public:
    vector<int> countBits(int n) {
        vector<int> output(n + 1);

        for (int x = 0; x <= n; x++) {
            output[x] = num_ones(x);
        }

        return output;
    }
};
