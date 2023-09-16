#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll p = 1e9 + 7;
int n, m, a, b, arr[100005];
vector<int> v[100005], rv[100005], list;
bool vis[100005];
int color[100005], cnt = 0;
void dfs1(int x){
    vis[x] = 1;
    for(auto i : v[x]){
        if(!vis[i]) dfs1(i);
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
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cin >> m;
    while(m--){
        cin >> a >> b;
        v[a].push_back(b);
        rv[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs1(i);
    }
    reverse(list.begin(), list.end());
    for(auto i : list){
        if(!color[i]){
            cnt += 1;
            dfs2(i);
        }
    }
    vector<int> ans[cnt + 5];
    for(int i = 1; i <= n; i++){
        ans[color[i]].push_back(arr[i]);
    }
    ll mi = 0, combine = 1;
    for(int i = 1; i <= cnt; i++){
        sort(ans[i].begin(), ans[i].end());
        mi += ans[i][0];
        ll tmp = 0;
        for(auto j : ans[i]){
            if(j == ans[i][0]) tmp += 1;
            else break;
        }
        combine *= tmp;
        combine %= p;
    }
    cout << mi << " " << combine << '\n';
}
