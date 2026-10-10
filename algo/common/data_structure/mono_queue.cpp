#include <deque>
using namespace std;
// https://oi-wiki.org/ds/monotonous-queue/
template<typename F>
concept Predicate = requires(F f, int a, int b) {
    { f(a, b) } -> convertible_to<bool>;
};
template<Predicate PushComp, Predicate PopComp>
struct MonoQueue {
    deque<int> q;
    PushComp push_cmp;
    PopComp pop_cmp;
    
    MonoQueue(PushComp push_comp, PopComp pop_comp)
        : push_cmp(push_comp),pop_cmp(pop_comp) {}

    void push(int idx) {
        while(!q.empty() && push_cmp(q.back(), idx)) q.pop_back();
        q.push_back(idx);
    }

    void pop_if_needed(int idx) {
        if(!q.empty() && pop_cmp(q.front(), idx)) {
            q.pop_front();
        }
    }
    int front() {
        return q.front();
    }
};