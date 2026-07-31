class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> ans;

            vector<vector<int>> bucket(nums.size()+1 );
            unordered_map<int,int> mp;

            for(int i=0 ; i<nums.size() ; i++){

                mp[nums[i]]++;
            } 


            for(auto it=mp.begin() ; it!=mp.end() ; it++){


                   bucket[it->second].push_back(it->first);
            }


            for(int i=bucket.size()-1 ; i>=0 ; i--){

                           bool va=false;

                      for(int j=0 ; j<bucket[i].size() ; j++){
                                    
                                    if(k<=0){

                                        va=true;
                                        break;
                                    }

                                   int val=bucket[i][j];

                                   ans.push_back(val );


                                   k--;


                      }

                      if(va==true){

                        break;
                      }

            }


            return ans;  
    }
};