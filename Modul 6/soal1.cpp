#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;
    
    vector<char> vertices(N);
    map<char, int> v_index; 
    
    for (int i = 0; i < N; ++i) {
        cin >> vertices[i];
        v_index[vertices[i]] = i;
    }

    int M;
    cin >> M;
    
    vector<vector<int>> matrix(N, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        matrix[v_index[u]][v_index[v]] = w;
    }

    cout << "Adjacency Matrix:\n  ";
    for (int i = 0; i < N; ++i) cout << vertices[i] << (i == N - 1 ? "" : " ");
    cout << "\n";
    
    for (int i = 0; i < N; ++i) {
        cout << vertices[i] << " ";
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}