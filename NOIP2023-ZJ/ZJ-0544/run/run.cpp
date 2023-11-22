#include<bits/stdc++.h>
using namespace std;
int main()
{
    
	freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
	int c,asks;
    int ans=0;
    scanf("%d%d",&c,&asks);
    while(asks--)
    {
        int energy,days,challenges,limit,energydown;
        scanf("%d%d%d%d",&days,&challenges,&limit,&energydown);
        for(int i=0;i<challenges;i++)
        {
            int endd,dayk,rew;
            scanf("%d%d%d",&endd,&dayk,&rew);
            if(endd<dayk)continue;
            if(dayk>limit)continue;
            int add=rew-dayk*energydown;
            if(add>0)ans+=add;
        }
    }
    printf("%d",ans);
    return 0;
}
