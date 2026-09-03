class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:

        vec={}

        sz=len(ransomNote)

        for i in ransomNote:

            if i in vec:

                vec[i]+=1
            else:
                vec[i]=1
            


        for i in magazine:

            if sz==0:
                return True

            if i in vec and vec[i] > 0:

                sz-=1
                vec[i]-=1
            
        if sz == 0:
            return True
        else:

            return False    



       