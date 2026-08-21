class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>map;
        int left = 0, len = 0;

        for(int right = 0; right < s.size(); right++){
            if(map.find(s[right]) != map.end()){
                left = max(map[s[right]] + 1, left);
            }
            map[s[right]] = right;
            len = max(len, right - left + 1);
        }
        return len;
    }
};
