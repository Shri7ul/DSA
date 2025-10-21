#include <bits/stdc++.h>
using namespace std;

int rows, cols;
char grid[10][10]; // grid size maximum 10x10, adjust if needed
string word;
bool found = false;

// directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dfs(int x, int y, int index, bool visited[10][10]) {
    // if whole word matched
    if(index == word.size()) return true;

    // check boundaries
    if(x < 0 || x >= rows || y < 0 || y >= cols) return false;
    if(visited[x][y] || grid[x][y] != word[index]) return false;

    visited[x][y] = true;

    // explore all 4 directions
    for(int dir=0; dir<4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(dfs(nx, ny, index+1, visited)) return true;
    }

    visited[x][y] = false; // backtrack
    return false;
}

bool exist() {
    bool visited[10][10] = {false};

    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(dfs(i,j,0,visited)) return true;
        }
    }
    return false;
}

int main() {
    rows = 3;
    cols = 4;

    char temp[4][10] = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            grid[i][j] = temp[i][j];

    word = "ABCCED";

    if(exist())
        cout << "Word '" << word << "' exists in the grid\n";
    else
        cout << "Word '" << word << "' does NOT exist in the grid\n";

    return 0;
}

