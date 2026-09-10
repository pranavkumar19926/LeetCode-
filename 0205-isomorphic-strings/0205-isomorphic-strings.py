class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:

        ss = {}
        used = set()

        for i in range(len(s)):

            if s[i] in ss:
                if ss[s[i]] != t[i]:
                    return False

            else:
                if t[i] in used:
                    return False

                ss[s[i]] = t[i]
                used.add(t[i])

        return True