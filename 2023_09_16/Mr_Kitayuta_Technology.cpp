#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a, b;
bool flag = 0;
vector<int> v[100005], cv[100005], path;
int vis[100005], vis2[100005];
void dfs(int x){
    vis[x] = 1;
    path.push_back(x);
    for(auto i : cv[x]){
        if(!vis[i]) dfs(i);
    }
}
void dfs2(int x){
    if(vis2[x]){
        if(vis2[x] == 1) flag = 1;
        return;
    }
    vis2[x] = 1;
    for(auto i : v[x]){
        dfs2(i);
    }
    vis2[x] = 2;
}
int main(){
    // think:
    // cycle with k nodes --> need k paths
    // otherwise, need connected compoent k - 1 paths
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
        cv[a].push_back(b);
        cv[b].push_back(a);
    }
    // undirect graph avoid dfs uncompletely
    // ex: 6 -> 1 -> 3
    // if use direct graph and start dfs from 1
    // you will get path: 1 -> 3, 6
    // each path does not include cycle --> ans = (2 - 1) + (1 - 1) = 1
    // actually ans is "2"
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            flag = 0;
            dfs(i); // find conected component
            ans += path.size();
            for(auto e : path){
                if(!vis2[e]) dfs2(e); // find cycle
            }
            if(!flag) ans -= 1;
            path.clear();
        }
    }
    cout << ans << '\n';
}
