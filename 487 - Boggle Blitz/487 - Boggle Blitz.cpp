#include<bits/stdc++.h>
using namespace std;

int n;
vector<string>arr;
vector<string>r;
map<string,int>mymap;
bool vis[25][25];
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};
string res;
void backtrack(int x,int y)
{
    if(vis[x][y])
        return;
    vis[x][y]= true;
    if(res.length()>=3&&mymap.count(res)<=0)
    {
        mymap[res]++;;
        r.push_back(res);
    }
    for(int i=0;i<8;i++)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<n&&(arr[xx][yy]>arr[x][y]))
        {
            res+= arr[xx][yy];
            backtrack(xx,yy);
            res = res.substr(0,res.size()-1);
        }
    }
    vis[x][y] = false;
}

bool cmp(string p1,string p2)
{
    if(p1.size()==p2.size())
        return p1<p2;
    return p1.size()<p2.size();
}
int main() {
	int cases;
	scanf("%d",&cases);
	int web = 0;
	while(cases--)
	{
		arr.clear();
		r.clear();
        mymap.clear();

		string cad;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			cin>>cad;
			arr.push_back(cad);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
			    res = "";
			    res+=arr[i][j];
			    memset(vis,0,sizeof vis);
				backtrack(i,j);
			}
		}
		sort(r.begin(),r.end(),cmp);
		if(web)
            printf("\n");
        web++;
		for(int i=0;i<r.size();i++)
		{
		    printf("%s\n",r[i].c_str());
		}
	}
	return 0;
}
