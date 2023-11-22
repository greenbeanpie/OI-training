#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define L(i, l, r) for (int i = (l); i <= (r); i++)
#define R(i, l, r) for (int i = (l); i >= (r); i--)
inline int read() 
{
    int sum = 0, nega = 1; char ch = getchar(); 
    while(ch > '9' || ch < '0') {if(ch == '-') nega = -1; ch = getchar();}
    while(ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
    return sum * nega; 
}
const int N = 3009; 
int n, m, pos;
int ans[N], cnt[29]; 
char s[N][N], tmp[N];
inline bool cmp(int x, int y)
{
    L(i, 1, m) 
    {
        if(s[x][i] < s[y][i]) return 1; 
        else if(s[x][i] > s[y][i]) return 0;
    }
    return 0; 
}
signed main() 
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout); 
    n = read(); m = read();
    L(i, 1, n) 
    {
        scanf("%s", tmp + 1); 
        L(j, 0, 25) cnt[j] = 0; 
        L(j, 1, m) cnt[tmp[j] - 'a']++; 
        int pep = 0; 
        R(j, 25, 0)
            L(k, 1, cnt[j]) s[i][++pep] = j + 'a';  
    }
    pos = 1; 
    L(i, 2, n) 
        if(!cmp(pos, i)) pos = i; 
    L(i, 1, n) 
        if(i != pos) 
        {
            L(j, 0, 25) cnt[j] = 0;
            L(j, 1, m) tmp[j] = s[i][j]; 
            L(j, 1, m) cnt[s[i][j] - 'a']++;
            int pep = 0;  
            L(j, 0, 25) 
                L(k, 1, cnt[j]) s[i][++pep] = j + 'a'; 
            if(cmp(i, pos)) ans[i] = 1;
            L(j, 1, m) s[i][j] = tmp[j];  
        }
    ans[pos] = 1; 
    L(j, 0, 25) cnt[j] = 0; 
    L(j, 1, m) tmp[j] = s[pos][j]; 
    L(j, 1, m) cnt[s[pos][j] - 'a']++; 
    int pep = 0; 
    L(j, 0, 25) 
        L(k, 1, cnt[j]) s[pos][++pep] = j + 'a'; 
    L(i, 1, n)
        if(i != pos && !cmp(pos, i)) ans[pos] = 0;
    L(i, 1, n) putchar(ans[i] + '0'); puts(""); 
    return 0; 
}