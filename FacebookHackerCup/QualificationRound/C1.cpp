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
#define vii vector<pii>
#define vll vector<ll>
 
#define FOR(a,b,c)  for(int a=b; a<c; ++a)
#define F0R(a,b,c)  for(int a=b; a<=c; ++a)
 
#define INF 0x3f3f3f3f
 
using namespace std;
 
const int MAXN = 112;

int par[MAXN], sum[MAXN];
bool vis[MAXN];

void dfs(int v, vi c, vi adj[]){
    vis[v] = true;
    for(auto x: adj[v]){
        if(vis[x]) continue;
        par[x] = v;
        sum[x] = sum[v]+c[x];
        dfs(x,c,adj);
    }
}

void solve(){
    int n; cin>>n;
    
    vi c(n+1);
    F0R(i,1,n) cin>>c[i];

    vi adj[MAXN];
    FOR(i,0,n-1){
        int u,v; cin>>u>>v;
        adj[u].pb(v), adj[v].pb(u);
    }

    memset(vis,false,sizeof(vis)); 
    memset(par, -1, sizeof(par));
    memset(sum, 0, sizeof(sum));

    sum[1] = c[1];
    dfs(1,c,adj);

    vii order;
    F0R(i,1,n) order.pb( {sum[i], i} );

    sort(order.begin(), order.end());

    ll sum1=-1, sum2=-1;

    bool vis[MAXN]={false};
    for(int i = order.size()-1; i>=0; --i){
        if(sum1 == -1){
            int v = order[i].y;
            sum1=0LL;
            while(v != 1){
                vis[v] = true;
                sum1 += c[v];
                v = par[v];
            }
        }
        else{
            ll tmp=0LL;
        
            int v = order[i].y;
            while(v != 1){
                if(vis[v]){ tmp=0; break; }

                vis[v] = true;
                tmp += c[v];
                v = par[v];
            }
            sum2 = max(sum2, tmp);
        }

        if(sum2>sum1) swap(sum1, sum2);
    }

    if(sum1 == 0)
        cout<<c[1]<<endl;
    else if(sum2 == 0)
        cout<<sum1+c[1]<<endl;
    else
        cout<<sum1+sum2+c[1]<<endl;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);
    
    int T; cin>>T;
    F0R(i,1,T){ cout<<"Case #"<<i<<": "; solve(); }

    return 0;
}
