class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        int xaxis = 0;
        int area = 0;
        while(left < right){
            xaxis = right - left;
            if(height[left] < height[right]){
                area = height[left] * xaxis;
                if(area > maxArea){
                    maxArea = area;
                }
                left++;
            }
            else if(height[left] > height[right]){
                area = height[right] * xaxis;
                if(area > maxArea){
                    maxArea = area;
                }
                right--;
            }
            else{
                area = height[right] * xaxis;
                if(area > maxArea){
                    maxArea = area;
                }
                left++;
                right--;                
            }
        }
        return maxArea;
    }
};