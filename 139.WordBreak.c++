/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
*/
class Solution {
public:
    bool recursiveSoln(int index,string &s,set<string>&dictionary,vector<int>&dp){
        if(index>=s.size()){
            return true;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        
        string part;
        
        for(int i=index;i<s.size();i++){
            part.push_back(s[i]);
            
            if(dictionary.find(part)!=dictionary.end()){//Word found
    
                if( recursiveSoln(i+1,s,dictionary,dp)){ //Checking for remaining string
                    return dp[index]=true; //found the way of partitioning
                }

            }
        }
        dp[index]=0; //Checked all possible ways but can't break into valid parts.
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>dictionary;
        for(auto &word:wordDict){
            dictionary.insert(word);
        }
        vector<int>dp(s.size(),-1);
        return recursiveSoln(0,s,dictionary,dp);
    }
};
