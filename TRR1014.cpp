#include <iostream>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

int n;
int graph[105][105];

void solveType1(){
    for(int i = 1; i <= n; ++i){
        int inDeg = 0, outDeg = 0;
        for(int j = 1; j <= n; ++j){
            inDeg += graph[j][i];
            outDeg += graph[i][j];
        }
        cout << inDeg << " " << outDeg << endl;
    }
}

void solveType2(){
    vector<pair<int, int>> edges;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(graph[i][j] == 1) edges.push_back({i, j});
    
    int m = edges.size();
    int arr[n + 1][m];
    memset(arr, 0, sizeof(arr));

    for(int i = 0; i < m; ++i){
        arr[edges[i].first][i] = 1;
        arr[edges[i].second][i] = -1;
    }
    
    cout << n << " " << m << endl;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < m; ++j) cout << arr[i][j] << " ";
        cout << endl;
    }
}

void solve(){
    int type;
    cin >> type >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> graph[i][j];
    
    if(type == 1) solveType1();
    else solveType2();
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    solve();

    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms";
    return 0;
}
