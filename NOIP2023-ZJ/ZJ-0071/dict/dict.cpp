#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
// #define int long long
inline int read()
{
    int x=0,f=1,c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)x=x*10+c-48,c=getchar();
    return x*f;
}
char a[3005][3005];
std::string pre[3005],suf[3005],b[3005];
signed main()
{
    // printf("%d\n",'~');
    // return 0;
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n=read(),m=read();
    pre[0]=suf[n+1]="~";
    for(int i=1;i<=n;i++)
    {
        scanf("%s",a[i]+1);
        std::sort(a[i]+1,a[i]+m+1);
        std::reverse(a[i]+1,a[i]+m+1);
        b[i]=a[i]+1;
        // if(i==1||x<qwq)qwq=x;
    }
    for(int i=1;i<=n;i++)
    {
        pre[i]=(b[i]<pre[i-1])?b[i]:pre[i-1];
    }
    for(int i=n;i>=1;i--)
    {
        suf[i]=(b[i]<suf[i+1])?b[i]:suf[i+1];
    }
    for(int i=1;i<=n;i++)
    {

        std::reverse(a[i]+1,a[i]+m+1);
        std::string x=a[i]+1;
        printf("%d",(x<pre[i-1])&&(x<suf[i+1]));
    }
    puts("");
}