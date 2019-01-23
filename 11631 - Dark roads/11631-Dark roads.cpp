#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int pset[200005];

void initSet(int n)
{
    for(int i=0;i<n;i++)
        pset[i]=i;
}
int findSet(int i)
{
    return (pset[i]==i)?i:pset[i]=findSet(pset[i]);
}
void unionSet(int i,int j)
{
    int x=findSet(i),y=findSet(j);
    pset[x]=y;
}
bool isSameSet(int i,int j)
{
    if(findSet(i)==findSet(j))
        return true;
    return false;
}

struct node{
    int u,v,w;
    node(int _u,int _v,int _w)
    {
        u=_u,v=_v,w=_w;
    }
};

bool cmp(node p1,node p2)
{
    return p1.w<p2.w;
}
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m))
    {
        initSet(n+5);
        vector<node>Edges;
        int u,v,w;
        if(n==0&&m==0)
            break;
        int suma=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            suma+=w;
            Edges.push_back(node(u,v,w));
        }
        sort(Edges.begin(),Edges.end(),cmp);
        int mst=0;
        for(int i=0;i<m;i++)
        {
            if(!isSameSet(Edges[i].u,Edges[i].v))
            {
                unionSet(Edges[i].u,Edges[i].v);
                mst+=Edges[i].w;
            }
        }
        printf("%d\n",suma-mst);
    }
    return 0;
}
