class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
            
            sort(nums.begin() , nums.end());
               vector<int> ans;

            for(int i=1 ; i<nums.size() ; i++){

                 
                 if(nums[i]!=nums[i-1]+1 ){
                         
                         int val=nums[i-1]+1;
                         int end=nums[i];
                          
                         while(val!=end){
                               

                               ans.push_back(val);

                               val++;

                         }

                       

                 }
            }


            return ans;



    }
};