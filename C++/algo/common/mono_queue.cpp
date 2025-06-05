#include <deque>
struct MonoQueue
{
    deque<int> q;
    deque<int> minQ;
    deque<int> maxQ;
    void push(int x)
    {
        q.push_back(x);
        while (!minQ.empty() && minQ.back() > x)
        {
            minQ.pop_back();
        }
        minQ.push_back(x);
        while (!maxQ.empty() && maxQ.back() < x)
        {
            maxQ.pop_back();
        }
        maxQ.push_back(x);
    }
    void pop()
    {
        if (q.empty())
            return;
        int x = q.front();
        q.pop_front();
        if (x == minQ.front())
        {
            minQ.pop_front();
        }
        if (x == maxQ.front())
        {
            maxQ.pop_front();
        }
    }
    int min() const
    {
        return minQ.empty() ? -1 : minQ.front();
    }
    int max() const
    {
        return maxQ.empty() ? -1 : maxQ.front();
    }
};