class Solution {
public:
    int helper(int sc,int sr,int ec,int er)
    {
        if(sr==er && sc==ec) return 1;
        if(sr>er || sc>ec) return 0;
        return helper(sc+1,sr,ec,er)+helper(sc,sr+1,ec,er);
    }

    int helper2(int sr,int sc,int er,int ec,vector<vector<int>> &dp)
    {
        if(sr==er && sc==ec) return 1;
        if(sr>er || sc>ec) return 0;
        if(dp[sr][sc]!=-1) return dp[sr][sc];
        return dp[sr][sc]=helper2(sr,sc+1,er,ec,dp)+helper2(sr+1,sc,er,ec,dp);
    }

    int helper3(int m,int n)
    {
        int dp[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePaths(int m, int n) {
        //return helper(0,0,m-1,n-1);

        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return helper2(0,0,m-1,n-1,dp);

        return helper3(m,n);
    }
};