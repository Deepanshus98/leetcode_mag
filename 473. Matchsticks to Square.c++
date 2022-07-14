
/*

3066

237

Add to List

Share
You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

 

Example 1:


Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:

Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: You cannot find a way to form a square with all the matchsticks.
*/
class Solution {
public:
    bool recur(vector<int>& matchsticks,int i,int target,int sum1,int sum2,int sum3,int sum4)
    {
        if(sum1>target || sum2>target || sum3>target ||sum4>target )
            return false;
        if(i==-1)
        {
            if(sum1==target && sum2==target && sum3==target && sum4==target)
                return true;
            else
                return false;
        }
        return 
    recur(matchsticks,i-1,target,sum1+matchsticks[i],sum2,sum3,sum4)||
    recur(matchsticks,i-1,target,sum1,sum2+matchsticks[i],sum3,sum4)||
    recur(matchsticks,i-1,target,sum1,sum2,sum3+matchsticks[i],sum4)||
    recur(matchsticks,i-1,target,sum1,sum2,sum3,sum4+matchsticks[i]);

    }
    bool makesquare(vector<int>& matchsticks) 
    {
        int si = matchsticks.size();
        int sum = 0;
        for(int i=0;i<si;i++)
        {
            sum = sum+matchsticks[i];
        }
        if(sum%4!=0 || si<4 )
            return false;

        int sum1=0,sum2=0,sum3=0,sum4=0;

        int target  = sum/4;
        sort(matchsticks.begin(),matchsticks.end());
       return recur(matchsticks,si-1,target,sum1,sum2,sum3,sum4);

    }
    };
