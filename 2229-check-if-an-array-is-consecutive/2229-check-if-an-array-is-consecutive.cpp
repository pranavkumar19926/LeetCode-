class Solution {
public:
    bool isConsecutive(vector<int>& nums) {

        
        unordered_map<int,bool> mp;

        int n=nums.size();
        int x=INT_MAX;

        for(int i=0 ; i<nums.size() ; i++){

            x=min(x , nums[i]);
        }
         int t=x+n-1 ;

         for(int i=x ; i<=t ; i++){

            mp[i]=false;
         }

       for(int i=0 ; i < nums.size() ; i++){
  
            mp[nums[i]]=true;
       }

       for(auto it=mp.begin() ; it!=mp.end() ; it++){

             if(it->second == false){

                return false;
             }
       }


       return true;

    }
};