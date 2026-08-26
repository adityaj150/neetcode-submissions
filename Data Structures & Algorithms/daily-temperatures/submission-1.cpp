class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size(), 0);
        stack<pair<int, int>>stk; // {temp, index};

        for(int i = 0; i < temperatures.size(); i++){
            int t = temperatures[i];
            while(!stk.empty() && t > stk.top().first){
                auto dono = stk.top();
                stk.pop();
                ans[dono.second] = i - dono.second;
            }
            stk.push({t, i});
        }
        return ans;
    }
};
