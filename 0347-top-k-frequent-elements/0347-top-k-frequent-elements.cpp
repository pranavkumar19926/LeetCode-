class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
                  
                  priority_queue<pair<int,int> > pq;

                        unordered_map<int,int> mp;

                  for(int i=0 ; i<nums.size() ; i++){
                            mp[nums[i]]++;
                  }

                   for(auto it=mp.begin() ; it!=mp.end() ; it++){
                               

                               pq.push(make_pair(it->second , it->first ));


                   }


                      vector<int> ans;

                  while(!pq.empty() && k!=0){


                            int count=pq.top().first;

                            int val=pq.top().second;

                              pq.pop();

                            ans.push_back(val);        

                             k--;
                  }



                  return ans;


    }
};