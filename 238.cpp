class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1); // Initialize ans with all 1s.

        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            ans[i] *= leftProduct; // Multiply by the product of elements to the left.
            leftProduct *= nums[i];
        }

        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= rightProduct; // Multiply by the product of elements to the right.
            rightProduct *= nums[i];
        }

        return ans;
    }
};