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
#define vc  vector<char>
#define vii vector<pii>

#define FOR(a,b,c)  for(int a=b; a<c; ++a)
#define F0R(a,b,c)  for(int a=b; a<=c; ++a)

#define INF 0x3f3f3f3f

using namespace std;

void solve(){
    int n; cin>>n;
    string s; cin>>s;

    vc nof;
    FOR(i,0,n){
        if(s[i]=='F') continue;
        nof.pb(s[i]);
    }

    ll ans=0;
    FOR(i,1,nof.size())
        if(nof[i]!=nof[i-1]) ans++;

    cout<<ans<<endl;
}

int main(){
    cin.tie(NULL); ios::sync_with_stdio(false);

    int T; cin>>T;
    F0R(i,1,T){
        cout<<"Case #"<<i<<": "; solve();
    }

    return 0;
}