#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a, b;
vector<int> v[100005], rv[100005];
bool vis[100005], vis2[100005];
void dfs(int x){
    vis[x] = 1;
    for(auto i : v[x]){
        if(!vis[i]) dfs(i);
    }
}
void dfs2(int x){
    vis2[x] = 1;
    for(auto i : rv[x]){
        if(!vis[i]) dfs2(i);
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
        rv[b].push_back(a);
    }
    dfs(1);
    dfs2(1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i] || !vis2[i]) ans += 1;
    }
    cout << ans << '\n';
}
