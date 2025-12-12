#include <bits/stdc++.h>
using namespace std;
struct Region
{
    int width;
    int height;
    vector<int> requirements;
};

void printShapes(const vector<vector<string>>& shapes) {
    cout << "--- Parsed SHAPES ---" << endl;
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "Shape " << i << ":" << endl;
        for (auto& row : shapes[i]) {
            cout << "  " << row << endl;
        }
    }
    cout << endl;
}

void printRegions(const vector<Region>& regions) {
    cout << "--- Parsed REGIONS ---" << endl;
    for (size_t i = 0; i < regions.size(); ++i) {
        cout << "Region " << i << ":" << endl;
        cout << "  Width: " << regions[i].width << endl;
        cout << "  Height: " << regions[i].height << endl;
        cout << "  Requirements (Shape Indices):";
        for (int req : regions[i].requirements) {
            cout << " " << req;
        }
        cout << endl;
    }
    cout << endl;
}

vector<string> rotate(const vector<string> &shape)
{
    if (shape.empty())
        return {};
    int H = shape.size();
    int W = shape[0].size();
    vector<string> rotated(W, string(H, '.'));
    for (int r = 0; r < H; ++r)
    {
        for (int c = 0; c < W; ++c)
        {
            rotated[c][H - 1 - r] = shape[r][c];
        }
    }
    return rotated;
}

vector<string> flip(const vector<string> &shape)
{
    if (shape.empty())
        return {};
    vector<string> flipped = shape;
    std::reverse(flipped.begin(), flipped.end());
    return flipped;
}

vector<vector<string>> generateOrientations(const vector<string> &base)
{
    set<vector<string>> unique;
    vector<string> cur = base;
    // 4 Rotations
    for (int i = 0; i < 4; ++i)
    {
        unique.insert(cur);
        cur = rotate(cur);
    }
    // Flip and 4 Rotations
    cur = flip(base);
    for (int i = 0; i < 4; ++i)
    {
        unique.insert(cur);
        cur = rotate(cur);
    }
    return vector<vector<string>>(unique.begin(), unique.end());
}

bool dfs(int idx,
         vector<int> &pieces,
         vector<string> &grid,
         vector<vector<vector<string>>> &allOrientations,
         int lastPos)
{
    if (idx == (int)pieces.size()) return true;
    int shapeId = pieces[idx];
    int R = grid.size();
    int C = grid[0].size();
    bool sameAsPrev = (idx > 0 && pieces[idx] == pieces[idx - 1]);
    int startPos = sameAsPrev ? lastPos : 0;
    auto &orientations = allOrientations[shapeId];
    for (auto &shape : orientations)
    {
        int h = shape.size();
        int w = shape[0].size();
        for (int r = 0; r <= R - h; ++r)
        {
            for (int c = 0; c <= C - w; ++c)
            {

                int current_pos = r * C + c; // Flattened index
                if (current_pos < startPos)
                    continue;

                // Check Collision
                bool fits = true;
                for (int dr = 0; dr < h; ++dr)
                {
                    auto &s_row = shape[dr];
                    auto &g_row = grid[r + dr];
                    for (int dc = 0; dc < w; ++dc)
                    {
                        if (s_row[dc] == '#' && g_row[c + dc] != '.')
                        {
                            fits = false;
                            break;
                        }
                    }
                    if (!fits)
                        break;
                }

                if (fits)
                {
                    // Place
                    for (int dr = 0; dr < h; ++dr)
                    {
                        for (int dc = 0; dc < w; ++dc)
                        {
                            if (shape[dr][dc] == '#')
                            {
                                grid[r + dr][c + dc] = 'A' + (idx % 26);
                            }
                        }
                    }
                    if (dfs(idx + 1, pieces, grid, allOrientations, current_pos)) return true;
                    for (int dr = 0; dr < h; ++dr)
                    {
                        for (int dc = 0; dc < w; ++dc)
                        {
                            if (shape[dr][dc] == '#')
                            {
                                grid[r + dr][c + dc] = '.';
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

int solve(vector<vector<string>> &shapes, vector<Region> &regions)
{
    vector<vector<vector<string>>> allOrientations(shapes.size());
    for (int i = 0; i < shapes.size(); ++i) allOrientations[i] = generateOrientations(shapes[i]);
    vector<int> shapeAreas(shapes.size(), 0);
    for (int i = 0; i < shapes.size(); ++i)
    {
        for (auto &row : shapes[i])
        {
            for (char c : row) {
                if (c == '#') shapeAreas[i]++;
            }
        }
    }

    int ans = 0;

    for (auto &reg : regions)
    {
        vector<int> toPlaceList;
        for (int i = 0; i < reg.requirements.size(); ++i)
        {
            for (int k = 0; k < reg.requirements[i]; ++k)
            {
                toPlaceList.push_back(i);
            }
        }
        long long totalArea = 0;
        for (int pid : toPlaceList) totalArea += shapeAreas[pid];
        if (totalArea > (long long)reg.width * reg.height) continue;
        std::sort(toPlaceList.begin(), toPlaceList.end(), 
            [&](int a, int b) { 
                return shapeAreas[a] > shapeAreas[b]; 
            }
        );
        vector<string> grid(reg.height, string(reg.width, '.'));
        if (dfs(0, toPlaceList, grid, allOrientations, 0)) ans += 1;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string line;
    vector<vector<string>> shapes;
    vector<Region> regions;
    map<int, vector<string>> temp_shapes;
    int curShapeIdx = -1;
    while (std::getline(cin, line))
    {
        int first = line.find_first_not_of(" \t\r\n");
        if (first == string::npos) continue;
        int last = line.find_last_not_of(" \t\r\n");
        line = line.substr(first, (last - first + 1));
        int xPos = line.find('x');
        int colonPos = line.find(':');
        // If there is a x, means it is a region
        if (xPos != string::npos && colonPos != string::npos && xPos < colonPos)
        {
            // Region parsing
            Region reg;
            reg.width = std::stoi(line.substr(0, xPos));
            reg.height = std::stoi(line.substr(xPos + 1, colonPos - (xPos + 1)));
            stringstream ss(line.substr(colonPos + 1));
            int count;
            while (ss >> count)
            {
                reg.requirements.push_back(count);
            }
            regions.push_back(reg);
            continue;
        }
        if (line.back() == ':' && line.find(' ') == string::npos) curShapeIdx = std::stoi(line.substr(0, line.size() - 1));
        if (curShapeIdx != -1)
        {
            if(line.find('#') != string::npos || line.find('.') != string::npos) temp_shapes[curShapeIdx].push_back(line);
        }
    }

    if (!temp_shapes.empty())
    {
        int maxIdx = temp_shapes.rbegin()->first;
        shapes.resize(maxIdx + 1);
        for (auto &p : temp_shapes)
        {
            shapes[p.first] = p.second;
        }
    }
    printShapes(shapes);
    printRegions(regions);
    auto start_time = std::chrono::high_resolution_clock::now();
    auto end_time = std::chrono::high_resolution_clock::now();
    cout << "ans:" << solve(shapes, regions) << endl;
    cout << "runtime: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << "ms" << endl;
    return 0;
}