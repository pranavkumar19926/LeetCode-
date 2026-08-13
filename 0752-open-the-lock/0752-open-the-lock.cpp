class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> visited;

        for(int i = 0; i < deadends.size(); i++) {

            visited.insert(deadends[i]);
        }

        if(visited.count("0000")) {

            return -1;
        }

        queue<pair<string, int>> q;

        q.push(make_pair("0000", 0));

        visited.insert("0000");

        while(!q.empty()) {

            string cha = q.front().first;
            int val = q.front().second;

            q.pop();

            if(cha == target) {

                return val;
            }


            
            for(int i = 0; i < 4; i++) {

                string ch = cha;

                int temp = ch[i] - '0';

                if(temp == 9) {

                    temp = 0;
                }
                else {

                    temp++;
                }

                char add = temp + '0';

                ch[i] = add;

                if(!visited.count(ch)) {

                    visited.insert(ch);

                    q.push(make_pair(ch, val + 1));
                }
            }


            
            for(int i = 0; i < 4; i++) {

                string ch = cha;

                int temp = ch[i] - '0';

                if(temp == 0) {

                    temp = 9;
                }
                else {

                    temp--;
                }

                char add = temp + '0';

                ch[i] = add;

                if(!visited.count(ch)) {

                    visited.insert(ch);

                    q.push(make_pair(ch, val + 1));
                }
            }
        }

        return -1;
    }
};