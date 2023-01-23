#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int ROWS = 10;
const int COLS = 10;

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

std::vector<std::vector<bool>> grid(ROWS, std::vector<bool>(COLS, true));

void generateMaze(int x, int y) {
    std::vector<Direction> directions = { NORTH, EAST, SOUTH, WEST };
    std::random_shuffle(directions.begin(), directions.end());
    for (auto dir : directions) {
        int newX = x, newY = y;
        switch (dir) {
            case NORTH:
                newX--;
                break;
            case EAST:
                newY++;
                break;
            case SOUTH:
                newX++;
                break;
            case WEST:
                newY--;
                break;
        }
        if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && grid[newX][newY]) {
            grid[x][y] = false;
            grid[newX][newY] = false;
            generateMaze(newX, newY);
        }
    }
}

int main() {
    srand(time(0
