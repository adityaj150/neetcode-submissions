class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //first flatten the 2D array into 1D array
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>flatten;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                flatten.push_back(matrix[i][j]);
            }
        }

        int len = flatten.size();
        int left = 0;
        int right = flatten.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(target > flatten[mid]){
                left = mid + 1;
            }
            else if(target < flatten[mid]){
                right = mid - 1;
            }
            else if(flatten[mid] == target){
                return true;
            }
        }
        return false;
    }
};
