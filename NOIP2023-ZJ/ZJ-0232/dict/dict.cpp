#include<bits/stdc++.h>
#define For(i,l,r) for(int i=(l);i<=(r);++i)
#define ReFor(i,r,l) for(int i=(r);i>=(l);--i)
const int N=3010;
using namespace std;
int n,m,id;
char CH[N];
int buc[27];
vector<int> S[N],minn,second_min,now_max,now_min;
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    For(i,1,n)
    {
        For(j,1,m)cin>>CH[j];
        S[i].clear();
        For(j,1,m)S[i].emplace_back((CH[j]-'a'));
    }
    if(n==1){cout<<"1";return 0;}
    {
        minn=S[1];
        sort(minn.begin(),minn.end());
        reverse(minn.begin(),minn.end());
        id=1;
        For(i,2,n)
        {
            memset(buc,0,sizeof(buc));
            for(auto x:S[i])++buc[x];
            now_max.clear();
            ReFor(cnt,25,0){For(_,1,buc[cnt])now_max.emplace_back(cnt);}
            For(j,0,m-1)
            {
                if(minn[j]==now_max[j])continue;
                if(minn[j]>now_max[j]){minn=now_max;id=i;break;}
                if(minn[j]<now_max[j])break;
            }
        }
        For(i,1,n){if(id!=i){second_min=S[i];break;}}
        sort(second_min.begin(),second_min.end());
        reverse(second_min.begin(),second_min.end());
        For(i,1,n)
        {
            if(id==i)continue;
            memset(buc,0,sizeof(buc));
            for(auto x:S[i])++buc[x];
            now_max.clear();
            ReFor(cnt,25,0){For(_,1,buc[cnt])now_max.emplace_back(cnt);}
            For(j,0,m-1)
            {
                if(second_min[j]==now_max[j])continue;
                if(second_min[j]>now_max[j]){second_min=now_max;break;}
                if(second_min[j]<now_max[j])break;
            }
        }
    };
    For(i,1,n)
    {
        memset(buc,0,sizeof(buc));
        for(auto x:S[i])++buc[x];
        now_min.clear();
        For(cnt,0,25){For(_,1,buc[cnt])now_min.emplace_back(cnt);}
        int type=1;if(i==id)type=2;
        bool flag=true;
        if(type==1)
        {
            For(j,0,m-1)
            {
                if(now_min[j]==minn[j])continue;
                if(now_min[j]<minn[j]){flag=true;break;}
                if(now_min[j]>minn[j]){flag=false;break;}
            }
        }
        if(type==2)
        {
            For(j,0,m-1)
            {
                if(now_min[j]==second_min[j])continue;
                if(now_min[j]<second_min[j]){flag=true;break;}
                if(now_min[j]>second_min[j]){flag=false;break;}
            }
        }
        if(flag==true)cout<<"1";
        else if(flag==false)cout<<"0";
    }
    return 0;
}