#include<bits/stdc++.h>
using namespace std;
int main(){
    ofstream out("test.in");
    int v[100];
    v[0]=3;
    v[1]=5;
    v[2]=7;
    v[3]=9;
    for(int i=0;i<26;++i)
    {
        int value=rand()%100+1;
        out<<(char)('a'+i)<<"="<<value<<'\n';
    }
    char op[100];
    op[0]='+';
    op[1]='-';
    op[2]='*';
    op[3]='/';
    op[4]='^';
    for(int i=0;i<100000;++i)
    {
        int length=v[rand()%4];
        for(int j=0;j<length;++j)
            if(j%2==0)
            {
                out<<(char)('a'+rand()%25);
            }
            else
            {
                out<<op[rand()%5];
            }
        out<<'\n';
    }



    return 0;
}
