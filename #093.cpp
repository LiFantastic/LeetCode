/*============================================================
Problem: Restore IP Addresses
==============================================================
Given a string containing only digits, restore it by returning 
all possible valid IP address combinations.

For example:
Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
============================================================*/
class Solution {
private:
    vector<string> res;
    
    void restoreIp(string ip, string restored, int idx, int level) {
        if (level > 4) return;
        if (level==4 && idx==ip.length()) res.push_back(restored);

        for (int i=1; i<4; i++) {
            if (idx+i>ip.length()) break;
            string s = ip.substr(idx, i);
            if ((s[0]=='0' && s.size()>1) || (i==3 && atoi(s.c_str()) > 255)) continue;
            restoreIp(ip, restored+s+(level==3 ? "" : "."), idx+i, level+1);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        restoreIp(s, "", 0, 0);
        return res;    
    }
};

