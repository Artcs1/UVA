#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long int>Tfib;
    Tfib.push_back(0);
    Tfib.push_back(1);
    Tfib.push_back(1);
    for(int i=0;i<35;i++)
    {
        int tam = Tfib.size();
        Tfib.push_back(Tfib[tam-1]+Tfib[tam-2]+Tfib[tam-3]);
    }
    
    vector<long long int>res;
    long long int ini = 0;
    for(int i=0;i<35;i++)
    {
        res.push_back(ini);
        ini = ini*2 + Tfib[i];
    }
    int n;
    while(scanf("%d",&n)&&n!=0)
    {
        printf("%lld\n",res[n-1]);
    }
    return 0;
}
