
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = s.size() - 1;

        while (i >= 0) {
            if (i >= 0 && !isspace(s[i])) {
                string add = "";

                while (i >= 0 && !isspace(s[i])) {
                    add += s[i];
                    i--;
                }

                reverse(add.begin(), add.end());

                if (!ans.empty()) {
                    ans += " ";
                }

                ans += add;
            } else {
                i--;
            }
        }

        return ans;
    }
};
