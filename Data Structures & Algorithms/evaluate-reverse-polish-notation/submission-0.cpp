class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stack;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int firstOperand = stack.top();
                stack.pop();
                
                int secondOperand = stack.top();
                stack.pop();

                switch (tokens[i][0]) {  
                    case '+':
                        stack.push(secondOperand + firstOperand);
                        break;
                    case '-':
                        stack.push(secondOperand - firstOperand);
                        break;
                    case '*':
                        stack.push(secondOperand * firstOperand);
                        break;
                    case '/':
                        stack.push(secondOperand / firstOperand);
                        break;
                }
            }
            else{
                int operand = stoi(tokens[i]);
                stack.push(operand);
            }
        }
        return stack.top();
    }
};