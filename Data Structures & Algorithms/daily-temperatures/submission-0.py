class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        result=[0]*len(temperatures)
        stack=[0]
        for i in range(1,len(temperatures)):
            while stack and temperatures[i]>temperatures[stack[-1]]:
                idx=stack.pop()
                result[idx]=i-idx
            stack.append(i)
        return result