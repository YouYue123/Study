#include <bits/stdc++.h>
using namespace std;

// 353. Design Snake Game [M]
// LeetCode design-snake-game

struct Coord {
    int x;
    int y;
};
class SnakeGame {
private:
    vector<vector<int>> food;
    int width;
    int height;
    int foodIdx = 0;
    deque<Coord> snake;
    unordered_set<int> body;
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width = width;
        this->height = height;
        this->food = std::move(food);
        this->body.insert(0);
        snake.emplace_back(0, 0);
    }
    
    int move(string direction) {
        int nxtHeadX = snake.front().x;
        int nxtHeadY = snake.front().y;
        if(direction == "R") {
            nxtHeadY += 1;
        } else if(direction == "L") {
            nxtHeadY -= 1;
        } else if(direction == "U") {
            nxtHeadX -= 1;
        } else if(direction == "D") {
            nxtHeadX += 1;
        }
        // cout << "curPos: " << nxtHeadX << " " << nxtHeadY << endl;
        if(nxtHeadX < 0 || nxtHeadX >= height || nxtHeadY < 0 || nxtHeadY >= width) return -1;
        if(foodIdx < food.size() && nxtHeadX == food[foodIdx][0] && nxtHeadY == food[foodIdx][1]) {
            foodIdx += 1;
        } else {
            body.erase(snake.back().x * width + snake.back().y);
            snake.pop_back();
        }
        if(body.contains(nxtHeadX * width + nxtHeadY)) return -1;
        snake.emplace_front(nxtHeadX, nxtHeadY);
        body.insert(nxtHeadX * width + nxtHeadY);

        // cout << "snake: " << endl;
        // for(int i = 0; i < snake.size(); i ++) {
        //     if(i != 0 && nxtHeadX == snake[i].x && nxtHeadY == snake[i].y) return -1;
        //     // cout << "(" << snake[i].x << "," << snake[i].y << ")" << " ";
        // }
        // cout << endl;
        return foodIdx;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */