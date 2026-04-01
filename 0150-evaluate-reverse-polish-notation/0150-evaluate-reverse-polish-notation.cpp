class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<string>st;
        for (int i=0; i<n; i++) {
            if (tokens[i]!="+" && tokens[i]!="*" && tokens[i]!="/" && tokens[i]!="-") st.push(tokens[i]);
            else {
                string val1,val2;
                val2=st.top();
                st.pop();
                val1=st.top();
                st.pop();
                if (tokens[i]=="+") st.push(to_string(stoi(val1)+stoi(val2)));
                else if (tokens[i]=="-")    st.push(to_string(stoi(val1)-stoi(val2)));
                else if (tokens[i]=="/" && val2!="0")    st.push(to_string(stoi(val1)/stoi(val2)));
                else if (tokens[i]=="*")    st.push(to_string(stoi(val1)*stoi(val2)));
            }
        }
        return stoi(st.top());
    }
};