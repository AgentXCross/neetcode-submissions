class Solution {
public:
    std::vector<int> productExceptSelf(
        std::vector<int> &nums
    ) {
        std::size_t nums_size = nums.size();

        std::vector<int> left_product(nums_size, 0);
        std::vector<int> right_product(nums_size, 0);

        int product = 1;

        for (int i = 0; i < nums_size; i++) {
            left_product[i] = product;
            product *= nums[i];
        }

        product = 1;

        for (int j = nums_size - 1; j >= 0; j--) {
            right_product[j] = product;
            product *= nums[j];
        }

        std::vector<int> product_except_self(nums_size);

        for (int k = 0; k < nums_size; k++) {
            product_except_self[k] = left_product[k] * right_product[k];
        }

        return product_except_self;
    }
};
