class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        hash_map={}
        for i in range(len(numbers)):
            hash_map[numbers[i]]=i
        for i in range(len(numbers)):
            d=target-numbers[i]
            if d in hash_map and hash_map[d]!=i:
                return [i+1,hash_map[d]+1]
        return []
