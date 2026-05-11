class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string currentStr = "";
        int currentNum = 0;
        for (char c : s) {
            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(currentNum);
                strStack.push(currentStr);
                currentNum = 0;
                currentStr = "";
            } else if (c == ']') {
                int repeatTimes = numStack.top();
                numStack.pop();
                string prevStr = strStack.top();
                strStack.pop();

                string temp = "";
                for (int i = 0; i < repeatTimes; i++) {
                    temp += currentStr;
                }
                currentStr = prevStr + temp;
            } else {
                currentStr += c;
            }
        }
        return currentStr;
    }
};