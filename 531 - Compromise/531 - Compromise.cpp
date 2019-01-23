#include<bits/stdc++.h>

using namespace std;

int t1,t2;
vector<int>A,B,r;
int memo[105][105];

int lcs(int i,int j)
{
    if(i==t1||j==t2)
        return 0;
    if(memo[i][j]!=-1)
        return memo[i][j];

    int res = 0;
    if(A[i]==B[j])
        res = 1 + lcs(i+1,j+1);
    res = max(res,max(lcs(i+1,j),lcs(i,j+1)));
    return memo[i][j] = res;
}

void solve(int i,int j)
{
    if(i==t1||j==t2)
        return;
    if(A[i]==B[j])
    {
        r.push_back(A[i]);
        solve(i+1,j+1);
    }
    else
    {
        if(memo[i+1][j]>memo[i][j+1])
            solve(i+1,j);
        else
            solve(i,j+1);
    }
}
int main()
{
    string cad;
    while(getline(cin,cad)&&cad!="")
    {
        map<string,int>mymap;
        map<int,string>mymap2;
        int index =0;
        A.clear();B.clear();
        do{
            istringstream iss(cad);
            string t;
            while(iss>>t)
            { 
                if(mymap.count(t)<=0)
                {
                    mymap2[index]=t;
                    mymap[t]=index++;
                }
                A.push_back(mymap[t]);
            }
        }while(getline(cin,cad)&&cad!="#");

        while(getline(cin,cad)&&cad!="#")
        {
            istringstream iss(cad);
            string t;
            while(iss>>t)
            {
                if(mymap.count(t)<=0)
                {
                    mymap2[index] = t;
                    mymap[t]=index++;
                }
                B.push_back(mymap[t]);
            }
        }
        t1 = A.size();
        t2 = B.size();
        memset(memo,-1,sizeof memo);
        lcs(0,0);
        solve(0,0);
        for(int i=0;i<(int)r.size();i++)
        {
            (i==0)?printf("%s",mymap2[r[i]].c_str()):printf(" %s",mymap2[r[i]].c_str());
        }
        printf("\n");
        r.clear();
    }
    return 0;
}
