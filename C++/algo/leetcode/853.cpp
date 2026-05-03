// 853. Car Fleet [M]
// LeetCode car-fleet

struct Car {
    int pos;
    int speed;
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        assert(position.size() == speed.size());
        vector<Car> cars;
        for(int i = 0 ; i < n; i ++) {
            int p = position[i], s = speed[i];
            cars.emplace_back(p, s);
        }
        sort(cars.begin(), cars.end(), [&] (auto& c1, auto& c2) {
            return c1.pos < c2.pos;
        });
        // return true, if car b can catch car a 
        auto canCatch = [&] (Car& a, Car b) -> bool {
            if(a.speed >= b.speed) return false;
            return 1LL * (target - a.pos) *  b.speed >= 1LL * (target - b.pos) * a.speed;
        };
        stack<Car> st;
        for(int i = 0; i < n; i ++) {
            auto car = cars[i];
            while(!st.empty() && canCatch(car, st.top())) {
                st.pop();
            }
            st.push(car);
        }
        return st.size();
    }
};