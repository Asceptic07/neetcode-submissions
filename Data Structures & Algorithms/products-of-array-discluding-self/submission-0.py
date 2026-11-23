class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        arr_prod=1
        zero_count=0
        for i in range(len(nums)):
            if nums[i]!=0:
                arr_prod*=nums[i]
            else:
                zero_count+=1
        if zero_count>1:
            return [0]*len(nums)
        elif zero_count==1:
            result=[]
            for i in range(len(nums)):
                if nums[i]!=0:
                    result.append(0)
                else:
                    result.append(arr_prod)
            return result
        else:
            result=[]
            for i in range(len(nums)):
                result.append(arr_prod//nums[i])
            return result
        

        