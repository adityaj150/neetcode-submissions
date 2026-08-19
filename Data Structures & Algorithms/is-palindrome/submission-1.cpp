class Solution {
public:
    bool isPalindrome(string s) {
        stack<int>st;
        string clean;
        for(char c : s) {
            if(isalnum(c)) {
                clean += tolower(c);
            }
        }

        for(char c : clean){
            st.push(c);
        }

        for(int i = 0; i < clean.size(); i++){
            if(st.top() != clean[i]){
                return false;
            }
            st.pop();
        }

        return true;
    }
};
