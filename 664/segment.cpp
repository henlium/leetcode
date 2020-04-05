#include "common.h"

class Solution
{
public:
    vector<set<int>> pos;
    string str;
    int n;
    vector<vector<int>> record;
    int strangePrinter(string s)
    {
        str = clean(s);
        n = str.length();
        pos = vector<set<int>>(26);
        get_pos();
        for (int i = 0; i < n; ++i)
            record.push_back(vector<int>(n + 1, -1));
        for (int i = 0; i < n; ++i)
            record[i][i + 1] = 1;
        return recur(0, n, ' ');
    }

    string clean(string s)
    {
        string res;
        char last = ' ';
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != last)
                res.push_back(s[i]);
            last = s[i];
        }
        return res;
    }

    void get_pos()
    {
        for (int i = 0; i < n; ++i)
        {
            pos[str[i] - 'a'].insert(i);
        }
    }

    int recur(int start, int end, char outer)
    {
        if (start >= end) return 0;
        if (record[start][end] != -1)
            return record[start][end];
        int best = INT_MAX;
        int first_char = str[start] - 'a';
        auto pos_set = pos[first_char];
        for (auto it = pos_set.lower_bound(start); it != pos_set.end(); ++it)
        {
            int sec_start = *it+1;
            if (str[sec_start] == outer) ++sec_start;
            int res = 1 + recur(start+1, *it, str[start]) + recur(sec_start, end, outer);
            if (res < best) {
                best = res;
            }
        }
        record[start][end] = best;
        return best;
    }
};