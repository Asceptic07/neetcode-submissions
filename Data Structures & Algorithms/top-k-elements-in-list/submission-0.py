class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        map={}
        for i in range(len(nums)):
            if nums[i] in map:
                map[nums[i]]+=1
            else:
                map[nums[i]]=1
        sorted_dict=dict(sorted(map.items(), key=lambda item: item[1],reverse=True))
        return list(sorted_dict.keys())[0:k]
        