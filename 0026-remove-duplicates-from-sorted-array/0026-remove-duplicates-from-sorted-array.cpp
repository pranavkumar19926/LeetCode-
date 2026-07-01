class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        unordered_set<int> s;

        int f = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (!s.count(nums[i])) {
                s.insert(nums[i]);
                nums[f] = nums[i];   // Place unique element at the front
                f++;
                count++;
            }
        }

        return count;
    }
};