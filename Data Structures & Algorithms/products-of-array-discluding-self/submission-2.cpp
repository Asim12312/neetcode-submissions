class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans(n, 1);
            
            //find prefix(product of all prev values for ith value)
            for(int i = 1; i < n; i++){
                ans[i] = ans[i-1] * nums[i-1];
            }

            //find suffix & multiply for ans
            int suffix = 1;
            for(int i = n-2; i >= 0; i--){
                suffix *= nums[i+1];
                ans[i] *= suffix;
            }

            return ans;
    }
};
