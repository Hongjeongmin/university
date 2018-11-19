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
		int f;//����
		int down;//�������� ����ġ 
		int up; //�ö󰥶� ����ġ 
				
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
	
	fin>>T; // case �Է� 
		
	for(int i=1;i<=T;i++)
	{
		fin>>n;fin>>k;//������� ��� �������� ����~
		for(int j=1;j<=n;j++)//��ǲ ���� �ޱ� �� 
		{
			fin>>C[j].f;fin>>C[j].down;fin>>C[j].up;	
		} 
		
		//dp 1���ױ� 
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
		//dp 2�� ���� �ױ� 
		//if(i==2) cout<<"ddd"<<e[5].w[4]<<endl;
		for(int j=2;j<=k;j++)
		{
			Min_weight = INF;
			for(int m=1;m<=200;m++)
			{
				W[m] = 0;//��Ϻ� ����ġ �ʱ�ȭ; 
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
