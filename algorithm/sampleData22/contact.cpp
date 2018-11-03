#include<iostream>
#include<fstream>
#define INF 987654321
using namespace std;

int T;// 0~90 테스트케이스 
int N;// 1~500 정점의 개수 
int M;// 1~10000 간선의수 
int K;// 1~3 질문의 개수 
int result1,result2;

int D[501]; // 다익스트라 
int W[501][501]={0}; // 노드 구성도 
int P[501][501];//경로 
int S[501];//방문 
void Swap(int& a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
void Qurey(int a,int b,double distance)
{
	int tmp;
	int tmp1;
	int tmp2;
	
	for(int i=0;;i++)
	{
		if(P[b][i] == -1) break;
		
		tmp = P[b][i];
		
		if(distance - W[tmp][b] <0)
		{
			// tmp 와 b 사이에 있는 것 
			tmp1 = tmp; tmp2 = b;
			if(tmp1>tmp2)Swap(tmp1,tmp2);
			if(result1>tmp1)
			{
				result1=tmp1;result2=tmp2;
			}
			else if(result1==tmp1 && result2>tmp2)
			{
				result2=tmp2;
			}
		}
		else if(distance - W[tmp][b] >0)
		{
			//a와 tmp 사이에 있다.
			Qurey(a,tmp,distance-W[tmp][b]); 
		}
		else
		{
			// tmp위치에서 만난다~ 
			if(result1>tmp)
			{
				result1=tmp;result2=tmp;
			}
			else if(result1==tmp && result2>tmp)
			{
				result2=tmp;
			}			
			
		}
	} 
	
}
void Dijkstra(int a, int b)//반환하는 값은 거리! 
{
	int dt=INF;
	int tmp; 
	int check;
	for(int i=1;i<=N;i++)
	{
		S[i] = 0; // 방문했는지 안했는지도 초기화 해줍니다.
		P[i][0] = -1; // 경로 초기화를 해줍니다.  
		D[i] = W[a][i];
		if(D[i] !=0 && D[i] !=INF) // a->i로 갈수있는 길이 있을경우 
		{
			if(dt > D[i])
			{
				dt = D[i];
				check = i; // 경로가 제일작은값 마킹 
			}
			P[i][0] = a;
			P[i][1] = -1;	
		}
	}
	S[a] = 1; // a에서 출발하므로 당연히 방문했겠지?? 

	for(int T=1;T<N;T++)
	{		
		dt = INF;
		for(int j=1;j<=N;j++)
		{
			if(S[j]==1) continue;
			if(dt>D[j]) 
			{
				dt = D[j];
				check = j;
			}
		}
		S[check] =1;	
		for(int i=1;i<=N;i++)
		{
			if(S[i] == 1 ) continue;

			if(W[check][i] == INF) continue;

			if(D[i] > D[check] + W[check][i])
			{	
				D[i] = D[check] + W[check][i];
				P[i][0] = check;
				P[i][1] =-1; // 경로초기화  
			}
			else if(D[i] == D[check] + W[check][i])
			{
				for(int j=1;;j++)
				{
					if(P[i][j]==-1)
					{
						P[i][j] = check;
						P[i][j+1] = -1;
						break;
					}
				}
			}
		}
	}
	//D에는 a에서 임의의 수로가는 최단 거리가 저장되었다. 
	//P에는 최단거리 경로가 저장 되어있다. 
}

int main(void)
{
	int a;
	int b;
	int _i;
	int _j;
	int _w;
	double distance;
	ifstream fin;
	ofstream fout;
	
	fin.open("contact.inp");
	fout.open("contact.out");
	
	fin>>T; //테스터 케이스 입력 
	
	for(int i=1;i<=T;i++)//테스터 케이스만큼 실행 
	{
		fin>>N;fin>>M;fin>>K; // 정점 간석 질문 입력

		for(int q=1;q<=N;q++)//초기화 작업 D^0 번째 
		{
			for(int w=1;w<=N;w++)
			{
				if(q==w)
				{
					continue;
				}
				W[q][w] = INF; // INF 무한대값
			}
		}
		for(int j=1;j<=M;j++)//간선 정보들 입력 
		{
			fin>>_i;fin>>_j;fin>>_w;
			// 전치행렬이므로  
			W[_i][_j] = _w;
			W[_j][_i] = _w;
		}
				 
		for(int j=1;j<=K;j++)//질문에대한 답변 
		{
			fin>>a;fin>>b;
			Dijkstra(a,b);
			result1=INF;result2=INF;distance = (double)D[b]/2;
			//S 중복방지 배열과 P최단거리 배열완성 
			Qurey(a,b,distance);
			//cout<<result1<<" "<<result2<<endl;
			fout<<result1<<" "<<result2<<endl;
		}
	}	
}
