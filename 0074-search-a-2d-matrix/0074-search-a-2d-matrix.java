class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n=matrix.length;
        int m=matrix[0].length;
        int si=m*n; int a=0;
        int[] res=new int[si];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                res[a]=matrix[i][j];
                a++;
            }
        }
        int high=si-1, low=0;
        while (low<=high)    {
            int mid=(high+low)/2;
            if (res[mid]>target)    high=mid-1;
            else if (res[mid]==target)  return true;
            else low=mid+1;
        }
        return false;
    }
}