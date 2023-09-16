#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, a, b, color[100005], cnt;
vector<int> v[100005], rv[100005], list;
bool vis[100005];
void dfs(int x){
    vis[x] = 1;
    for(auto i : v[x]){
        if(!vis[i]) dfs(i);
    }
    list.push_back(x);
}
void dfs2(int x){
    color[x] = cnt;
    for(auto i : rv[x]){
        if(!color[i]) dfs2(i);
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
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i);
    }
    reverse(list.begin(), list.end());
    for(auto i : list){
        if(!color[i]){
            cnt += 1;
            dfs2(i);
        }
    }
    cout << cnt << '\n';
    for(int i = 1; i <= n; i++){
        cout << color[i] << " ";
    }
}
