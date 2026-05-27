class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n==1 && trust.empty()) return 1;
        int len=trust.size();
        bool check=true;
        unordered_map<int,int>freq;
        for (int i=0; i<len; i++) {
            freq[trust[i][1]]++;
        }
        int maxFreq=INT_MIN, judge=0;
        for (auto it: freq) {
            if(it.second>maxFreq) {
                maxFreq=it.second;
                judge=it.first;
            }
        }
        for (int i=0; i<len; i++) {
            if (judge==trust[i][0]) check=false;
        }
        if (maxFreq==n-1 && check) return judge;
        else return -1;
    }
};