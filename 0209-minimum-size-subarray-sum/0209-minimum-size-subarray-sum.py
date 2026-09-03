class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:

        first = 0
        second = 0
        ans = float('inf')
        curr_sum = 0

        while second < len(nums):

            curr_sum += nums[second]
            second += 1

            while curr_sum >= target:
                ans = min(ans, second - first)

                curr_sum -= nums[first]
                first += 1

        if ans != float('inf'):
            return ans
        else:
            return 0