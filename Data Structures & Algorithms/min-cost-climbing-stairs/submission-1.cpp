class Solution {
public:
    int helper(vector<int> &cost,int i)
    {
        if(i==0 || i==1) return cost[i]; 
        return cost[i]+min(helper(cost,i-1),helper(cost,i-2));
    }

    int helper2(vector<int> &cost,int i,vector<int> &dp)
    {
        if(i==0 || i==1) return cost[i];
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        return dp[i]=cost[i]+min(helper2(cost,i-1,dp),helper2(cost,i-2,dp));
    }

    int helper3(vector<int> &cost)
    {
        int n=cost.size();
        for(int i=2;i<n;i++)
        {
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
    }

    int minCostClimbingStairs(vector<int>& cost) 
    {
        //int n=cost.size();
        //return min(helper(cost,n-1),helper(cost,n-2));
        
        //vector<int> dp(n,-1);
        //return min(helper2(cost,n-1,dp),helper2(cost,n-2,dp));
        
        return helper3(cost);
    }
};
