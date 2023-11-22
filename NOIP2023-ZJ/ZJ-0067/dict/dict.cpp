#include<bits/stdc++.h>
using namespace std;
const int N=6005;
int n,m,c[26],ans[N];
struct node {
    string s;
    bool k;
    int id;
    bool operator <(const node &o) const {
        return s!=o.s?s<o.s:k<o.k;
    }
} a[N];
int main() {
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i].s;
        a[i].k=0;
        a[i].id=i;
        memset(c,0,sizeof(c));
        for(int j=0;j<m;j++) {
            c[a[i].s[j]-'a']++;
        }
        for(int j=0,k=0;j<m;j++) {
            while(!c[k]) {
                k++;
            }
            a[i].s[j]='a'+k;
            c[k]--;
        }
        a[n+i].s=a[i].s;
        reverse(a[n+i].s.begin(),a[n+i].s.end());
        a[n+i].k=1;
        a[n+i].id=n+i;
    }
    sort(a+1,a+2*n+1);
    for(int i=2*n,j=0;i>=1;i--) {
        if(a[i].k==1) j++;
        if(a[i].id<=n) ans[a[i].id]=(j==n);
    }
    for(int i=1;i<=n;i++) {
        cout<<ans[i];
    }
    return 0;
}