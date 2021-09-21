#include <bits/stdc++.h>
#include <iostream>
 
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>

#define x first
#define y second
#define mp make_pair
#define pb push_back

#define vi vector<int>
#define vc vector<char>
#define vii vector<pii>
#define vll vector<ll>
 
#define FOR(a,b,c)  for(int a=b; a<c; ++a)
#define F0R(a,b,c)  for(int a=b; a<=c; ++a)
 
#define INF 0x3f3f3f3f
 
using namespace std;

ll path[30][30];

void bfs(int v, int u, vi adj[]){
    path[u][v] = 0;
    queue<int> q; q.push(v);
    while(!q.empty()){
        int front = q.front(); q.pop();

        for(auto x: adj[front]){
            if(path[u][x]>-1) continue;

            q.push(x);
            path[u][x] = path[u][front]+1;
        }
    }

}

void solve(){
    string s; cin>>s;
    int k; cin>>k;

    vi adj[26];
    FOR(i,0,k){
        string x; cin>>x;
        adj[x[0]-'A'].pb(x[1]-'A');
    }

    memset(path, -1, sizeof(path));
    FOR(i,0,26) bfs(i,i,adj);

    ll ans = INT_MAX;
    FOR(i,0,26){
        ll cnt = 0LL;
        FOR(j,0,s.length()){
            cnt += path[s[j]-'A'][i];
            if(path[s[j]-'A'][i] == -1){ cnt = INT_MAX; break; }
        }
        ans = min(ans, cnt);
    }

    cout<< (ans == INT_MAX? -1: ans) << endl;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    
    int T; cin>>T;
    F0R(i,1,T){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
