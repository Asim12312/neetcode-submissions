//Time complexity: O(N)
//Space complexity O(N)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;

        deque<int> dq;

        for(int right = 0; right < nums.size(); right++) {

            // 1. Remove smaller elements from the back
            while(!dq.empty() && nums[dq.back()] <= nums[right]) {
                dq.pop_back();
            }

            // 2. Add current index
            dq.push_back(right);

            // 3. Remove elements outside the window
            int left = right - k + 1;

            while(!dq.empty() && dq.front() < left) {
                dq.pop_front();
            }

            // 4. Window has reached size k
            if(right >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};