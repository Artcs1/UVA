#include<bits/stdc++.h>

using namespace std;

int main()
{
    string S,N;
    int n,m;
    scanf("%d",&n);
    while(n--)
    {
        cin>>S;
        scanf("%d",&m);
        while(m--)
        {
            cin>>N;
            bool band = false;
            int tS = S.size(),nS= N.size();
            for(int i=0;i< tS-nS+1;i++)
            {
                string st = S.substr(i,nS);
                if(st == N)
                    band = true;
            }
            (band)? printf("y\n"): printf("n\n");
        }
    }
    return 0;
}
