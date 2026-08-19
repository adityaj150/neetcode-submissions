class Solution {
public:
    bool isPalindrome(string s) {
        string clean;
        for(char c : s) {
            if(isalnum(c)) {
                clean += tolower(c);
            }
        }
        
        return clean == string(clean.rbegin(), clean.rend());
    }
};
