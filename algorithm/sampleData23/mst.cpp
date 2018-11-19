#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<stdio.h>
#define INF 987654321
using namespace std;
FILE *in = fopen("mst.inp","rt");
FILE *out = fopen("mst.out","wt");
class MST
{
	public:
		int u;
		int v;
		int w;
		int edge;
		
		bool operator>(MST &k) const{
			if(this->w > k.w) return true;
			else if(this->w == k.w && this->edge > k.edge) return true;
			return false;
		}
		bool operator<(MST &k) const{
			if(this->w < k.w) return true;
			else if(this->w == k.w && this->edge < k.edge) return true;
			return false;
		}

};
int n,m;
int N[10001];
int S[10001]; // 엄마노드 저장하는곳
MST K[100001]; 
MST W[10001][10001];
MST heap[100001]; // prioritiy_Q
int size;// 우선순위 큐 사이즈 
MST tmp_t;
void MST_Swap(MST &a,MST &b)
{
	tmp_t = a;
	a = b;
	b = tmp_t;
}
MST ret;
int current;
int leftChild;
int rightChild;
int maxNode;
int parent;
void P_PUSH(MST& p)
{
	heap[size] = p;
	
	current = size;
	parent =(size-1)/2;
	
	while(current > 0 && heap[current] < heap[parent])
	{
		MST_Swap(heap[current],heap[parent]);
		current = parent;
		parent = (parent-1) /2;
	}
	size++;
}


MST P_POP()
{
	ret = heap[0];
	size--;
	
	heap[0] = heap[size];
	current = 0;
	leftChild = 1;
	rightChild = 2;
	maxNode = 0;
	
	while(leftChild < size)
	{
		if(heap[maxNode] > heap[leftChild])
		{
			maxNode = leftChild;
		}
		if(rightChild < size && heap[maxNode] > heap[rightChild])
		{
			maxNode = rightChild;
		}
		if(maxNode == current) break;
		else
		{
			MST_Swap(heap[current],heap[maxNode]);
			current = maxNode;
			leftChild = current * 2 + 1;
			rightChild = current * 2 + 2;
		}
	}
	return ret;
} 


int result = 0;
void  Kru() // mst 값 반환 
{
	int tmp1,tmp2,tmp;
	int u;int v;
	int set=0;
	//long long int result=0;
	for(int i=0;i<n;i++)
	{
		S[i] = i;// 자기 자신을 가리키는 노드가 된다	
	} 
	sort(K,K+m);
	for(int i=0;i<m;i++)
	{
		tmp1 = K[i].u;
		while(true)
		{
			if(tmp1==S[tmp1])
			{
				//끝노드 도착
				break;
			} 
			else
			{
				tmp1=S[tmp1];//그다음 노드를 최신화 
			}
		}
		
		tmp2 = K[i].v;
		while(true)
		{
			if(tmp2==S[tmp2])
			{
				//끝노드 도착
				break;
			} 
			else
			{
				tmp2=S[tmp2];//그다음 노드를 최신화 
			}
		}	
		
		if(tmp1==tmp2) continue;

		if(tmp1>tmp2)
		{
			S[tmp2] = tmp1;
			
			v = K[i].v;
			while(S[v]!=tmp1)
			{
				tmp = S[v];
				S[v] = tmp1;
				v= tmp;
			}
			//v랑 연결된 값들 tmp1로 초기화하기
		}
		else
		{
			//u랑 연결된 값들 tmp2로 초기화하기
			S[tmp1] = tmp2;
			
			u = K[i].u;
			while(S[u]!=tmp2)
			{
				tmp =S[u];
				S[u] = tmp2;
				u =tmp;	
			}	 
	 	}
		
		N[set++] = K[i].edge;
		result +=K[i].w;
		if(set==n-1) break;
	} 
	

	fprintf(out,"Tree edges by Kruskal algorithm: %d\n",result);

	for(int i=0;i<n-1;i++)
	{
	fprintf(out,"%d\n",N[i]);
	}	
	
}
void Report()
{
	int s=0;
	while(s<size)
	{
		
		cout<<heap[s].edge<<" ";
		s++;//0   1   2   4   8   16
	}
	cout<<endl;
}
void Prim(int start)
{
	size = 0; // 우선순위 큐 초기화
	int set=0;
	MST tmp;
	//long long int result = 0;
	
	for(int i=0;i<n;i++)
	{
		S[i] = 0;
	}
	
	int result_s = start; 
	S[start] = 1;
//	V[start][q] =1;


	for(int i=0;i<n;i++)
	{
		if(S[i] == 1) continue;
		else if(W[start][i].w == 0) continue;
		P_PUSH(W[start][i]);
	}
	while(size>=0)
	{
		tmp = P_POP();
		if(S[tmp.v]==1) continue;
		S[tmp.v] = 1;
		
		//result += tmp.w;
		N[set++] = tmp.edge;
		//if(set==n-1) break;
		start = tmp.v;
		for(int i=0;i<n;i++)
		{
			if(W[start][i].w == 0) continue;
			if(S[i] == 1) continue;
			
			
			P_PUSH(W[start][i]);
			//pq.push(W[start][i]);
		} 

	}
	
	fprintf(out,"Tree edges by Prim algorithm with starting vertex %d: %d\n",result_s,result);
	for(int i=0;i<n-1;i++)
	{
		fprintf(out,"%d\n",N[i]);
	}		
	
}

int main()
{
//	DWORD s;
//  	DWORD e;
 /// 	s = GetTickCount();

	
	int u,v,w;
	
	//fin>>n;fin>>m;
	
	fscanf(in,"%d %d",&n,&m);

	
	size=0;
	for(int i=0;i<m;i++)// m개의 간선의 표현들 모아옴 
	{
		//fin>>u;fin>>v;fin>>w;
		fscanf(in,"%d",&u);
		fscanf(in,"%d",&v);
		fscanf(in,"%d",&w);
		K[i].u =u; K[i].v =v; K[i].w =w; K[i].edge =i;
		W[u][v].w = w; W[v][u].w = w;
		W[v][u].edge = i; W[u][v].edge =i;
		W[u][v].v=v; W[v][u].v =u;
	}
	 // 간선 정보 정렬완료
	Kru();
	Prim(0);
	Prim(n/2);
	Prim(n-1);	 	
  	fclose(in);
  	fclose(out);
 // 	e = GetTickCount(); 
  ///	cout << "실행 시간 :" << (e - s) / (double)2000 << endl;
	return 0;
	
}
