class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 1;
        int right = numbers.size();
        vector<int> finalArr;
        while((left - 1) < (right - 1)){
            if(numbers[left - 1] + numbers[right - 1] == target){
                finalArr.push_back(left);
                finalArr.push_back(right);
                break;
            }
            else if(numbers[left - 1] + numbers[right - 1] < target){
                left++;
            }
            else if(numbers[left - 1] + numbers[right - 1] > target){
                right--;
            }
        }
        return finalArr;
    }
};