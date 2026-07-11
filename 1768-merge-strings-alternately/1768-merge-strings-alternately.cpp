class Solution {
public:
    string mergeAlternately(string word1, string word2) {

                int w1=0;
                int w2=0;

                string ans="";


                int n1=word1.size();
                int n2=word2.size();

                while(w1<n1 && w2 <n2){

                       ans+=word1[w1];
                       ans+=word2[w2];

                       w1++;
                       w2++;

                }   



                while(w1<n1){
                     ans+=word1[w1];
                     w1++;
                }

                while(w2<n2){

                    ans+=word2[w2];

                    w2++;
                }


                return ans;
    }
};