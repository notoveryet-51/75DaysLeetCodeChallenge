class Solution {
public:
    bool checkValidity(vector<int>arr, int a, int b) {
        long long sum=0;
        for (int i=0; i<arr.size(); i++) sum+=ceil(double(arr[i])/a);
        return (sum<=b);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size(), mx=INT_MIN;
        for (int i=0; i<n; i++) mx=max(piles[i],mx);
        int low=1, high=mx;
        while (low<=high) {
            int mid=(low+high)/2;
            if (checkValidity(piles,mid,h)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};