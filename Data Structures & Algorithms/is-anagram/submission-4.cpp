class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        map<char, int>hashmap;
        for(char c : s){
            hashmap[c]++;
        }
        for(char c : t){
            hashmap[c]--;
        }

        for(auto mp : hashmap){
            if(mp.second != 0){
                return false;
            }
        }

        return true;
    }
};