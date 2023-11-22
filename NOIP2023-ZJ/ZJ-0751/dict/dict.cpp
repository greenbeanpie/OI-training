#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

typedef pair<string,int> psi;

const int N = 3005;

string s[N];

int n,m;
int b[N],vis[N];

unordered_map<string,int> um;

vector<psi> tot;

inline void read(int &x)
{
    x = 0;int f = 1;char c = getchar();
    while(!isdigit(c)){if(c == '-')f = -1;c = getchar();}
    while(isdigit(c)){x = (x<<1)+(x<<3)+(c^48);c = getchar();}
    x*=f;
}
/*
inline void read(string &x)
{
    x = "";char c = getchar();
    while(isalpha(c)){x+=c;c = getchar();};
}*/

bool cmp(psi a,psi b)
{
	//���������ŵ��뷨 
    return a.first>b.first;
}

void change(psi s)
{
    um[s.first]++;
    tot.push_back(s);
    for(int i=0;i<s.first.size();i++)
    {
        for(int j=i+1;j<s.first.size();j++)
        {
            string s_change = s.first;
            swap(s_change[i],s_change[j]);
            if(!um[s_change])
            {
                um[s_change]++;
                tot.push_back({s_change,s.second});
                change({s_change,s.second});
            }
        }
    }
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    read(n);read(m);
    if(n == 1) puts("1");
    for(int i=1;i<=n;i++)
    {
        um.clear();
        string t;
        //read(t);
        cin >> t;
        s[i] = t;
        change({t,i});
    }
    sort(tot.begin(),tot.end(),cmp);
    /*for(int i=1;i<=n;i++)
    {
        for(auto x:s_get[i])
            cout << x.first << "-"  << x.second << " ";
        puts("");
    }*/
    //for(auto x:tot) cout << x.second << " ";
    //puts("");
    for(int i=0;i<tot.size();i++)
    {
        int m = tot[i].second;
        if(i == tot.size()-1)
        {
            b[m] = 1;
            break;
        }
        vis[m] = 1;
        if(b[m]) continue;
        int flag = 0;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j])
            {
                flag = 1;
                break;
            }
        }
        if(!flag) b[m] = 1;
    }
    for(int i=1;i<=n;i++) printf("%d",b[i]);
    return 0;
}
