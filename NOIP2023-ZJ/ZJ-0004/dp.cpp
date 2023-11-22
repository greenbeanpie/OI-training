#include <bits/stdc++.h>
using namespace std;
FILE *f;
#define printf(args...) fprintf(f,##args)
inline void make()
{
    // int X=(rand()&1)?1e9:100;
    // int n=300-rand()%10,m=300-rand()%10,q=60,i,s,t;
    // printf("-1 %d %d %d\n",n,m,q);
    // for(i=0;i<n;i++) printf("%d ",rand()%X); printf("\n");
    // for(i=0;i<m;i++) printf("%d ",rand()%X); printf("\n");
    // while(q--)
    // {
    //     s=5e5/120+rand()%10,t=5e5/120+rand()%10;
    //     printf("%d %d\n",s,t);
    //     while(s--) printf("%d %d\n",rand()%n+1,rand()%X);
    //     while(t--) printf("%d %d\n",rand()%m+1,rand()%X);
    // }
    int T=10;
    printf("-1 %d\n",T);
    while(T--)
    {
        int X=(rand()&1)?1e9:100;
        int n=rand()%10+1,m=300-rand()%10,l,r;
        printf("%d %d %d %d\n",n,m,rand()%n+1,rand()%X/10);
        while(m--)
        {
            int l=rand()%n+1,r=rand()%n+1;
            printf("%d %d %d\n",max(l,r),abs(r-l)+1,rand()%X);
        }
        // int X=1e9;
        // int n=rand()%(int)1e9+1,m=100000-rand()%10,l,r;
        // printf("%d %d %d %d\n",n,m,rand()%n+1,rand()%X);
        // while(m--)
        // {
        //     int l=rand()%n+1,r=rand()%n+1;
        //     printf("%d %d %d\n",max(l,r),abs(r-l)+1,rand()%X);
        // }
    }
}
#undef printf
int main()
{
    int i;
    for(i=0;i<100;i++)
    {
        // f=fopen("expand.in","w"),make(),fclose(f);
        // if(system("time ./test")) break;
        // if(system("./bf")) break;
        // if(system("diff expand.out expand.ans -w -q -s")) break;
        f=fopen("run.in","w"),make(),fclose(f);
        if(system("time ./test")) break;
        if(system("./bf")) break;
        if(system("diff run.out run.ans -w -q -s")) break;
    }
    return 0;
}