class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        int cheapestPrice = prices[0];  
        int maxProfit = 0; 
     
        for (int i = 1; i < prices.size(); i++) {
            int next = prices[i];  
            if (cheapestPrice > next) {
                cheapestPrice = next;
            } 
            else {
                int currProfit = next - cheapestPrice;
                if (currProfit > maxProfit) {
                    maxProfit = currProfit;
                }
            }
        }
        
        return maxProfit;
    }
};
