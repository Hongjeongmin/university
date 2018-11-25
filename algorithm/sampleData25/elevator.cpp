#include<iostream>
#include<fstream>
#include<algorithm>
#include<stdio.h>
using namespace std;

typedef struct Data
{
	int f;//����
	int down;//�������� ����ġ 
	int up; //�ö󰥶� ����ġ 	
}data;
typedef struct dd
{
	int w[501];
}DD;
int W[201][201];//sum of weight
data C[501]; // input data

//int dp[501][201][201]; // dp ���� 
DD dp[201][201];
int tmp;
int tmp_w;
DD candidate;
int candidate_w; 

int main(void)
{
	int T;
	int n;
	int k;
	int MAX_F;
	ifstream fin;
	ofstream fout;
	
	fin.open("elevator.inp");
	fout.open("elevator.out");
	
	fin>>T; // case �Է� 
	for(int i=1;i<=T;i++)
	{
		MAX_F=0;
		fin>>n;fin>>k;//������� ��� �������� ����~
		for(int x=1 ; x<=n ; x++)//��ǲ ���� �ޱ� �� 
		{
			fin>>C[x].f;
			fin>>C[x].down; 
			fin>>C[x].up;
			MAX_F = max(C[x].f,MAX_F);
		} 
		// K=0 �϶� �ױ� �̶��� ������ 1���� ����
		W[0][1] = 0;
		for(int x = 1; x<=n ; x++)
		{
		//	dp[x][1][0] = (C[x].f - 1) * C[x].up;
			dp[0][1].w[x] =  (C[x].up) * ((C[x].f) - 1);
		//	W[0][1] += dp[x][1][0];			
			W[0][1] += dp[0][1].w[x];
		}
		//cout<<C[370].f<<endl; 
		
		// k=0 �̶�� ������ ������� ��� ���� �� �Ȱ���
		for(int m=2;m<=MAX_F;m++)
		{
			/*
			for(int x = 1; x<=n ; x++)
			{
				dp[x][m][0] = dp[x][1][0];
			}
			*/
			copy(dp[0][1].w,dp[0][1].w+n+1,dp[0][m].w);
			W[0][m] = W[0][1];
		}
		// k=0 �϶� ��ä�m���� ���� k=1 ���� ä��� �ȴ�.		
		// k = 1 ���� ���� 
		for(int j=1;j<=k;j++)
		{
			for(int m=1;m<=MAX_F;m++)
			{
				if(m==1)
				{
					/*
					for(int x = 1; x<=n ; x++)
					{
						dp[x][m][j] = dp[x][1][0];
					}
					*/
					copy(dp[0][1].w,dp[0][1].w+n+1,dp[j][m].w);
					W[j][m] = W[0][1];				
				}
				else if(m-1 == j)// ��輱 ���ϱ� K=1 m=2�� k=2 m=3��  k=3 m=4�� 
				{
				//	W[j][m] = 0;
					for(int x=1;x<=n;x++)
					{
						if(C[x].f>m) // ���ϴ� �� ���� ���� ���� ���� �� 
						{
							//���� dp�� ���ؼ� �������� �ֽ�ȭ 
							//tmp = min(dp[x][m-1][j-1],(C[x].f - m) * C[x].up);	
							tmp = min(dp[j-1][m-1].w[x],(C[x].f - m) * C[x].up);	
						}
						else if(C[x].f<m) //���ϴ��� ���� ���� �ؿ����� �� 
						{
							//���� dp �� ���ؼ� �������� �ֽ�ȭ 
 
							//tmp = min(dp[x][m-1][j-1] ,(m-C[x].f) * C[x].down);
							tmp = min(dp[j-1][m-1].w[x] ,(m-C[x].f) * C[x].down);
						}
						else//���ϴ����� �������� ��ġ�Ҷ� 
						{
							tmp = 0;
						}
					//	dp[x][m][j] = tmp;
						dp[j][m].w[x] = tmp;
						W[j][m] += tmp; 	
					}					
				}
				else if(j>=m)// k���� �������� Ŭ ��� �� ����ص� k�� �ۿ� �������� ���� dp���� �����´� 
				{
					/*
					for(int x = 1; x<=n ; x++)
					{
						// k�� ������ �ʰ��ϸ� �ᱹ ���������� �ִ밪�̹Ƿ� ���� dp����
						// k�� m-1 1���� ���� �ϱ� ������ m������ ���� �������� �ȴ�. 
						dp[x][m][j] = dp[x][m][m-1];
					}
					*/
					copy(dp[m-1][m].w,dp[m-1][m].w+n+1,dp[j][m].w);					
					W[j][m] =  W[m-1][m];
				}
				else
				{
					//������ dp ����Ʈ�� �������� 
					candidate_w = W[j][m-1]; 
					W[j][m] = candidate_w;
					/*
					for(int x=1;x<=n;x++)
					{
						dp[x][m][j] = dp[x][m-1][j];
					}
					*/
					copy(dp[j][m-1].w,dp[j][m-1].w+n+1,dp[j][m].w);
					//// ���� k-1 ������ ã������ �������� ���� ������ �༮����
					if(j!=1)
					{
						for(int past = j;past<m;past++)
						{
							tmp_w=0;
							for(int x=1;x<=n;x++)
							{
								if(C[x].f>m) // ���ϴ� �� ���� ���� ���� ���� �� 
								{
								//	tmp = min(dp[x][past][j-1],(C[x].f - m) * C[x].up);		
									tmp = min(dp[j-1][past].w[x],(C[x].f - m) * C[x].up);
								}
								else if(C[x].f<m) //���ϴ��� ���� ���� �ؿ����� �� 
								{
								//	tmp = min(dp[x][past][j-1] ,(m-C[x].f) * C[x].down);
									tmp = min(dp[j-1][past].w[x],(m-C[x].f) * C[x].down);
								}
								else//���ϴ����� �������� ��ġ�Ҷ� 
								{
									tmp = 0;
								}
								//candidate[x] = tmp;
								candidate.w[x] = tmp;
								tmp_w += tmp; 	
							}						
							if(candidate_w > tmp_w) //�ĺ��� ��ũ��? 
							{
								candidate_w = tmp_w;
								
								W[j][m] = candidate_w;
								/*
								for(int x=1;x<=n;x++)
								{
									dp[x][m][j] = candidate[x];
								}
								*/
								copy(candidate.w,candidate.w+n+1,dp[j][m].w);							 
							}
						} 				
					}
					else
					{
						tmp_w=0;
						for(int x=1;x<=n;x++)
						{
							if(C[x].f>m) // ���ϴ� �� ���� ���� ���� ���� �� 
							{
							//	tmp = min(dp[x][1][0],(C[x].f - m) * C[x].up);		
								tmp = min(dp[0][1].w[x],(C[x].f - m) * C[x].up);
							}
							else if(C[x].f<m) //���ϴ��� ���� ���� �ؿ����� �� 
							{
							//	tmp = min(dp[x][1][0] ,(m-C[x].f) * C[x].down);
								tmp = min(dp[0][1].w[x],(m-C[x].f) * C[x].down);
							}
							else//���ϴ����� �������� ��ġ�Ҷ� 
							{
								tmp = 0;
							}
						//	candidate[x] = tmp;
							candidate.w[x] = tmp;
							tmp_w += tmp; 	
						}						
						if(candidate_w > tmp_w) //�ĺ��� ��ũ��? 
						{	
							W[j][m] = tmp_w;
							/*
							for(int x=1;x<=n;x++)
							{
								dp[x][m][j] = candidate[x];
							}
							*/
							copy(candidate.w,candidate.w+n+1,dp[j][m].w);							 
						}						
					}			
				} 
			}
		}
//		cout<<W[k][MAX_F]<<endl;
		fout<<W[k][MAX_F]<<endl;
		/*
		for(int q=0;q<=k;q++)
		{
			for(int w=1;w<=MAX_F;w++)
			{
				cout<<W[q][w]<<" ";	
			}	
			cout<<endl;
		}		 
		*/
	}
	fin.close();
	fout.close();
	return 0;
}
