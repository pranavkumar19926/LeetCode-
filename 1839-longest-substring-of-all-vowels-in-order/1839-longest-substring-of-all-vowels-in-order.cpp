class Solution {
public:
    int longestBeautifulSubstring(string word) {

        int n = word.size();
        int start = 0;
        int end = 0;
        int ans = 0;

        while (start < n) {

            // Find next 'a'
            while (start < n && word[start] != 'a')
                start++;

            if (start == n)
                break;

            end = start;

            int state = 0; // 0->a, 1->e, 2->i, 3->o, 4->u

            while (end + 1 < n) {

                if (word[end + 1] == word[end]) {
                    end++;
                }
                else if (state == 0 && word[end + 1] == 'e') {
                    state++;
                    end++;
                }
                else if (state == 1 && word[end + 1] == 'i') {
                    state++;
                    end++;
                }
                else if (state == 2 && word[end + 1] == 'o') {
                    state++;
                    end++;
                }
                else if (state == 3 && word[end + 1] == 'u') {
                    state++;
                    end++;
                }
                else {
                    break;
                }
            }

            if (state == 4) {
                ans = max(ans, end - start + 1);
            }

            start = end + 1;
        }

        return ans;
    }
};