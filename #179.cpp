/*============================================================
Problem: Largest Number
==============================================================
Given a list of non negative integers, arrange them such that 
they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number 
is 9534330.

Note: The result may be very large, so you need to return a 
string instead of an integer.
============================================================*/
class Solution {
private:
    static bool cmp(const string& s1, const string& s2) {
        return (s1+s2) > (s2+s1);
    }
public:   
    string largestNumber(vector<int>& num) {
        vector<string> numString(num.size());
        for (int i=0; i<num.size(); i++)
            numString[i] = to_string(num[i]);
        sort(numString.begin(), numString.end(), cmp);
        string res;
        bool first = true;
        for (int i=0; i<numString.size(); i++) {
            if (numString[i] != "0") {
                res += numString[i];
                first = false;
            } 
            else if (!first)  // add '0' only when not to the begin
                res += numString[i];
        }
        if (first) res.push_back('0');
        return res;
    }
};