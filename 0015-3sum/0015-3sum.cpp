class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int val = nums[i];
            int t = -val;

            int start = i + 1;
            int end = n;

            while (start < end) {

                int v = nums[start] + nums[end];

                if (v == t) {

                    vector<int> add;
                    add.push_back(val);
                    add.push_back(nums[start]);
                    add.push_back(nums[end]);

                    ans.push_back(add);

                    start++;
                    end--;

                    while (start < end && nums[start] == nums[start - 1])
                        start++;

                    while (start < end && nums[end] == nums[end + 1])
                        end--;
                }
                else if (v > t) {

                    end--;
                }
                else {

                    start++;
                }
            }
        }

        return ans;
    }
};