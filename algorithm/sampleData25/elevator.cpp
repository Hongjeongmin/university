#include<iostream>
#include<fstream>
#define INF 987654321
using namespace std;

class Elevator
{
	public:
		int w[501];
};

class data
{
	public:
		int f;//층수
		int down;//내려갈때 가중치 
		int up; //올라갈때 가중치 
				
};

int W[201];//sum of weight
data C[200]; // input data

Elevator e[201]; // dp

int main(void)
{
	int T;
	int n;
	int k;
	int Min_weight_f;
	int Min_weight;
	int buffer;
	ifstream fin;
	ofstream fout;
	
	fin.open("elevator.inp");
	fout.open("elevator.out");
	
	fin>>T; // case 입력 
		
	for(int i=1;i<=T;i++)
	{
		fin>>n;fin>>k;//사람수와 층몇개 선택할지 고르자~
		for(int j=1;j<=n;j++)//인풋 파일 받기 끝 
		{
			fin>>C[j].f;fin>>C[j].down;fin>>C[j].up;	
		} 
		
		//dp 1개쌓기 
		Min_weight = INF;
		for(int m=1;m<=200;m++)
		{
			W[m] = 0;
			for(int x=1;x<=n;x++)
			{
					if(C[x].f>m)
					{
						e[m].w[x] = (C[x].f - m) * C[x].up;
						W[m] += e[m].w[x];		
					}
					else
					{
						if((C[x].f-1) * C[x].up  > (m-C[x].f) * C[x].down )
						{
							e[m].w[x] = (m-C[x].f) * C[x].down;
						}
						else
						{
							e[m].w[x] =(C[x].f-1) * C[x].up;
						}
						W[m] += e[m].w[x];
					} 	
			}
			if(Min_weight > W[m] ) 
			{
				Min_weight = W[m];
				Min_weight_f = m;
			}
		}
		buffer = Min_weight_f;
		
		cout<<"f: "<<Min_weight_f<<endl;
		//dp 2개 부터 쌓기 
		//if(i==2) cout<<"ddd"<<e[5].w[4]<<endl;
		for(int j=2;j<=k;j++)
		{
			Min_weight = INF;
			for(int m=1;m<=200;m++)
			{
				W[m] = 0;//블록별 가중치 초기화; 
				for(int x=1;x<=n;x++)
				{
					if(e[buffer].w[x] < e[m].w[x])
					{
						e[m].w[x] = e[buffer].w[x];
					}
					W[m] += e[m].w[x];			 	
				}
				if(Min_weight > W[m] ) 
				{
					Min_weight = W[m];
					Min_weight_f = m;
					cout<<"Min:"<<m<<endl;
				}
			}

			buffer = Min_weight_f;
			cout<<"f: "<<Min_weight_f<<endl;
		}
		
		cout<<Min_weight<<endl;
		fout<<Min_weight<<endl; 
	}
}
