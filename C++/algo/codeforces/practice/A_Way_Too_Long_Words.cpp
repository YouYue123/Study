#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int count;
    vector<string> words;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        string s;
        cin >> s;
        words.push_back(s);
    }
    for (int i = 0; i < count; i++)
    {
        if (words[i].length() <= 10)
        {
            cout << words[i] << endl;
        }
        else
        {
            cout << words[i][0] << words[i].size() - 2 << words[i][words[i].size() - 1] << endl;
        }
    }
    return 0;
}