#include<bits/stdc++.h>

using namespace std;

struct node{
    int w,q,pos;
    node(){}
    node(int w,int q,int pos):w(w),q(q),pos(pos){}
    bool operator<(const node &a)
    {
        if(w == a.w)
            return q<a.q;
        return w<a.w; 
    }
};


vector<int> r;
vector<int> p;

void lis()
{
    vector<int>L,I;
    vector<int>:: iterator it;
    int tam = r.size();
    for(int i=0;i<tam;i++)
    {
        it = lower_bound(L.begin(),L.end(),-r[i]);
        I.push_back((int)(it - L.begin()));
        if(it == L.end())
            L.push_back(-r[i]);
        else
        {
            L.erase(it);
            L.insert(it,-r[i]);
        }
    }
    printf("%d\n",(int)L.size());
    int siz = L.size();
    vector<int>R;
    for(int i=tam-1;i>=0;i--)
        if(siz == I[i]+1)
            R.push_back(p[i]),siz--;
    reverse(R.begin(),R.end());
    for(int i=0;i<R.size();i++)
        printf("%d\n",R[i]);
}
int main()
{
    vector<node>A;
    int w1,q1;
    int j=1;
    while(~scanf("%d %d",&w1,&q1))
    {
        A.push_back(node(w1,q1,j++));
    }
    sort(A.begin(),A.end());
    int t = A.size();

    bool flag[1000000];
    memset(flag,0,sizeof flag);
    for(int i=0;i<t;i++)
    {
        flag[A[i].w] = true;
        if(flag[A[i].w])
            r.push_back(A[i].q),p.push_back(A[i].pos);
    } 
    lis();

    return 0;
}
