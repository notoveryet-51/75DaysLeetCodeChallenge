class Solution {
public:
    bool frequency(int a[], int b[]) {
        for (int i=0; i<26; i++)  {
            if (a[i]!=b[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int check[26] = {0};
        int hash[26] = {0};
        // frequency of s1
        for (int i = 0; i < s1.size(); i++)
            check[s1[i] - 'a']++;
        // first window
        for (int i = 0; i < s1.size(); i++)
            hash[s2[i] - 'a']++;
        int i = 0, j = s1.size();
        while (j < s2.size()) {
            if (frequency(check, hash)) return true;
            //moving the window
            hash[s2[j] - 'a']++;        // add new char
            hash[s2[i] - 'a']--;        // remove old char
            i++;
            j++;
        }
        return frequency(check, hash);   
    }
};