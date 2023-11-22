// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
int T;
int mysystem(std::string command){return system(command.c_str());}
signed main()
{
    std::ios::sync_with_stdio(false);
    while(!(mysystem("./mkdata > run.in")||
            mysystem("./boom")||
            mysystem("./run")||
            mysystem("diff run.out run.ans")))
        std::cout<<++T<<std::endl;
    return 0;
}