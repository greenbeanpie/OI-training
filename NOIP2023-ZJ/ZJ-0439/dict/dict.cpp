// const string tsh="forever friends"
// rp++;
// return "退役";
// g++ -Wall -O2 -std=c++14  dict.cpp -o dict_exec

#include<bits/stdc++.h>
using namespace std;
#define il inline
#define fo(_var,_a,_b) for(int _var=_a;_var<=_b;_var++)
#define fr(_var,_a,_b) for(int _var=_a;_var>=_b;_var--)
#define foo(_var,_a,_b,_c) for(int _var=_a;_var<=_b;_var+=_c)
#define frr(_var,_a,_b,_c) for(int _var=_a;_var>=_b;_var-=_c)

struct node
{
    string str;
    string str_min;
    string str_max;
}a[3010];

int n,m;

bool cmp1(char _tmp1,char _tmp2)
{
    return _tmp1<_tmp2; 
}

bool cmp2(char _tmp1,char _tmp2)
{
    return _tmp1>_tmp2; 
}

void solve()
{
    scanf("%d%d",&n,&m);
    fo(i,1,n)
    {
        cin>>a[i].str;
        a[i].str_min=a[i].str;
        a[i].str_max=a[i].str;
        sort(a[i].str_min.begin(),a[i].str_min.end(),cmp1);
        sort(a[i].str_max.begin(),a[i].str_max.end(),cmp2);
    }
    fo(i,1,n)
    {
        int flag=1;
        fo(j,1,n)
        {
            if(i==j)
            {
                continue;
            }
            if(a[i].str_min>a[j].str_max)
            {
                flag=0;
            }
        }
        printf("%d",flag);
    }
    printf("\n");
    return ;
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);

    solve();
    
    // 多测要清空、要换行
    return 0;
}
