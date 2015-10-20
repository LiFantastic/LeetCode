/*============================================================
Problem: Fraction to Recurring Decimal
==============================================================
Given two integers representing the numerator and denominator 
of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part 
in parentheses.

For example,
Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
============================================================*/
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string res = "";
		if (numerator==0) return "0";
		if (denominator==0) return res;

		long n = numerator;
		long d = denominator;
		if ((n < 0 && d > 0) || (n > 0 && d < 0))
			res = "-";
		if (n < 0) n = -n;
		if (d < 0) d = -d;
		res += to_string(n/d);
		n = n%d;
		if (n == 0) return res;
		res += '.';  // integer part

		int pos = res.size();
		map<long, int> record;
		while (n != 0) {
			if (record.find(n) != record.end()) {
				res.insert(res.begin() + record[n], '(');
				res += ')';
				return res;
			}
			record[n] = pos;
			res += char(n*10/d+'0');
			pos++;
			n = (n*10)%d;
		}
		return res;
	}
};