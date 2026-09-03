class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:

        ans = []

        if len(nums) == 0:
            return ans

        st = 0
        s = 0
        f = 1

        while f < len(nums):

            if nums[f] - nums[s] == 1:

                f += 1
                s += 1

            else:

                if st == s:
                    c = ""
                    c += str(nums[st])
                    ans.append(c)

                else:
                    c = ""
                    c += str(nums[st])
                    c += "->"
                    c += str(nums[s])
                    ans.append(c)

                st = f
                s = f
                f += 1

        
        if st == s:
            c = ""
            c += str(nums[st])
            ans.append(c)
        else:
            c = ""
            c += str(nums[st])
            c += "->"
            c += str(nums[s])
            ans.append(c)

        return ans