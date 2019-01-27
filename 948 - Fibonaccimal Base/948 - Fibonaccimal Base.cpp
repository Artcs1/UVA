#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>fib;
    fib.push_back(1);
    fib.push_back(2);
    int F = 2+1;
    while(F < 100000000)
    {
        fib.push_back(F);
        int tam = fib.size();
        F = fib[tam-1] + fib[tam-2];
    }
    int n,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        int M = m,suma = 0,ind,R = 1e9,zeros =0;
        string S = "";
        while(suma != m)
        {
            
            ind = upper_bound(fib.begin(),fib.end(),M) - fib.begin();
            if(R == 1e9)
                R = ind;
            else 
            { 
                zeros = R -  ind -1;
                R = ind;
            } 
            for(int z = 0; z<zeros;z++)
                S+="0";
            S+="1";
            suma+=fib[ind-1];
            M= m -suma;
        }
        zeros = R -1;
        for(int z =0;z<zeros;z++)
            S+="0";

        printf("%d = %s (fib)\n",m,S.c_str());
    }

    return 0;
}
