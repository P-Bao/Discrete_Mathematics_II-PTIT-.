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
    cout << n << endl;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) cout << graph[i][j] << " ";
        cout << endl;
    }
}

void solve(){
    int type, m;
    cin >> type >> n >> m;

    int u, v;
    while(m--){
        cin >> u >> v;
        graph[u][v] = 1;
    }

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
