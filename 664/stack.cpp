#include "common.h"

class Solution {
public:
    int strangePrinter(string s) {
        s = clean(s);
        return recur(s, string());
    }
    
    string clean(string s) {
        string res;
        char last = ' ';
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != last) res.push_back(s[i]);
            last = s[i];
        }
        return res;
    }
    
    int recur(string s, string stk) {
        if (s.length() == 0) 
            return stk.length();
        int res = INT_MAX;
        if (stk.length() > 0 && stk.back() == s.front()) {
            //middle
            res = min(res, recur(s.substr(1, s.length()-1), stk));
            if (s.length() == 1 || s[1] != stk.back()) {
                //tail
                stk.pop_back();
                res = min(res, 1 + recur(s.substr(1, s.length()-1), stk));
                stk.push_back(s.front());
            }
        } else {
        // head
            stk.push_back(s.front());
            res = min(res, recur(s.substr(1, s.length()-1), stk));
            stk.pop_back();
        // head and tail
            res = min(res, 1 + recur(s.substr(1, s.length()-1), stk));
        }
        return res;
    }
};