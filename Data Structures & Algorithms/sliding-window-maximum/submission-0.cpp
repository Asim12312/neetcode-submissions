//Time complexity: O(NlogN)
//Space complexity O(N)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;

        priority_queue<pair<int, int>> pq;

        for(int right = 0; right < nums.size(); right++) {

            // Add current element
            pq.push({nums[right], right});

            // Once window reaches size k
            if(right >= k - 1) {

                int left = right - k + 1;

                // Remove elements that are outside the window
                while(pq.top().second < left) {
                    pq.pop();
                }

                // Maximum of current window
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }
};