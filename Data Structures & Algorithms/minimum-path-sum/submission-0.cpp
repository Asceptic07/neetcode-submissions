class Solution {
public:
    vector<vector<int>> arr;
    int n,m;

    int solve(int i,int j)
    {
        if(i==m-1 && j==n-1) return arr[m-1][n-1];
        if(i>=m || j>=n || i<0 || j<0) return INT_MAX;
        return arr[i][j]+min(solve(i,j+1),solve(i+1,j));
    }

    int solve2(int i,int j,vector<vector<int>> &dp)
    {
        if(i==m-1 && j==n-1) return arr[m-1][n-1];
        if(i>=m || j>=n || i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=arr[i][j]+min(solve2(i,j+1,dp),solve2(i+1,j,dp));
    }

    

    int minPathSum(vector<vector<int>>& grid) {
        // arr=grid;
        // m=arr.size();
        // n=arr[0].size();
        // return solve(0,0);

        arr=grid;
        m=arr.size();
        n=arr[0].size();
        vector<vector<int>> dp(200,vector<int>(200,-1));
        return solve2(0,0,dp);
    }
};