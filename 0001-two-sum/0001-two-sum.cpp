#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.count(complement)) {
                return {map[complement], i}; // Return 0-based indices
            }
            map[nums[i]] = i;
        }

        return {}; // Should not happen if one solution is guaranteed
    }
};
