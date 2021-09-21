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
 
bool isVowel(char c){
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

bool indexVowel(int c){
    return (c=='A'-'A' || c=='E'-'A' || c=='I'-'A' || c=='O'-'A' || c=='U'-'A');
}

void solve(){
    string s; cin>>s;

    int letters[26] = {0},
        vowels=0;
    FOR(i,0,s.length())
        vowels += isVowel(s[i]),
        letters[s[i]-'A']++;

    int highestVowel=0, 
        highestConsoant=1,
        vowelSum=0, consoantSum=0;
    FOR(i,0,26){
        if(indexVowel(i)){
            if(letters[i]>letters[highestVowel])
                highestVowel = i;
            vowelSum += letters[i];
        }
        else{
            if(letters[i]>letters[highestConsoant])
                highestConsoant=i;
            consoantSum += letters[i];
        }
    }

    ll ans = min( consoantSum + 2*(vowelSum - letters[highestVowel]),
                  vowelSum + 2*(consoantSum - letters[highestConsoant]));



    cout<<ans<<endl;
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
