class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result=[]
        map={}
        for i in range(len(strs)):
            idx=""
            sorted_idx="".join(sorted(strs[i]))
            if sorted_idx in map:
                map[sorted_idx].append(strs[i])
            else:
                map[sorted_idx]=[strs[i]]
            
        result=list(dict.values(map))
        return result

            


            

        