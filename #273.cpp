/*============================================================
Problem: Integer to English Words
==============================================================
Convert a non-negative integer to its english words representation. 
Given input is guaranteed to be less than 2^31 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five 
Hundred Sixty Seven"

Hint:

Did you see a pattern in dividing the number into chunk of words? 
For example, 123 and 123000.
Group the number by thousands (3 digits). You can write a 
helper function that takes a number less than 1000 and convert 
just that chunk to words.
There are many edge cases. What are some good test cases? Does 
your code work with input such as 0? Or 1000010? (middle chunk 
is zero and should not be printed out)
============================================================*/
class Solution {
private:
    string helper(int num) {
    	const static char* less_ten[] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
    	const static char* less_twenty[] = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
   		const static char* less_hundred[] = {"", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};

    	string s; 

    	if (num != 0){
        	//get hundredth, tenth, and single digit
        	int hundred = num / 100;
        	num %= 100; 
        	int tenth = num / 10; 
        	int single = num % 10; 

        	if (hundred) s = s + less_ten[hundred] + " Hundred";

        	if (tenth) {
            	if (tenth == 1) {  //special handling, choose from less_twenty based on value of single
                	s += less_twenty[single];
                return s;
            	}
            	else  s += less_hundred[tenth];
        	}
        	if (single) s += less_ten[single];
    	}
    	return s;
	}
public:
	string numberToWords(int num) {
    	const static char* unit[] = {"", " Thousand", " Million", " Billion"};
    	int parts[4] = {0};
    	for (int i=0; i<4; i++) {
        	parts[i] = num % 1000;
        	num /= 1000; 
    	}
    	string s; 
    	for (int i=0; i<4; i++) {
        	if(parts[i] == 0) continue; 
        	s = helper(parts[i]) + unit[i] + s;  
    	}
    	s = s.size() ? s.substr(1) : "Zero";
    	return s;
	}
};