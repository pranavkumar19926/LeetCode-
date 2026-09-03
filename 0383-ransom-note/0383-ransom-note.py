class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:

        ransomNote = ''.join(sorted(ransomNote))
        magazine = ''.join(sorted(magazine))

        sz = len(ransomNote)
        first = 0

        for i in magazine:

            if first >= sz:
                break

            if ransomNote[first] == i:
                first += 1

        if first >= sz:
            return True
        else:
            return False