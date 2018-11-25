#include<iostream>
#include<fstream>
#include<algorithm>
#include<stdio.h>
using namespace std;

typedef struct Data
{
	int f;//층수
	int down;//내려갈때 가중치 
	int up; //올라갈때 가중치 	
}data;
typedef struct dd
{
	int w[501];
}DD;
int W[201][201];//sum of weight
data C[501]; // input data

//int dp[501][201][201]; // dp 문제 
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
	
	fin>>T; // case 입력 
	for(int i=1;i<=T;i++)
	{
		MAX_F=0;
		fin>>n;fin>>k;//사람수와 층몇개 선택할지 고르자~
		for(int x=1 ; x<=n ; x++)//인풋 파일 받기 끝 
		{
			fin>>C[x].f;
			fin>>C[x].down; 
			fin>>C[x].up;
			MAX_F = max(C[x].f,MAX_F);
		} 
		// K=0 일때 쌓기 이때는 엘베는 1층에 고정
		W[0][1] = 0;
		for(int x = 1; x<=n ; x++)
		{
		//	dp[x][1][0] = (C[x].f - 1) * C[x].up;
			dp[0][1].w[x] =  (C[x].up) * ((C[x].f) - 1);
		//	W[0][1] += dp[x][1][0];			
			W[0][1] += dp[0][1].w[x];
		}
		//cout<<C[370].f<<endl; 
		
		// k=0 이라면 엘베를 어느곳에 골라도 값이 다 똑같음
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
		// k=0 일때 다채웟으니 이제 k=1 부터 채우면 된다.		
		// k = 1 부터 쌓자 
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
				else if(m-1 == j)// 경계선 정하기 K=1 m=2층 k=2 m=3층  k=3 m=4층 
				{
				//	W[j][m] = 0;
					for(int x=1;x<=n;x++)
					{
						if(C[x].f>m) // 원하는 층 보다 나는 위에 잇을 때 
						{
							//이전 dp와 비교해서 더작은걸 최신화 
							//tmp = min(dp[x][m-1][j-1],(C[x].f - m) * C[x].up);	
							tmp = min(dp[j-1][m-1].w[x],(C[x].f - m) * C[x].up);	
						}
						else if(C[x].f<m) //원하는층 보다 나는 밑에잇을 때 
						{
							//이전 dp 와 비교해서 더작은걸 최신화 
 
							//tmp = min(dp[x][m-1][j-1] ,(m-C[x].f) * C[x].down);
							tmp = min(dp[j-1][m-1].w[x] ,(m-C[x].f) * C[x].down);
						}
						else//원하는층과 현재층이 일치할때 
						{
							tmp = 0;
						}
					//	dp[x][m][j] = tmp;
						dp[j][m].w[x] = tmp;
						W[j][m] += tmp; 	
					}					
				}
				else if(j>=m)// k값이 층수보다 클 경우 즉 어떻게해도 k게 밖에 못뽑으니 이전 dp에서 가져온다 
				{
					/*
					for(int x = 1; x<=n ; x++)
					{
						// k가 층수를 초과하면 결국 그층수까지 최대값이므로 이전 dp에서
						// k가 m-1 1층을 포함 하기 때문에 m까지의 값을 가져오면 된다. 
						dp[x][m][j] = dp[x][m][m-1];
					}
					*/
					copy(dp[m-1][m].w,dp[m-1][m].w+n+1,dp[j][m].w);					
					W[j][m] =  W[m-1][m];
				}
				else
				{
					//직전층 dp 웨이트합 가져오기 
					candidate_w = W[j][m-1]; 
					W[j][m] = candidate_w;
					/*
					for(int x=1;x<=n;x++)
					{
						dp[x][m][j] = dp[x][m-1][j];
					}
					*/
					copy(dp[j][m-1].w,dp[j][m-1].w+n+1,dp[j][m].w);
					//// 이제 k-1 값에서 찾을거임 제일작은 합을 가지는 녀석으로
					if(j!=1)
					{
						for(int past = j;past<m;past++)
						{
							tmp_w=0;
							for(int x=1;x<=n;x++)
							{
								if(C[x].f>m) // 원하는 층 보다 나는 위에 잇을 때 
								{
								//	tmp = min(dp[x][past][j-1],(C[x].f - m) * C[x].up);		
									tmp = min(dp[j-1][past].w[x],(C[x].f - m) * C[x].up);
								}
								else if(C[x].f<m) //원하는층 보다 나는 밑에잇을 때 
								{
								//	tmp = min(dp[x][past][j-1] ,(m-C[x].f) * C[x].down);
									tmp = min(dp[j-1][past].w[x],(m-C[x].f) * C[x].down);
								}
								else//원하는층과 현재층이 일치할때 
								{
									tmp = 0;
								}
								//candidate[x] = tmp;
								candidate.w[x] = tmp;
								tmp_w += tmp; 	
							}						
							if(candidate_w > tmp_w) //후보가 더크다? 
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
							if(C[x].f>m) // 원하는 층 보다 나는 위에 잇을 때 
							{
							//	tmp = min(dp[x][1][0],(C[x].f - m) * C[x].up);		
								tmp = min(dp[0][1].w[x],(C[x].f - m) * C[x].up);
							}
							else if(C[x].f<m) //원하는층 보다 나는 밑에잇을 때 
							{
							//	tmp = min(dp[x][1][0] ,(m-C[x].f) * C[x].down);
								tmp = min(dp[0][1].w[x],(m-C[x].f) * C[x].down);
							}
							else//원하는층과 현재층이 일치할때 
							{
								tmp = 0;
							}
						//	candidate[x] = tmp;
							candidate.w[x] = tmp;
							tmp_w += tmp; 	
						}						
						if(candidate_w > tmp_w) //후보가 더크다? 
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
