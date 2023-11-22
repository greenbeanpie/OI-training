#include <bits/stdc++.h>
using namespace std;
inline int gin() {
    int s=0,f=1;
    char c=getchar();
    while(c<'0' || c>'9') {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        s=(s<<3)+(s<<1)+(c^48);
        c=getchar();
    }
    return s*f;
}
//remember to check the answer when n==1 !!!
const int N=3005;
int n,m;
char w[N][N],A[N][N],B[N][N];
string mn[N],mx[N];

bool cmp(char x,char y) {return x>y;}

signed main() {
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    n=gin(),m=gin();
    for(int i=1;i<=n;i++) {
        scanf("%s",w[i]+1);
        for(int j=1;j<=m;j++) A[i][j]=B[i][j]=w[i][j];
        sort(A[i]+1,A[i]+m+1);
        sort(B[i]+1,B[i]+m+1,cmp);
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            mn[i]+=A[i][j];
        }
        // cout<<mn[i];
        // puts("");
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            mx[i]+=B[i][j];
        }
        // cout<<mx[i];
        // puts("");
    }
    for(int i=1;i<=n;i++) {
        int op=1;
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            if(mn[i]>=mx[j]) {op=0; break;}
        }
        printf("%d",op);
    }
    return 0;
}