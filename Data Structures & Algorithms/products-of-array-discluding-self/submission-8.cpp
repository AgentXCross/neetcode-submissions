class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int nums_length = nums.size();
        vector<int> result(nums_length, 1);
        
        vector<int> products_left(nums_length, 1);
        vector<int> products_right(nums_length, 1);

        int product_l_to_r = 1;
        for (int i = 0; i < nums_length; i++) {
            products_left[i] = product_l_to_r;
            product_l_to_r *= nums[i];
        }

        int product_r_to_l = 1;
        for (int j = nums_length - 1; j >= 0; j--) {
            products_right[j] = product_r_to_l;
            product_r_to_l *= nums[j];
        }

        for (int k = 0; k < nums_length; k++) {
            result[k] = products_left[k] * products_right[k];
        }

        return result;
    }
};
