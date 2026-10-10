#include <bits/stdc++.h>
using namespace std;

// 489. Robot Room Cleaner [H]
// LeetCode robot-room-cleaner

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the
 * cell.
 *     // Returns false if the cell in front is blocked and robot stays in the
 * current cell. bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

// enum Direction { UP, RIGHT, DOWN, LEFT };

class Solution {

    array<char, 4> direction_x = {1, 0, -1, 0};
    array<char, 4> direction_y = {0, 1, 0, -1};

    array<array<bool, 200>, 200> visited;
    char current_direction = 0;

    void turn(char target_direction, Robot& robot) {
        switch (target_direction - current_direction) {
            case 1:
            case -3:
                robot.turnRight();
                break;
            case 2:
            case -2:
                robot.turnRight();
                robot.turnRight();
                break;
            case 3:
            case -1:
                robot.turnLeft();
                break;
        }
        current_direction = target_direction;
    }

    void clean(Robot& robot, short x, short y, char original_direction) {
        robot.clean();

        for (char direction = 0; direction < 4; direction++) {
            short i  = x + direction_x[direction];
            short j  = y + direction_y[direction];

            if (!visited[i][j]) {
                visited[i][j] = true;
                turn(direction, robot);
                if (robot.move()) {
                    clean(robot, i, j, direction);
                }
            }
        }

        turn((original_direction + 2) % 4, robot);
        robot.move();
    }

public:
    void cleanRoom(Robot& robot) { clean(robot, 100, 100, 0); }
};