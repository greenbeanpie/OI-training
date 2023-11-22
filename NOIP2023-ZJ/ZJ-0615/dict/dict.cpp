#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int MAXN=3e3+3;
string s[2][MAXN];
int n,m; 
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cerr<<n<<m;
    for(int i=1;i<=n;i++){
        string g;
        cin>>g;
        sort(g.begin(),g.end());
        s[0][i]=g;
        reverse(g.begin(),g.end());
        s[1][i]=g;
    }
    for(int i=1;i<=n;i++){
        int flag=1;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            // cerr<<s[0]
            if(s[0][i]>=s[1][j]){
                flag=0;
                break;
            }
        }
        cout<<flag;
    }
    cout<<"\n";
    return 0;
}