class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;  // If lengths are different, they cannot be anagrams
        }

        int freq[26] = {0};  // Array to store frequency of characters (assuming lowercase English letters)

        // Count frequencies for string 's' and decrease for string 't'
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;  // Increment frequency of character in 's'
            freq[t[i] - 'a']--;  // Decrement frequency of character in 't'
        }

        // If all frequencies are zero, the strings are anagrams
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;  // Strings are anagrams
    }
};

    /*bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;  
        }
        char c;
        int len = s.length();
        int i = 0, k = 0;
        int *arr = (int *)calloc(len, sizeof(int));
        while(s[i] != '\0'){
            c = s[i];
            int j = 0;
            while(t[j] != '\0'){
                if(c == t[j]){
                    if(!arr[j]){
                        arr[j] = 1;
                    }
                }
                j++;
            }
            i++;
        }
        for(int i = 0; i < len; i++){
            if(!arr[i]){
                return false;
            }
        }
        return true;
    }
};*/
