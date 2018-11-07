#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<fstream>
#define INF 987654321
using namespace std;

class Kruskal
{
	public:
		int u;
		int v;
		int w;
		int edge;
		
		bool operator>(Kruskal &k) const{
			if(this->w > k.w) return true;
			else if(this->w == k.w && this->edge > k.edge) return true;
			return false;
		}
		bool operator<(Kruskal &k) const{
			if(this->w < k.w) return true;
			else if(this->w == k.w && this->edge < k.edge) return true;
			return false;
		}
};

class Prime
{
	public:
		int w;
		int edge;
};
class Priority
{
	public:
		int 	
};
Kruskal K[10000001];
long long int n,m;
int N[10001];
int S[10001]; // 엄마노드 저장하는곳
Prime W[10001][10001];
Prime D[10000001];

void P_push()
typedef pair<int,int> p;
void  Kru(ofstream &fout) // mst 값 반환 
{
	int tmp;
	int u;int v;
	int set=0;
	long long int result=0;
	for(int i=0;i<n;i++)
	{
		S[i] = i;// 자기 자신을 가리키는 노드가 된다	
	} 
	sort(K,K+m);
	
	for(int i=0;i<m;i++)
	{
		tmp = K[i].u;
		while(true)
		{
			if(tmp==S[tmp])
			{
				//끝노드 도착
				u=tmp;
				break;
			} 
			else
			{
				tmp=S[tmp];
			}
		}
		
		tmp = K[i].v;
		while(true)
		{
			if(tmp==S[tmp])
			{
				//끝노드 도착
				v=tmp;
				break;
			} 
			else
			{
				tmp=S[tmp];
			}
		}		
		
		if(u==v) continue;

		if(u>v)
		{
			S[v]=u;
		}
		else
		{
			S[u]=v;
	 	}
		N[set++] = K[i].edge;
		result +=K[i].w;
		if(set==n-1) break;
	} 
	cout<<"Tree edges by Kruskal algorithm: "<<result<<endl;
	fout<<"Tree edges by Kruskal algorithm: "<<result<<endl;
	for(int i=0;i<n-1;i++)
	{
		cout<<N[i]<<endl;
		fout<<N[i]<<endl;
	}	
	
}

void Prim(ofstream &fout,int start)
{
	priority_queue<p, vector<p>, greater<p> > pq;
	int set=0;
	int inf;
	int edge;
	int tmp;
	int w;
	long long int result=0;
	int result_s = start;
	for(int i=0;i<n;i++)
	{
		S[i] = 0;
	}
		S[start] = 1;
	
	for(int i=0;i<n;i++)
	{
		if(W[start][i].w==INF) continue;
		pq.push(p(i,W[start][i].w));
	}
	
	while(!pq.empty())
	{
		tmp = pq.top().first;
		w = pq.top().second;
		
		pq.pop();
		
		if(S[tmp]== 1) continue;
		
		S[tmp] =1;
		result += w;
		N[set++] = W[start][tmp].edge;
		start = tmp;
		for(int i=0;i<n;i++)
		{
			if(W[start][i].w==INF) continue;
			pq.push(p(i,W[start][i].w));
		}
	}
	cout<<"Tree edges by Prim algorithm with starting vertex "<<result_s<<": "<<result<<endl;
	fout<<"Tree edges by Prim algorithm with starting vertex "<<result_s<<": "<<result<<endl;
	for(int i=0;i<n-1;i++)
	{
		cout<<N[i]<<endl;
		fout<<N[i]<<endl;
	}	
	
	
}



int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("mst.inp");
	fout.open("mst.out");
	
	int u,v,w;
	
	fin>>n;fin>>m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			W[i][j].w = INF;
		}
	}
	
	
	for(int i=0;i<m;i++)// m개의 간선의 표현들 모아옴 
	{
		fin>>u;fin>>v;fin>>w;
		K[i].u =u; K[i].v =v; K[i].w =w; K[i].edge =i;
		W[u][v].w = w; W[v][u].w = w;
		W[v][u].edge = i; W[u][v].edge =i;
	}
	 // 간선 정보 정렬완료
	Kru(fout);
	Prim(fout,0);
	Prim(fout,n/2);
	Prim(fout,n-1);
	
	
	
}
