class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len=tasks.size();
        int maxFreq=INT_MIN, totalMaxFreq=0;
        unordered_map<char,int>mpp;
        for (auto it: tasks) {
            mpp[it]++;
            if (mpp[it]>maxFreq) {
                maxFreq=mpp[it];
            }
        }
        for (auto it: mpp) {
            if (it.second==maxFreq) totalMaxFreq++;
        }
        return max(len,(maxFreq-1)*(n+1)+totalMaxFreq);
    }
};