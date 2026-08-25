class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        map<char, char>charmap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c : s){
            if(charmap.find(c) != charmap.end()){
                if(!stk.empty() && stk.top() == charmap[c]){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
            else{
                stk.push(c);
            }
        }

        return stk.empty();
    }
};
