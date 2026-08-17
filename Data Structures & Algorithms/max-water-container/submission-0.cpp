class Solution {
public:
    int maxArea(vector<int>& heights) {
        int width = heights.size() - 1;
        int maxArea = 0;
        int height = -1;
        int left = 0;
        int right = heights.size() - 1;
        while(left < right){
            height = min(heights[left], heights[right]);
            maxArea = max(height * width, maxArea);
            if(heights[left] < heights[right]){
                left++;
                width--;
            }
            else{
                right--;
                width--;
            }
        }
        return maxArea;
    }
};
