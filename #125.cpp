/*============================================================
Problem: Valid Palindrome
==============================================================
Given a string, determine if it is a palindrome, considering 
only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
For the purpose of this problem, we define empty string as 
valid palindrome.
============================================================*/
class Solution {
private:
    int char2int (char c) {
        if ((c>='a' && c<='z') || (c>='0' && c<='9')) return c;
        else if (c>='A' && c<='Z') return c-'A'+'a';
        else return -1;
    }
    
public:
    bool isPalindrome(string s) {
        int n = s.size();
        
        if (n==0) return true;
            
        int l=0, r=n-1, leftInt, rightInt;
        
        while (l<r) {
            leftInt = char2int(s[l]);
            if (leftInt==-1) {
                l++;
                continue;
            }
            rightInt = char2int(s[r]);
            if (rightInt==-1) {
                r--;
                continue;
            }
            if (leftInt==rightInt) {
                l++;
                r--;
                continue;
            }
            return false;
        }
        return true;
    }
};