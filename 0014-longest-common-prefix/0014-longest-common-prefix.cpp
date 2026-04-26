class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string str="";
        sort(strs.begin(),strs.end());
        //comparing the first and the last string only
        int len=max(strs[0].size(),strs[n-1].size());
        for (int i=0; i<len; i++){
            if (strs[0][i]==strs[n-1][i])   str+=strs[0][i];
            else break;
        }
        return str;
    }
};