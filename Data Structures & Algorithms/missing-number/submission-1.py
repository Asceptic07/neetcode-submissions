class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)
        map={}
        for i in range(0,n+1):
            map[i]=0
        for i in nums:
            map[i]=1
        for key,val in dict.items(map):
            if val==0:
                return key
        return 0
        