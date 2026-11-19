class Solution {
public:
    int maximumLengthSubstring(string s) {
        int start = 0;
        int end = 0;
        int ans = 0;
        int n = s.size();

        unordered_map<char, int> ch;

        while (end < n) {

            char c = s[end];

            
            ch[c]++;

                while (ch[c] > 2) {
                ch[s[start]]--;
                start++;
            }

            
            ans = max(ans, end - start + 1);

            end++;
        }

        return ans;
    }
};