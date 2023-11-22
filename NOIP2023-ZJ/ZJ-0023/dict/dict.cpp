#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=(j),i##_=(k);i<=i##_;i++)
#define per(i,j,k) for(int i=(j),i##_=(k);i>=i##_;i--)
#define ckmn(i,j) (i=min(i,j))
#define ckmx(i,j) (i=max(i,j))
#define fir first
#define sec second
#define mkp make_pair
#define eb emplace_back
#define pb push_back
typedef long long ll;
typedef long double db;
#define siz(i) ((int)(i).size())
#define all(i) (i).begin(),(i).end()
// #define int ll
typedef vector<int> vi;
typedef pair<int,int> pi;

const int N=3010;
int n,m,a[N<<1],pos[N<<1],ans[N];
string s[N<<1];
signed main(){ios::sync_with_stdio(false),cin.tie(nullptr);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n){
        cin>>s[i];
        sort(all(s[i]));
        s[i+n]=s[i];
        reverse(all(s[i+n]));
    }
    iota(a+1,a+1+2*n,1);
    sort(a+1,a+1+2*n,[](int x,int y){return s[x]==s[y]?x>y:s[x]<s[y];});
    // rep(i,1,2*n) cout<<a[i]<<" \n"[i==i_];
    rep(i,1,2*n) pos[a[i]]=i;
    int cnt=0;
    rep(i,1,2*n){
        if(a[i]>n){
            cnt++;
        }else{
            ans[a[i]]=(cnt-(pos[a[i]+n]<i)==0);
        }
    }
    rep(i,1,n) cout<<ans[i];
    cout<<"\n";
return 0;}