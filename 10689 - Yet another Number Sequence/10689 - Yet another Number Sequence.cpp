#include<bits/stdc++.h>

using namespace std;

int main()
{
    
   /* freopen("input.txt", "r", stdin);
      freopen("out.txt", "w", stdout);*/
 
    int cases,a,b,n,m;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++)
    {
        scanf("%d %d %d %d",&a,&b,&n,&m);
        int mod = 1;
        for(int j=0;j<m;j++)
            mod*=10;
        int A = a % mod, B= b %mod;
        vector<int>period;
        period.push_back(A);
        period.push_back(B);
        do{
            int C= (A+B)%mod;
            period.push_back(C);
            A = B;
            B = C;
        }while( A != a%mod || B!= b%mod );
        period.pop_back();
        period.pop_back();
        
        int tam = period.size();
        printf("%d\n", period[n%tam]);

    }

    /*fclose(stdin);
    fclose(stdout);*/

    return 0;
}
