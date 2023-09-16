#include <iostream>
#include <vector>
using namespace std;
int n, m, a, b;
vector<int> v[100005], rv[100005];
bool vis1[100005], vis2[100005];
void dfs(int x){
    vis1[x] = 1;
    for(auto i : v[x]){
        if(!vis1[i]) dfs(i);
    }
}
void dfs2(int x){
    vis2[x] = 1;
    for(auto i : rv[x]){
        if(!vis2[i]) dfs2(i);
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
    for(int i = 2; i <= n; i++){
        if(!vis1[i]){
            cout << "NO" << '\n';
            cout << 1 << " " << i << '\n';
            return 0;
        }
        if(!vis2[i]){
            cout << "NO" << '\n';
            cout << i << " " << 1 << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
}
