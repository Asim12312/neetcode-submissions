class Solution {
public:
    int trap(vector<int>& height) {

        // Store max height from left/right at each index
        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);

        int size = height.size() - 1;

        leftMax[0] = height[0];
        rightMax[size] = height[size];

        // Build left maximums
        for(int i = 1; i <= size; i++){
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }

        // Build right maximums
        for(int i = size - 1; i >= 0; i--){
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }

        int ans = 0;

        // Water = smaller wall - current height
        for(int i = 0; i <= size; i++){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }

        return ans;
    }
};