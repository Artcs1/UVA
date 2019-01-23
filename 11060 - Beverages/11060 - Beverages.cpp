#include<stdio.h>
#include<vector>
#include<iostream>
#include<map>
#include<string.h>
#include<algorithm>
#include <queue>
using  namespace std;


int main()
{
    int n;
    string cad,cad1;
    int cases=0;
    while(~scanf("%d",&n))
    {
        vector<int>topo;
        vector<int>ady[n+2];
        int degree[n+2];
        memset(degree,0,sizeof degree);
        map<string ,int> mymap;
        map<int , string> mymap2;
        for(int i=0;i<n;i++)
        {
            cin>>cad;
            mymap[cad]=i;
            mymap2[i]=cad;
        }
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            cin>>cad>>cad1;
            int u = mymap[cad];
            int v = mymap[cad1];
            ady[u].push_back(v);
            degree[v]++;
        }

        priority_queue<int, vector<int>, greater<int> >pq;
        for(int i=0;i<n;i++)
            if(degree[i]==0)
                pq.push(i);

        while(!pq.empty())
        {
            int u = pq.top();
            topo.push_back(u);
            pq.pop();
            for(int i=0;i<(int)ady[u].size();i++)
            {
                int v = ady[u][i];
                degree[v]--;
                if(degree[v]==0)
                    pq.push(v);
            }
        }
        int t=topo.size();
        printf("Case #%d: Dilbert should drink beverages in this order: ",++cases);
        for(int i=0;i<t;i++)
            (i==t-1)?printf("%s.\n\n",mymap2[topo[i]].c_str()):printf("%s ",mymap2[topo[i]].c_str());
        topo.clear();
        for(int i=0;i<n;i++)
            ady[i].clear();


    }
    return 0;
}
