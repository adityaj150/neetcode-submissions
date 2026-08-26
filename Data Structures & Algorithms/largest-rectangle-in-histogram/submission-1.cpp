class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>stk;
        int maxarea = 0;

        for(int i = 0; i <= n; i++){
            int currheight = (i == n) ? 0 : heights[i];

            while(!stk.empty() && currheight < heights[stk.top()]){
                int h = heights[stk.top()];
                stk.pop();

                int width;
                
                if(stk.empty()){
                    width = i;
                }
                else{
                    width = i - stk.top() - 1;
                }

                maxarea = max(maxarea, h * width);
            }
            stk.push(i);
        }
        return maxarea;
    }
};
