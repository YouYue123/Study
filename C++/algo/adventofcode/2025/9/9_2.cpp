#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<ll, ll>;
struct Point {
    ll x, y;
};
using line = pair<Point, Point>;

// check point c is on which side of the line l (1: left/above, -1: right/below, 0: on the line)
auto crossProduct = [](line l, const Point& c) -> ll {
    Point a = l.first;
    Point b = l.second;
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
};

bool isIntersect(line l1, line l2) {
    auto cp1 = crossProduct(l1, l2.first);
    auto cp2 = crossProduct(l1, l2.second);
    auto cp3 = crossProduct(l2, l1.first);
    auto cp4 = crossProduct(l2, l1.second);
    // if cp1 and cp2 have different signs, then l1 and l2 intersect
    // or if cp3 and cp4 have different signs, then l1 and l2 intersect
    if (((cp1 > 0 && cp2 < 0) || (cp1 < 0 && cp2 > 0)) &&
        ((cp3 > 0 && cp4 < 0) || (cp3 < 0 && cp4 > 0))) {
        return true;
    }
    return false;
}

bool isInOrOnPoly(Point p, const vector<Point>& poly) {
    int n = poly.size();
    bool inside = false;
    for (int i = 0; i < n; i++) {
        Point p1 = poly[i];
        Point p2 = poly[(i + 1) % n];
        ll cross = (p2.x - p1.x) * (p.y - p1.y) - (p.x - p1.x) * (p2.y - p1.y);
        if (cross == 0) {
            // on the edge of the polygon
            ll minX = min(p1.x, p2.x);
            ll maxX = max(p1.x, p2.x);
            ll minY = min(p1.y, p2.y);
            ll maxY = max(p1.y, p2.y);
            if (p.x >= minX && p.x <= maxX && p.y >= minY && p.y <= maxY) return true;
        } else {
            // Not on the edge of the polygon
            // Use ray casting
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
    }
    return inside;
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
    // Check all 4 corners are in or on the polygon
    if (!isInOrOnPoly(A, poly)) return false;
    if (!isInOrOnPoly(B, poly)) return false;
    if (!isInOrOnPoly(C, poly)) return false;
    if (!isInOrOnPoly(D, poly)) return false;
    int n = poly.size();
    for (int i = 0; i < n; i++) {
        Point u = poly[i];
        Point v = poly[(i + 1) % n];
        line polyEdge = {u, v};
        // For each edge of the polygon, check if it intersects with the rectangle
        // If it does, that means there are some part of the rectangle is outside the polygon
        if (isIntersect(polyEdge, {A, B})) return false;
        if (isIntersect(polyEdge, {B, C})) return false;
        if (isIntersect(polyEdge, {C, D})) return false;
        if (isIntersect(polyEdge, {D, A})) return false;
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