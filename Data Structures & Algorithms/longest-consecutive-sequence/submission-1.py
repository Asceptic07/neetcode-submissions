class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        ans=1
        res=1
        nums=sorted(nums)
        for i in range(len(nums)-1):
            if nums[i+1]==nums[i]:
                continue
            if nums[i+1]-nums[i]==1:
                res+=1
            else:
                res=1
            ans=max(res,ans)
        return ans