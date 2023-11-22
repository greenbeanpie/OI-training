#include <bits/stdc++.h>
#define int unsigned long long int

using namespace std;

const int N = 3e3 + 10,INF = 0x7f7f7f7f7f7f7f7f,MOD = 9878325455767;

int p = 7;
int cnt[30];
char s[N];
int minn[N];

inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    for(;!isdigit(ch);ch = getchar())
        if(ch == '-') f = -1;
    for(;isdigit(ch);ch = getchar())
        x = (x << 1) + (x << 3) + ch -'0';
    return x * f;
}

void fre(){
    freopen("dict.in","r",stdin);//////////////////////////////
    freopen("dict.out","w",stdout);
}

signed main()
{
    fre();////////////////////////////////////////////////////
    int n = read(),len = read();

    if(n == 1){
        puts("1");
        return 0;
    }

    int least1 = INF,least2 = INF,id = 0;
    for(int i = 1;i <= n;i ++){
        cin >> s + 1;

        for(int j = 1;j <= len;j ++){
            cnt[s[j] - 'a' + 1] ++;
        }

        int has1 = 0,has = 0;
        for(int j = 1;j <= 26;j ++){
            for(int k = 1;k <= cnt[j];k ++){
                has1 = (has1 * p + j) % MOD;
            }
            /**/for(int k = 1;k <= cnt[26 - j + 1];k ++){
                has = (has * p + 26 - j + 1) % MOD;
            }
        }

        minn[i] = has1;

        /*for(int j = 26;j > 0;j --){
            for(int k = 1;k <= cnt[j];k ++){
                has = has * p + j % MOD;
            }
        }*/

        if(has < least1){
            least2 = least1;
            least1 = has;
            id = i;
        }

        else if(has < least2) least2 = has;
        
        for(int j = 1;j <= 26;j ++) cnt[j] = 0;//clear

    }

    for(int i = 1;i <= n;i ++){

        if(i == id){
            cout << (minn[i] < least2) ? 1 : 0;
        }
        else cout << (minn[i] < least1) ? 1 : 0;
    }
    /*printf("\n%lld\n%lld\n",least1,least2);
    int has = 0;
    for(int i = 1;i <= 3000;i ++){
    	has = (has * p + 26) % MOD;
    	printf("%llu\n",has);
	}*/
    return 0;
}
