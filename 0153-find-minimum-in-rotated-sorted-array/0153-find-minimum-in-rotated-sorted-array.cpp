
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Min is to the right
                left = mid + 1;
            } else {
                // Min is at mid or to the left
                right = mid;
            }
        }

        return nums[left];  // left == right is the min
    }
};
