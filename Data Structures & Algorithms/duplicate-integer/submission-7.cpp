class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>num(nums.begin(), nums.end());
        
        return num.size() != nums.size();
    }
};