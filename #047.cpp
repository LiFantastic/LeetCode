/*============================================================
Problem: Permutations II
==============================================================
Given a collection of numbers that might contain duplicates, 
return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
============================================================*/
class Solution {
private:
    vector<bool> notUsed;
    vector<vector<int>> res;
    vector<int> tmp;

    void dfs(vector<int>& num) {
        if (tmp.size() == num.size()) {
            res.push_back(tmp);
            return;
        }
        for(int i=0; i<num.size(); i++) {
            if (notUsed[i]) {  // process only when notused
                if (i != 0 && num[i] == num[i-1] && notUsed[i-1])  
                    continue;
                // two same number, to use the current one, the previous one must be used
                
                notUsed[i] = false;
                tmp.push_back(num[i]);
                dfs(num);
                notUsed[i] = true;
                tmp.pop_back();
            }
        }
    }    
public:
    vector<vector<int> > permuteUnique(vector<int>& num) {
        sort(num.begin(), num.end());
        notUsed = vector<bool>(num.size(), true);
        dfs(num);
        return res;
    }
};