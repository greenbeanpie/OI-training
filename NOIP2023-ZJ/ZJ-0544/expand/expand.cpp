#include<bits/stdc++.h>
using namespace std;
int oldx[5086],oldy[5086];
int curx[5086],cury[5086];
int xlen,ylen;
bool updateq(int& qrem)
{
    qrem--;
    memcpy(curx,oldx,xlen*sizeof(int));
    memcpy(cury,oldy,ylen*sizeof(int));
    int modx,mody;
    scanf("%d%d",&modx,&mody);
    while(modx--)
    {
        int pt,val;
        scanf("%d%d",&pt,&val);
        curx[pt-1]=val;
    }
    while(mody--)
    {
        int pt,val;
        scanf("%d%d",&pt,&val);
        cury[pt-1]=val;
    }
    return 1;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,extqs;
    scanf("%d%d%d%d",&c,&xlen,&ylen,&extqs);
    for(int i=0;i<xlen;i++)scanf("%d",oldx+i);
    for(int i=0;i<ylen;i++)scanf("%d",oldy+i);
    memcpy(curx,oldx,xlen*sizeof(int));
    memcpy(cury,oldy,ylen*sizeof(int));
    do
    {
        if(curx[0]==cury[0])
        {
            printf("0");
            continue;
        }
        if(curx[0]>cury[0])
        {
            if(curx[xlen-1]<cury[ylen-1])
            {
                printf("0");
                continue;
            }
            int xmax=0,ymax=0;
            for(int i=0;i<xlen;i++)if(xmax<curx[i])xmax=curx[i];
            for(int i=0;i<ylen;i++)if(ymax<cury[i])ymax=cury[i];
            if(xmax>ymax)
            {
                printf("1");
                continue;
            }
            else
            {
                printf("0");
                continue;
            }
        }
        else
        {
            if(curx[xlen-1]>cury[ylen-1])
            {
                printf("0");
                continue;
            }
            int xmin=0x7f3f3f3f,ymin=0x7f3f3f3f;
            for(int i=0;i<xlen;i++)if(xmin>curx[i])xmin=curx[i];
            for(int i=0;i<ylen;i++)if(ymin>cury[i])ymin=cury[i];
            if(xmin<ymin)
            {
                printf("1");
                continue;
            }
            else
            {
                printf("0");
                continue;
            }
        }
    }while(updateq(extqs));
    return 0;
}
