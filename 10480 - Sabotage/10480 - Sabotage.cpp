#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>

using namespace std;

#define inf_i (1<<29)-1

int n,m,u,v,w,f,s=0,t=1;
int res[55][55];
vector<int> p,vis;

void augment(int v,int minEdge)
{
    if(v==s)
    {
        f=minEdge;
        return;
    }
    else if(p[v]!=-1)
    {
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v]-=f,res[v][p[v]]+=f;
    }
}

int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        memset(res,-1,sizeof res);
        if(n==0&&m==0)
            break;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            res[u-1][v-1]=w;
            res[v-1][u-1]=w;
        }

        //printf("leyo\n");
        while(1)
        {
            f=0;
            vector<int> dist(55,inf_i);dist[s]=0;queue<int>q;q.push(s);
            p.assign(55,-1);
            while(!q.empty())
            {
                int u=q.front();q.pop();
                if(u==t) break;
                for(int v=0;v<n;v++)
                {
                    if(res[u][v]>0&&dist[v]==inf_i)
                        dist[v]=dist[u]+1,q.push(v),p[v]=u;
                }
            }
            augment(t,inf_i);
            if(f==0)break;
        }

        //printf("paso\n");
        queue<int>q;q.push(0);
        vis.assign(n,0);
        vis[0]=1;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int v=0;v<n;v++)
                if(res[u][v]>0&&vis[v]==0)
                    q.push(v),vis[v]=1;
        }
        //printf("imprimio\n");
        vector<int>V,U;
        for(int i=0;i<n;i++)
            if(vis[i]==1)
                V.push_back(i);
            else
                U.push_back(i);
        for(int i=0;i<(int)V.size();i++)
            for(int j=0;j<(int)U.size();j++)
                if(res[V[i]][U[j]]!=-1)
                    printf("%d %d\n",V[i]+1,U[j]+1);

        printf("\n");
    }
}
