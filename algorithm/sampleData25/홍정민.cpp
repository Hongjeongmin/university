#include<iostream>8
#include<fstream>
#define INF 987654321
using namespace std;

class data
{
	public:
		int f;//����
		int down;//�������� ����ġ 
		int up; //�ö󰥶� ����ġ 
				
};
typedef struct dd
{
	int w[501];
}DD;

int W[201][201];//sum of weight
//int W_min[201];
data C[501]; // input data

DD dp[201][201]; // dp ���� 
int tmp[501];
int tmp_[501];
int candidate[501];
int candidate_w;
int tmp_w;

int main(void)
{
	int T;
	int n;
	int k;
	int Min_weight_f;
	int Min_weight;
	int buffer;
	int MAX_F;
	ifstream fin;
	ofstream fout;
	
	fin.open("test.inp");
	fout.open("elevator.out");
	
	fin>>T; // case �Է� 
	for(int i=1;i<=T;i++)
	{
		MAX_F=0;
		fin>>n;fin>>k;//������� ��� �������� ����~
		for(int j=1;j<=n;j++)//��ǲ ���� �ޱ� �� 
		{
			fin>>C[j].f;fin>>C[j].down;fin>>C[j].up;
			MAX_F = max(C[j].f,MAX_F);
		} 
///////////// k=1 �ױ� ///////////////////////////////////////
	//	W_min[1] = INF;
		for(int m=2;m<=MAX_F;m++)
		{
			
			W[1][m] = 0;
			for(int x=1;x<=n;x++)
			{
					if(C[x].f>m)
					{
						dp[1][m].w[x] = (C[x].f - m) * C[x].up;
				//		W[1][m] += dp[x][m][1];		
					}
					else
					{
						if((C[x].f-1) * C[x].up  > (m-C[x].f) * C[x].down )
						{
							dp[1][m].w[x] = (m-C[x].f) * C[x].down;
						}
						else
						{
							dp[1][m].w[x] =(C[x].f-1) * C[x].up;
						}
						W[1][m] += dp[1][m].w[x];
					} 	
			}	
		}
//////////////////////////////////////////////////////////////
		for(int j=2;j<=k;j++)
		{
		//	W_min[j] = INF;			
		//	cout<<"K: "<<j<<endl;
			for(int m=j;m<=MAX_F;m++)
			{	
				///////// ���� ���õ��� �������� ���� ����
				candidate_w=0;
				
				for(int x=1;x<=n;x++)
				{
					if(C[x].f>m)
					{
						tmp_[x] = (C[x].f - m) * C[x].up;		
					}
					else
					{
						if((C[x].f-1) * C[x].up  > (m-C[x].f) * C[x].down )
						{
							tmp_[x] = (m-C[x].f) * C[x].down;
						}
						else
						{
							tmp_[x] =(C[x].f-1) * C[x].up;
						}
					}
					candidate_w += tmp_[x]; 	
				}	
				
				for(int past=m+1;past<=MAX_F;past++)
				{
					tmp_w=0;
					//���� ���ÿ����� w�� ���ϱ�
					for(int x=1;x<=n;x++)
					{
						tmp[x] = tmp_[x];
						if(dp[j-1][past].w[x] < tmp[x])
						{
							tmp[x] = dp[j-1][past].w[x];
						}
						tmp_w += tmp[x];					
					}						
					
					//���� ���ð� ���ؼ� �۴ٸ� ���� 
					if(candidate_w > tmp_w)
					{
					//	cnt = past;
						candidate_w = tmp_w;
					//	for(int x=1;x<=n;x++)
					//	{
					//		candidate[x] = tmp[x];
					//	}
					copy(tmp,tmp+n+1,candidate);
					}
				}
				W[j][m] = candidate_w;
				//���������� ���� �ĺ��� dp�� ������ 
			//	for(int x=1;x<=n;x++)
			//	{
			//		dp[x][m][j] = candidate[x];
			//	}
				copy(candidate,candidate+n+1,dp[j][m].w);	
			}
		//	cout<<"K: "<<j<<"���������� ���õ� m: "<<cnt<<endl;
		}

		cout<<W[k][MAX_F]<<endl;
		fout<<W[k][MAX_F]<<endl;
	}
}
