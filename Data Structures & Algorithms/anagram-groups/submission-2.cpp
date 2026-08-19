class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>hashmap;

        for(string s : strs){
            string key = s;
            sort(key.begin(), key.end());
            hashmap[key].push_back(s);
        }

        vector<vector<string>>ans;

        for(auto &[key, group] : hashmap){
            ans.push_back(group);
        }

        return ans;
    }
};
