class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Skip duplicate i values
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {

                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicate j values
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }

                    // Skip duplicate k values
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }

                else if (sum < 0) {
                    j++;
                }

                else {
                    k--;
                }
            }
        }

        return ans;
    }
};