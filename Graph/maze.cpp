#include <bits/stdc++.h>
using namespace std;

int rows = 4, cols = 4;
int maze[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 1, 0},
    {0, 1, 999, 0},
    {0, 0, 0, 1}
};

// directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Point {
    int x, y;
};

bool isValid(int x, int y, bool visited[4][4]) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] != 1 && !visited[x][y]);
}

void findTreasure(Point start) {
    queue<Point> q;
    bool visited[4][4] = {false};
    Point parent[4][4]; // store parent for path reconstruction

    visited[start.x][start.y] = true;
    q.push(start);
    parent[start.x][start.y] = {-1, -1};

    Point treasure = {-1, -1};
    bool found = false;

    while(!q.empty() && !found) {
        Point curr = q.front(); q.pop();

        if(maze[curr.x][curr.y] == 999) {
            treasure = curr;
            found = true;
            break;
        }

        for(int dir=0; dir<4; dir++) {
            int nx = curr.x + dx[dir];
            int ny = curr.y + dy[dir];

            if(isValid(nx, ny, visited)) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                parent[nx][ny] = curr; // track parent
            }
        }
    }

    if(!found) {
        cout << "Treasure not found!\n";
        return;
    }

    // reconstruct path
    vector<Point> path;
    Point cur = treasure;
    while(cur.x != -1) {
        path.push_back(cur);
        cur = parent[cur.x][cur.y];
    }
    reverse(path.begin(), path.end());

    cout << "Path to treasure: ";
    for(auto p : path) {
        cout << "(" << p.x << "," << p.y << ") ";
    }
    cout << endl;
}

int main() {
    Point start = {0,0};
    findTreasure(start);
    return 0;
}

