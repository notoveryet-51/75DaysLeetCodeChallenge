class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if (n==0)   return 0;
        int hash[128]={0};
        int i=0,j=0;
        int len=0;
        while (j<n) {
            hash[s[j]]++;
            while (hash[s[j]]>1)   {
                hash[s[i]]--;   i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};