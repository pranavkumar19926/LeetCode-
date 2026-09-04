class Solution:
    def isValid(self, s: str) -> bool:


        vec=[]

        for i in s:

             
            if not vec :

                vec.append(i)
            elif vec[-1]=='(' and i==')':


                vec.pop()
            elif vec[-1]=='{' and i=='}':
                vec.pop()

            elif vec[-1]=='[' and i==']':

                vec.pop()
            else:
                vec.append(i)                 
        

        if not vec :

            return True

        else :

            return False    
            



        