#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;


#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))

//
//  This code uses Dikstra algorithm.
//  
//


int inf = INT_MAX/2;
vector<PII> vertex[101];
priority_queue<status, vector<status>, greater<status> > q;
struct status
{
	int edge,dist;
	void Set(int _edge,int _dist)
	{
		edge = _edge;
		dist = _dist;
	}
	bool operator >(const status &st)const
	{
		return dist > st.dist;
	}
};
void Dikstra()
{
	//q have been pushed first para.
    status sta,p;
    int to,cos;
    while(!q.empty())
    {
		sta = q.top();
		REP(i,vertex[sta.edge].size())
		{
			to = vertex[sta.edge][i].first;
			cos = vertex[sta.edge][i].second;
			if(dist[to][sta.chicket] > dist[sta.edge][sta.chicket] + cos)
			{
				dist[to][sta.chicket] = dist[sta.edge][sta.chicket] + cos;
				p.Set(to,dist[to][sta.chicket],sta.chicket);
				q.push(p);
			}
		}
		
		q.pop();
	}
    
    
	printf("%d\n", min(dist[n][0],dist[n][1]));
}
}
