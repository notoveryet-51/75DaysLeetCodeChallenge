class Solution {
public:
    int rain(vector<int>& height)  {
        int n=height.size();
        vector<int>leftMax(n),rightMax(n);
        leftMax[0]=height[0];
        rightMax[n-1]=height[n-1];
        for (int i=1; i<n; i++) {
            if (leftMax[i-1]<height[i])    leftMax[i]=(height[i]);
            else leftMax[i]=(leftMax[i-1]);
        }
        for (int i=n-2; i>=0; i--) {
            if (rightMax[i+1]<height[i])    rightMax[i]=(height[i]);
            else rightMax[i]=(rightMax[i+1]);
        }
        int trapped=0;
        for (int i=0; i<n; i++) {
            int calc=min(rightMax[i],leftMax[i])-height[i];
            if (calc>=0) trapped+=calc;
        }
        return trapped;
    }
    int trap(vector<int>& height) {
        int trapped=rain(height);
        return trapped;
    }
};