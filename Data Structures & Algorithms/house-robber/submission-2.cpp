class Solution {
public:
    vector<int> dp;
    int helper(vector<int> &nums,int i)
    {
        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2) return max(nums[i],nums[i+1]);
        return max(nums[i]+helper(nums,i+2),0+helper(nums,i+1));
    }

    int helper2(vector<int> &nums,int i)
    {
        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2) return max(nums[i],nums[i+1]);

        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+helper(nums,i+2),0+helper(nums,i+1));        
    }

    int helper3(vector<int> &nums)
    {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        dp.clear();
        dp.resize(n);
        dp[n-1]=nums[n-1];
        dp[n-2]=max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>=0;i--)
        {
            dp[i]=max(nums[i]+dp[i+2],0+dp[i+1]);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        // return helper(nums,0);

        // dp.clear();
        // dp.resize(101,-1);  //Max length possible for dp array: 100 (in the code constraints)
        // return helper2(nums,0);

        return helper3(nums);
    }
};
