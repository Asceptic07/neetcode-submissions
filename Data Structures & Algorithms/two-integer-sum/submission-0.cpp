class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mat;
        for(int i=0;i<nums.size();i++)
        {
            mat[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            int d=target-nums[i];
            if(mat.find(d)!=mat.end() && i!=mat[d])
            {
                return {i,mat[d]};
            }
        }
        return {};
    }
};
