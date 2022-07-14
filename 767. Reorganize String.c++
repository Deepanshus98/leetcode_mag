/*

Medium

4953

183

Add to List

Share
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
*/
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        int max = 0;
        char maxele =s[0];
        for(auto ele:mp){
            if(max< ele.second){
                max = ele.second;
                maxele =ele.first;
            }
        }
        if((max*2)-1> s.length()){
            return "";
        }
        int i = 0;
        while(mp[maxele]>0){
            s[i] = maxele;
            i+=2;
            mp[maxele]--;
        }
        for(auto ele:mp){
            while(ele.second > 0){
                if(i>=s.size())i=1;
                s[i] = ele.first;
                ele.second --;
                i+=2;
            }
        }
        return s;
    }
};
