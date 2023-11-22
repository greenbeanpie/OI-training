#include <bits/stdc++.h>
using namespace std;
char q[3010][3010];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int strcnt,slen;
    scanf("%d%d",&strcnt,&slen);
    for(int i=0;i<strcnt;i++)scanf("%s",q+i);
    for(int i=0;i<strcnt;i++)sort(q[i],q[i]+slen);
    for(int i=0;i<strcnt;i++)
    {
        bool ifallok=1;
        for(int j=0;j<strcnt;j++)
        {
            if(i==j)continue;
            bool ifthisok=0;
            for(int pt=0;pt<slen;pt++)
            {
                if(q[i][pt]>q[j][slen-1-pt])break;
                else if(q[i][pt]<q[j][slen-1-pt])
                {
                    ifthisok=1;
                    break;
                }
            }
            if(!ifthisok)
            {
                ifallok=0;
                break;
            }
        }
        printf("%d",ifallok);
    }
    return 0;
}
