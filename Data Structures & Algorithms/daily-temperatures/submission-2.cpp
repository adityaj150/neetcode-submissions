class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> stk; 

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];

            while (!stk.empty() && t > temperatures[stk.top()]) {
                int prev = stk.top();
                stk.pop();

                ans[prev] = i - prev;
            }

            stk.push(i);
        }

        return ans;
    }
};