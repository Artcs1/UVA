#include<bits/stdc++.h>

using namespace std;

int lis(int Q[],int n)
{
    vector<int>L;
    vector<int>::iterator it;

    for(int i=0;i<n;i++)
    {
        int v = Q[i];
        if(v!=-1)
        {
            it  = lower_bound(L.begin(),L.end(),v);
            if(it == L.end())
                L.push_back(v);
            else{
                L.erase(it);
                L.insert(it,v);
            }
        }
    }
    return (int)L.size();
}
int main()
{
    int c;
    scanf("%d",&c);
    for(int k=0;k<c;k++)
    {
        int q,n,m,temp;
        scanf("%d %d %d",&q,&n,&m);
        n++,m++;
        int P[63000],Q[63000];
        memset(P,-1,sizeof P);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            P[temp] = i;
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&temp);
            Q[i] = P[temp];
        }

        printf("Case %d: %d\n",k+1,lis(Q,m));
    }
    return 0;
}
