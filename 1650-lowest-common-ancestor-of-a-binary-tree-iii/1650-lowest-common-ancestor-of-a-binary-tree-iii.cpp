/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
        
        
     


    Node* lowestCommonAncestor(Node* p, Node * q) {
               unordered_set<Node*> s;

               Node* t=p;


               while(t !=NULL){

                     s.insert(t);

                     t=t->parent;


               }


               Node* a=q;

               Node* ans=NULL;


               while(a!=NULL){

                        if(s.count(a)){

                             ans=a;
                             break;
                        }
                        else{

                            a=a->parent;
                        }
               }


               return ans;

    }
};