#include <bits/stdc++.h>
using namespace std;

// Grid max size
const int MAX = 100;

// DFS function to mark all connected lands as visited
void dfs(int i, int j, int n, int m, int grid[MAX][MAX], bool visited[MAX][MAX]) {
    // Check for bounds
    if(i < 0 || i >= n || j < 0 || j >= m)
        return;

    // Check if current cell is water or already visited
    if(grid[i][j] == 0 || visited[i][j])
        return;

    // Mark current cell as visited
    visited[i][j] = true;


    dfs(i + 1, j, n, m, grid, visited);
    dfs(i - 1, j, n, m, grid, visited);
    dfs(i, j + 1, n, m, grid, visited);
    dfs(i, j - 1, n, m, grid, visited);
}

// Function to count number of islands
int countIslands(int n, int m, int grid[MAX][MAX]) {
    bool visited[MAX][MAX] = {false};
    int count = 0;


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(grid[i][j] == 1 && !visited[i][j]) {
                dfs(i, j, n, m, grid, visited);
                count++;
        }
    }

    return count;
}

int main() {
    int n, m;
    cout << "Enter grid size (rows and columns): ";
    cin >> n >> m;

    int grid[MAX][MAX];

    cout << "Enter grid elements (1 for land, 0 for water):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }


    int totalIslands = countIslands(n, m, grid);
    cout << "Number of islands: " << totalIslands << endl;

    return 0;
}

