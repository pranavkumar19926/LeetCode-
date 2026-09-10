class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:

        start=0
        end=len(numbers)-1
        ans=[]



        while start<=end:

            val=numbers[start]+numbers[end]

            if val==target:
                ans.append(start+1)
                ans.append(end+1)
                break

            elif val > target:
                end-=1

            else:
                start+=1


        return ans            

        