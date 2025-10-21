#include <bits/stdc++.h>
using namespace std;

int rows = 4, cols = 4;
int maze[4][4] = {
    {1, 0, 0, 0},
    {1, 1, 1, 0},
    {0, 1, 0, 0},
    {0, 1, 1, 1}
};

// directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Point {
    int x, y;
};

// check if move is valid
bool isValid(int x, int y, bool visited[4][4]) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 1 && !visited[x][y]);
}

bool dfs(Point curr, Point end, bool visited[4][4], vector<Point>& path) {
    visited[curr.x][curr.y] = true;
    path.push_back(curr);

    if(curr.x == end.x && curr.y == end.y)
        return true; // destination reached

    for(int dir=0; dir<4; dir++) {
        int nx = curr.x + dx[dir];
        int ny = curr.y + dy[dir];

        if(isValid(nx, ny, visited)) {
            if(dfs({nx, ny}, end, visited, path))
                return true; // path found
        }
    }

    path.pop_back(); // backtrack
    return false;
}

int main() {
    Point start = {0,0};
    Point end = {3,3};
    bool visited[4][4] = {false};
    vector<Point> path;

    if(dfs(start, end, visited, path)) {
        cout << "Path from (0,0) to (3,3): ";
        for(auto p : path)
            cout << "(" << p.x << "," << p.y << ") ";
        cout << endl;
    } else {
        cout << "No path exists!\n";
    }

    return 0;
}

