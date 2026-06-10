class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n = intervals.size();
        if(n == 0) return result;
        sort(intervals.begin(), intervals.end());
        vector<int> v = intervals[0];
        for(int i = 1; i < n; i++) {
            if(v[1] >= intervals[i][0]) {
                v[1] = max(v[1], intervals[i][1]);
            } else {
                result.push_back(v);
                v = intervals[i];
            }
        }
        result.push_back(v);
        return result;
    }
};
