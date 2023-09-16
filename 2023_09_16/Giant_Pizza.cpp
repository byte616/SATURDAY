#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a, b, color[200005], cnt;
char c1, c2, ans[100005];
vector<int> v[200005], rv[200005], list;
bool vis[200005];
int rev(int x){
    if(x <= m) return x + m;
    return x - m;
}
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
    while(n--){
        cin >> c1 >> a >> c2 >> b;
        if(c1 == '-') a = m + a;
        if(c2 == '-') b = m + b;
        v[rev(a)].push_back(b);
        v[rev(b)].push_back(a);
        rv[a].push_back(rev(b));
        rv[b].push_back(rev(a));
    }
    for(int i = 1; i <= m * 2; i++){
        if(!vis[i]) dfs(i);
    }
    reverse(list.begin(), list.end());
    for(auto i : list){
        if(!color[i]){
            cnt += 1;
            dfs2(i);
        }
    }
    for(int i = 1; i <= m; i++){
        ans[i] = ' ';
        if(color[i] == color[i + m]){
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
        else if(color[i] > color[i + m]){
            ans[i] = '+';
        }
        else{
            ans[i] = '-';
        }
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
}
