class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
              int n=capacity.size();
             vector<int> ans(n,-1);

             for(int i=0 ; i<n ; i++){

                    int val = capacity[i]-rocks[i];

                    ans[i]=val;
             }

             sort(ans.begin() , ans.end());

              int count=0;

              bool found=false;

             for(int i=0 ; i<ans.size() ; i++){
                      
                      if(ans[i]==0){

                        count++;
                      }
                      else{
                            
                            if(ans[i] > additionalRocks){
                                     
                                     found=true;

                            }
                            else{

                                additionalRocks-=ans[i];

                                count++;


                            }



                      }

                      if(found){

                        break;
                      }
                    
             }


             return count;
    }
};