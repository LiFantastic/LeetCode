/*============================================================
Problem: Multiply Strings
==============================================================
Given two numbers represented as strings, return multiplication 
of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
============================================================*/
class Solution {
public:
    string multiply(string num1, string num2) {
		if(num1=="0" || num2=="0") return "0";
		int l1 = num1.length(), l2 = num2.length();
		vector<int> n1(l1);
		vector<int> n2(l2);
		vector<int> n3(l1+l2, 0);
		for (int i=0; i<l1; i++)
			n1[i] = num1[i]-'0';
		for (int i=0; i<l2; i++)
			n2[i] = num2[i]-'0';
		
		for (int i=0; i<l1; i++)
			for (int j=0; j<l2; j++)
				n3[i+j+1] += n1[i]*n2[j];

		string res = "";
		for (int k=l1+l2-1; k>=0; k--){
			if (k>0) n3[k-1] += n3[k]/10;
			n3[k] %= 10;
			res = char(n3[k]+'0') + res;
		}
		res = res[0]=='0' ? res.substr(1):res;
		return res;
	}
};