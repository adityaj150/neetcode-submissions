class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            int totalhours = 0;
            for(int pile : piles){
                totalhours += ceil((double)pile / mid);
            }
            if(totalhours <= h){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
