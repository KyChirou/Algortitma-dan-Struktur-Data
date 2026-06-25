#include <iostream>
#include <vector>
using namespace std;

int R, C;
int SR, SC, FR, FC;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int totalPaths = 0;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c) {
    if (r == FR && c == FC) {
        totalPaths++;
        return;
    }

    visited[r][c] = true;

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 0 && !visited[nr][nc]) {
            dfs(nr, nc);
        }
    }

    visited[r][c] = false; 
}

int main() {
    if (!(cin >> R >> C)) return 0;

    grid.assign(R, vector<int>(C));
    visited.assign(R, vector<bool>(C, false));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }

    cin >> SR >> SC >> FR >> FC;

    dfs(SR, SC);

    cout << totalPaths << "\n";
    return 0;
}