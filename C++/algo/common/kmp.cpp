#include <vector>
#include <ranges>
using namespace std;
struct KMP
{
    vector<int> calcPi(const string &p)
    {
        vector<int> pi(p.size());
        int match = 0;
        for (int i = 1; i < p.size(); i++)
        {
            char v = p[i];
            while (match > 0 && p[match] != v)
            {
                match = pi[match - 1];
            }
            if (p[match] == v)
            {
                match++;
            }
            pi[i] = match;
        }
        return pi;
    }
    vector<int> kmp(const string &s, const string &p)
    {
        if (p.empty())
        {
            vector<int> pos(s.size() + 1);
            for (int i = 0; i <= s.size(); i++) {
                pos[i] = i;
            }
            return pos;
        }
        vector<int> pi = calcPi(p);
        vector<int> pos;
        int match = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char v = s[i];
            while (match > 0 && p[match] != v)
                match = pi[match - 1];
            if (p[match] == v)
                match += 1;
            if (match == p.size())
            {
                pos.push_back(i - p.size() + 1);
                match = pi[match - 1];
            }
        }
        return pos;
    }
};