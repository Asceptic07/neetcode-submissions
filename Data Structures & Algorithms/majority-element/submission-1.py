class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        map={}
        for i in range(len(nums)):
            if nums[i] in map:
                map[nums[i]]+=1
            else:
                map[nums[i]]=1
        max_freq=max(list(dict.values(map)))
        for ele,freq in dict.items(map):
            if freq==max_freq:
                return ele
                