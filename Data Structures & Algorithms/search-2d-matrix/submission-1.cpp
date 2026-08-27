class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int targetrow = -1;

        for(int i = 0; i < n; i++){
            if(target > matrix[i][m - 1]){
                if(i == n - 1){
                    return false;
                }
                continue;
            }
            else if(target < matrix[i][m - 1]){
                targetrow = i;
                break;
            }
            else{
                return true;
            }
        }
        if(targetrow == -1){
            return false;
        }
        int left = 0;
        int right = m - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(matrix[targetrow][mid] == target){
                return true;
            }
            else if(matrix[targetrow][mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return false;
    }
};
