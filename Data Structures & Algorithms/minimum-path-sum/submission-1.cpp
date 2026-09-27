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

    int solve3(int i,int j)
    {
        vector<vector<int>> dp(205,vector<int>(205,0));
        dp[m-1][n-1]=arr[m-1][n-1];
        for(int i=m-2;i>=0;i--)
        {
            dp[i][n-1]=arr[i][n-1]+dp[i+1][n-1];
        }
        for(int j=n-2;j>=0;j--)
        {
            dp[m-1][j]=arr[m-1][j]+dp[m-1][j+1];
        }
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                dp[i][j]=arr[i][j]+min(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[0][0];
    }

    

    int minPathSum(vector<vector<int>>& grid) {
        // arr=grid;
        // m=arr.size();
        // n=arr[0].size();
        // return solve(0,0);

        // arr=grid;
        // m=arr.size();
        // n=arr[0].size();
        // vector<vector<int>> dp(200,vector<int>(200,-1));
        // return solve2(0,0,dp);

        arr=grid;
        m=grid.size();
        n=grid[0].size();
        return solve3(0,0);
    }
};