#include <bits/stdc++.h>
using namespace std;
struct bianliang
{
    bool ifsame;//nosame is 1
    int linkwith;
    bool ifc;
    char val;
};
bianliang vars[100086];
void init(int varc)
{
    for(int i=1;i<=varc;i++)vars[i].linkwith=i;
}
vector<int> routes[100086];
bool ifvis[100086];
queue<int> mutes;
int linkwithc[100086];
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    srand(time(0));
	int c,asks;
    scanf("%d%d",&c,&asks);
    while(asks--)
    {
        int varc,cmdc;
        scanf("%d%d",&varc,&cmdc);
        memset(vars+1,0,varc*sizeof(bianliang));
        init(varc);
        while(cmdc--)
        {
            char cmd;
            int param1,param2;
            scanf("\n%c ",&cmd);
            switch(cmd)
            {
            case 'T':
            case 'F':
            case 'U':
                scanf("%d",&param1);
                vars[param1].val=cmd;
                vars[param1].ifc=1;
                break;
            case '+':
                scanf("%d%d",&param1,&param2);
                vars[param1].ifc=vars[param2].ifc;
                if(vars[param2].ifc)vars[param1].val=vars[param2].val;
                else
                {
                    vars[param1].ifsame=vars[param2].ifsame;
                    vars[param1].linkwith=vars[param2].linkwith;
                }
                break;
            case '-':
                scanf("%d%d",&param1,&param2);
                vars[param1].ifc=vars[param2].ifc;
                if(vars[param2].ifc)
                {
                    switch(vars[param2].val)
                    {
                    case 'T':
                        vars[param1].val='F';
                        break;
                    case 'F':
                        vars[param1].val='T';
                        break;
                    case 'U':
                        vars[param1].val='U';
                        break;
                    }
                }
                else
                {
                    vars[param1].ifsame=!vars[param2].ifsame;
                    vars[param1].linkwith=vars[param2].linkwith;
                }
            }
        }
        for(int i=1;i<varc;i++)routes[i].clear();
        memset(linkwithc+1,0,varc*sizeof(int));
        int ans=0,rsp=0;
        for(int i=1;i<=varc;i++)
        {
            if(!vars[i].ifc)routes[vars[i].linkwith].push_back(i);
        }
        for(int i=1;i<=varc;i++)
        {
            memset(ifvis,0,100086);
            queue<int> qqq;
            qqq.push(i);
            while(!qqq.empty())
            {
                int x=qqq.front();
                qqq.pop();
                for(int q:routes[x])
                {
                    if(ifvis[q])continue;
                    vars[q].ifsame=!(vars[q].ifsame^vars[x].ifsame);
                    vars[q].linkwith=vars[x].linkwith;
                }
            }
        }
        ans=rand()%varc;
        printf("%d\n",ans);
    }
}
