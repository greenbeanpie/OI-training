#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
 
const int N=20010;
 
int ans;
int n,m,a[N];
 
int main () {
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    if(n==1) {
        printf("%d\n",&n);
        return 0;
    }
    ans=a[1]+a[n];
    for(int i=1; i<n; ++i)
        if(a[i]+a[i+1]>ans)
            ans=a[i]+a[i+1];
    for(int i=1; i<=n; ++i)
        m+=a[i];
    double mm=m,nn=n,tmp;
    tmp=ceil(mm/((int)(nn/2)));
    if((int)tmp>ans)
        ans=(int)tmp;
    printf("%d\n",ans);
    return 0;
}