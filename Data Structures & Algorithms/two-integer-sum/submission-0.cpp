class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; // This will store the number and its index
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                result.push_back(num_map[complement]);  // Push the index of the complement
                result.push_back(i);                    // Push the current index
                break;
            }
 
            num_map[nums[i]] = i;
        }
        return result;
    }
};
