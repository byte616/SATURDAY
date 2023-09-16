#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int> v[100005], rv[100005], nv[100005], list;
int n, m, a, b, color[100005];
ll cnt, val[100005], dp[100005], arr[100005];
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
ll func(int x){
    if(dp[x]) return dp[x];
    dp[x] = val[x];
    for(auto i : nv[x]){
        dp[x] = max(dp[x], func(i) + val[x]);
    }
    return dp[x];
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
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
    for(int i = 1; i <= n; i++){
        for(auto e : v[i]){
            if(color[i] == color[e]) continue;
            nv[color[i]].push_back(color[e]);
        }
        val[color[i]] += arr[i];
    }
    ll ans = 0;
    for(int i = 1; i <= cnt; i++){
        ans = max(ans, func(i));
    }
    cout << ans << '\n';
}
