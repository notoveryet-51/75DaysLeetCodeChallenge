class Solution {
public:
    bool isPalindrome(string s) {
        for (int i=0; i<s.size(); i++)  s[i]=tolower(s[i]);
        string emp="";
        for (int i=0; i<s.size(); i++) if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) emp+=s[i];
        string comp=emp;
        reverse(emp.begin(),emp.end());
        if (comp==emp) return true;
        return false;
    }
};