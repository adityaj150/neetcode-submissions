class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixproduct(n, 1);
        vector<int> suffixproduct(n, 1);

        for(int i = 1; i < n; i++){
            prefixproduct[i] = prefixproduct[i - 1] * nums[i - 1];
        }

        for(int i = n - 2; i >= 0; i--){
            suffixproduct[i] = suffixproduct[i + 1] * nums[i + 1];
        }

        vector<int> result(n);
        for(int i = 0; i < n; i++){
            result[i] = prefixproduct[i] * suffixproduct[i];
        }

        return result;
    }
};
