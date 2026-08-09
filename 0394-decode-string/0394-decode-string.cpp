class Solution {
public:
    string decodeString(string s) {

        stack<char> st;
        stack<string> num;

        string n = "";

        for(int i = 0; i < s.size(); i++){

            char c = s[i];

            if(c >= '0' && c <= '9'){

                n += c;
            }

            else if(c == '['){

                if(n != ""){
                    num.push(n);
                    n = "";
                }

                st.push(c);
            }

            else if(c >= 'a' && c <= 'z'){

                st.push(c);
            }

            else{

                string ch = "";

                while(!st.empty() && st.top() != '['){

                    ch += st.top();
                    st.pop();
                }

                reverse(ch.begin(), ch.end());

                if(!st.empty()){
                    st.pop();
                }

                string nu = num.top();
                num.pop();

                int numm = 0;

                for(int i = 0; i < nu.size(); i++){

                    numm = numm * 10 + (nu[i] - '0');
                }

                numm = numm - 1;

                string temp = ch;

                while(numm != 0){

                    ch += temp;
                    numm--;
                }

                for(int i = 0; i < ch.size(); i++){

                    st.push(ch[i]);
                }
            }
        }

        string ans = "";

        while(!st.empty()){

            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};