#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<ll, ll>;
struct Point {
    ll x, y;
};

ll cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
bool isInPoly(Point p, const vector<Point>& poly) {
    int n = poly.size();
    bool inside = false;
    for (int i = 0; i < n; i++) {
        Point p1 = poly[i];
        Point p2 = poly[(i + 1) % n];        
        if ((p1.y > p.y) != (p2.y > p.y)) {
            ll lhs = (p2.x - p1.x) * (p.y - p1.y);
            ll rhs = (p.x - p1.x) * (p2.y - p1.y);
            if (p2.y > p1.y) {
                if (lhs > rhs) inside = !inside;
            } else {
                if (lhs < rhs) inside = !inside;
            }
        }
    }
    return inside;
}
bool isStrictlyIntersect(Point a, Point b, Point c, Point d) {
    auto cp1 = cross_product(a, b, c);
    auto cp2 = cross_product(a, b, d);
    auto cp3 = cross_product(c, d, a);
    auto cp4 = cross_product(c, d, b);

    if (((cp1 > 0 && cp2 < 0) || (cp1 < 0 && cp2 > 0)) &&
        ((cp3 > 0 && cp4 < 0) || (cp3 < 0 && cp4 > 0))) {
        return true;
    }
    return false;
}
bool isValid(Point p1, Point p2, const vector<Point>& poly) {
    ll x1 = min(p1.x, p2.x);
    ll x2 = max(p1.x, p2.x);
    ll y1 = min(p1.y, p2.y);
    ll y2 = max(p1.y, p2.y);
    Point A = {x1, y1};
    Point B = {x2, y1};
    Point C = {x2, y2};
    Point D = {x1, y2};
    if (isInPoly(A, poly) == false) return false;
    if (isInPoly(B, poly) == false) return false;
    if (isInPoly(C, poly) == false) return false;
    if (isInPoly(D, poly) == false) return false;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        Point u = poly[i];
        Point v = poly[(i + 1) % n];
        if (isStrictlyIntersect(u, v, A, B)) return false;
        if (isStrictlyIntersect(u, v, B, C)) return false;
        if (isStrictlyIntersect(u, v, C, D)) return false;
        if (isStrictlyIntersect(u, v, D, A)) return false;
        if (u.x > x1 && u.x < x2 && u.y > y1 && u.y < y2) return false;
    }
    return true;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<Point> points;
    string line;
    while(getline(cin, line)) {
        if (line.empty()) break;
        size_t comma_pos = line.find(',');
        ll x = stoll(line.substr(0, comma_pos));
        ll y = stoll(line.substr(comma_pos + 1));
        points.push_back({x, y});
    }
    ll ans = 0;
    int n = points.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Point p1 = points[i];
            Point p2 = points[j];
            if (p1.x == p2.x || p1.y == p2.y) continue;
            if (isValid(p1, p2, points)) {
                // cout << "valid rectangle: " << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
                ll dx = abs(p1.x - p2.x) + 1;
                ll dy = abs(p1.y - p2.y) + 1;
                ll area = dx * dy;
                // cout << "area: " << area << endl;
                ans = max(ans, area);
            }
        }
    }

    cout << "ans:" << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "runtime: " << duration.count() << " nanoseconds" << endl;
}