/*
Medium

464

437

Add to List

Share
You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.

To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.

For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.

Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.

 

Example 1:


Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
Output: true
Explanation: The allowed triangular patterns are shown on the right.
Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.
/*
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mapping;
        for (const string& s : allowed)
        {
            mapping[s.substr(0, 2)].push_back(s[2]);
        }

        return dfs(bottom, "", mapping);
    }
    
private:
    unordered_map<string, bool> memo;
    bool dfs(string bottom, string top, unordered_map<string, vector<char>>& mapping)
    {
        if (bottom.size() == 2 && top.size() == 1)
        {
            return true;
        }
        
        if (memo.count(bottom))
            return memo[bottom];
        
        if (bottom.size() - top.size() == 1)
        {
            bool result = dfs(top, "", mapping);
            memo[top] = result;
            return result;
        }
        
        string sub = bottom.substr(top.size(), 2);
        if (mapping.count(sub) == 0)
            return false;
        
        for (char c : mapping[sub])
        {
            bool result = dfs(bottom, top + c, mapping);
            if (result)
            {
                memo[bottom] = true;
                return true;
            }
                
        }
        
        memo[bottom] = false;
        return false;
    }
};
