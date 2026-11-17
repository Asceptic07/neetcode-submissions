class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="+")
            {
                int n1=s.top();
                s.pop();
                int n2=s.top();
                s.pop();
                s.push(n2);
                s.push(n1);
                s.push(n1+n2);
            }
            else if(operations[i]=="D")
            {
                s.push(2*(s.top()));
            }
            else if(operations[i]=="C")
            {
                s.pop();
            }
            else
            {
                s.push(stoi(operations[i]));
            }
        }
        int ans=0;
        while(s.size()>0)
        {
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};