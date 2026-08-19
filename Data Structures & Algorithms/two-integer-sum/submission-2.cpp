class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hashmap;

        for(int i = 0; i < nums.size(); i++){
            int rest = target - nums[i];

            if(hashmap.find(rest) != hashmap.end()){
                return {hashmap[rest], i};
            }

            hashmap[nums[i]] = i;
        }
    }
};
