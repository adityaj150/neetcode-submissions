class Solution {
public:
    bool isValid(const std::string& s) {
        stack<char> stack;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c); 
            } 
            else {
                if (stack.empty()) 
                    return false; 

                char topChar = stack.top();
                stack.pop(); 

                if ((c == ')' && topChar != '(') ||
                    (c == '}' && topChar != '{') ||
                    (c == ']' && topChar != '[')) {
                    return false; 
                }
            }
        }

        return stack.empty(); 
    }
};