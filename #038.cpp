/*============================================================
Problem: Count and Say
==============================================================
The count-and-say sequence is the sequence of integers 
beginning as follows:

1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
============================================================*/
class Solution {
private:
    string revolution(string s) {
		string res;
		char pre =s[0];
		int count = 1;
		for (int i=1; i<s.size(); i++) {
			if (s[i]==pre)
				count ++;
			else {
				char tmp =  count+'0';
				res = res + tmp + pre;
				pre = s[i];
				count = 1;
			}
		}
		char tmp =  count+'0';
		res = res + tmp + pre;
		return res;
	}
public:
    string countAndSay(int n) {
		string res = "1";
		int j = 1;
		while (j<n) {
			res = revolution(res);
			j++;
		}
		return res;
    }
};