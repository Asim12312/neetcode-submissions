class Solution {
public:
    int trap(vector<int>& height) {

        int ans = 0;

        // Two pointers start from both ends
        int left = 0;
        int right = height.size() - 1;

        // Maximum wall seen from each side
        int leftMax = 0;
        int rightMax = 0;

        while(left < right){

            // Update maximum heights
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);

            // Smaller wall determines the water level
            if(leftMax < rightMax){

                // Calculate water trapped at left
                ans += leftMax - height[left];
                left++;
            }
            else{

                // Calculate water trapped at right
                ans += rightMax - height[right];
                right--;
            }
        }

        return ans;
    }
};