/*

Medium

3871

191

Add to List

Share
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
    vector<int>c;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(ch=='-' || ch=='+' || ch=='*'){
            string c1 = s.substr(0,i);
            string c2 = s.substr(i+1);
            vector<int>v1 = diffWaysToCompute(c1);
            vector<int>v2 = diffWaysToCompute(c2);
            for(auto x:v1){
                for(auto y:v2){
                    if(ch=='-'){
                        c.push_back(x-y);
                    }else if(ch=='+'){
                        c.push_back(x+y);
                    }else if(ch=='*'){
                        c.push_back(x*y);
                    }
                }
            }
        }
    }
    if(c.size()==0) c.push_back(stoi(s));

    return c;
}
};
