class Solution {
public:
    bool isMatched(char open, char close) {
        if((open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}')
        )   return true;
        return false;
    }

    bool isValid(string str) {
        stack<char> s;
        for(int i=0; i < str.length(); i++) {
            if(str[i] == '(' || str[i] == '[' || 
               str[i] == '{') {
                s.push(str[i]);
            }
            // for closing bracket encountered
            else {
                if(s.empty()) return false;
                char ch = s.top();
                s.pop();
                if(!isMatched(ch, str[i])) 
                    return false;
            }
        }
        return s.empty();
    }
};