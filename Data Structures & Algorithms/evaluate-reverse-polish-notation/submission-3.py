class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st=[]
        for i in range(len(tokens)):
            if tokens[i] not in {"+","-","*","/"}:
                st.append(int(tokens[i]))
            else:
                n1=st.pop()
                n2=st.pop()
                if tokens[i]=="+":
                    st.append(n1+n2)
                elif tokens[i]=="-":
                    st.append(n2-n1)
                elif tokens[i]=="*":
                    st.append(n1*n2)
                elif tokens[i]=="/":
                    st.append(int(n2/n1))
        return int(st[-1])


        