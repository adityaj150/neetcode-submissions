class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>hashmap;

        for(int num : nums){
            hashmap[num]++;
        }

        priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>, 
            greater<pair<int, int>>
        >pq;

        for(auto [num, count] : hashmap){
            pq.push({count, num});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int>ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
