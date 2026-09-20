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

    int helper3(int sr,int sc,int er,int ec)
    {
        if(sr==er && sc==ec) return 1;
        vector<vector<int>> dp(er+1,vector<int>(ec+1));
        for(int i=0;i<er+1;i++)
        {
            dp[i][0]=1;
        }
        for(int i=0;i<ec+1;i++)
        {
            dp[0][i]=1;
        }
        for(int i=1;i<er+1;i++)
        {
            for(int j=1;j<ec+1;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[er][ec];
    }

    int uniquePaths(int m, int n) {
        //return helper(0,0,m-1,n-1);

        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return helper2(0,0,m-1,n-1,dp);

        return helper3(0,0,m-1,n-1);
    }
};