/*

Medium

2998

105

Add to List

Share
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

 

Example 1:

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation: 
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
*/
class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
        unordered_map<string,int> m;
        for(auto p:deadends)
            m[p]++;
        
        if(m.find("0000")!=m.end()) 
            return -1;
        
        queue<string> q;
        q.push("0000");
        unordered_map<string,int> vis;
        int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                string temp=q.front();
                q.pop();
                
                if(target==temp && m.find(temp)==m.end())
                    return ans;
                
                for(int j=0;j<4;j++) 
                {
                    for(int diff:{1,9}) 
                    {
                        string s=temp;
                        s[j]=(s[j]-'0'+diff)%10+'0';
                        
                        if (m.find(s)==m.end() && vis.find(s)==m.end()) 
                            q.push(s);
                        
                        vis[s]++;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
