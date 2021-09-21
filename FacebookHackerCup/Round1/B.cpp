#include <bits/stdc++.h>
#include <iostream>

#define ll  long long
#define ull unsigned long long
#define x   first
#define y   second
#define mp  make_pair
#define pb  push_back

#define pii pair<int,int>
#define vi  vector<int>
#define vii vector<pii>

#define FOR(a,b,c)  for(int a=b; a<c; ++a)
#define F0R(a,b,c)  for(int a=b; a<=c; ++a)

#define INF 0x3f3f3f3f

using namespace std;

void solve(){
    int n,m,a,b; cin>>n>>m>>a>>b;

    if(a < n+m-1 || b < n+m-1) {cout<<"Impossible"<<endl; return;}

    int ans[n][m];

    FOR(i,0,n) FOR(j,0,m)
        ans[i][j] = 1;

    int sum = n+m-1;

    a -= sum-1, b -= sum-1;

    ans[0][0] = a, ans[0][m-1] = b;

    cout<<"Possible"<<endl;
    FOR(i,0,n) {
        FOR(j,0,m)  cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);

    int T; cin>>T;
    F0R(i,1,T){
        cout<<"Case #"<<i<<": "; solve();
    }

    return 0;
}