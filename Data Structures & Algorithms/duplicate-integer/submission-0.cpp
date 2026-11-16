class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mat;
        for(int i:nums)
        {
            mat[i]++;
            if(mat[i]>1) return true;
        }
        return false;
    }
    
};