/*============================================================
Problem: Simplify Path
==============================================================
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple 
slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and 
return "/home/foo".
============================================================*/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathStack;
        int i=0, n=path.size();
        while (i<n) {
            while (path[i] == '/')
            	i++;
            string s = "";
            while (i<n && path[i] != '/')
                s += path[i++];
                    
            if (".." == s && !pathStack.empty())
                pathStack.pop();
            else if(s != "" && s != "." && s != "..")
                pathStack.push(s);
        }
            
        if(pathStack.empty())
            return "/";
        string s = "";    
        while (!pathStack.empty()) {
            s = "/" + pathStack.top() + s;
            pathStack.pop();
        }
        return s;
    }
};