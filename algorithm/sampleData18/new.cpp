#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//int k_count;
class Path
{
	public:
		int w_r;
		int w_b;
		int x=0;// 1 is x sign
		int k=0;

};
class RR
{
	public:
		int x;
		int route=1;
		int weight;
		string str;
};
Path path[100][100];
RR dp[100][100][201];
//////////////////DP 추가 오버플로우 처리 how 경로출력? 
void gogo(int m,int n)
{
	
}

int main(void)
{
	RR result;
	RR count;
	ifstream fin;
	ofstream fout;
	fin.open("path.inp");
	fout.open("path.out");
	int C;
	int M;
	int N;	
	int K;
	int x,y;
	fin>>C;
	
	for(int i=0;i<C;i++)
	{		
		fin>>M;fin>>N;fin>>K;
		
		if(i!=0)
		{
			for(int q=0;q<M;q++)
			{
				for(int w=0;w<N;w++ )
				{
					path[q][w].x=0;
					path[q][w].k=0;	
				}	
			}
		}
				
		for(int j=0;j<K;j++)
		{
			fin>>x;fin>>y;
			path[x][y].x = 1;
		}
		for(int j=0;j<M;j++)
		{
			for(int z=0;z<N-1;z++)
			{
				fin>>path[j][z].w_r;
			}
		}
		for(int j=0;j<M-1;j++)
		{
			for(int z=0;z<N;z++)
			{
				fin>>path[j][z].w_b;
			}
		}
		path[0][0].k=0;
		//////////////////////////////////////////받기끝//// 
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(i==0&&j!=0)
				{
				//맨위에서 왼쪽 
					if(path[i][j-1].k > path[i][j].k )
					{
						path[i][j].k = path[i][j-1].k;	
					} 
					
					for(int q=0;q<path[i][j].k;q++)
					{
						dp[i][j][q].route = 0;
					}
					dp[i][j][path[i][j].k].route = 1;
					//시프트 
					if(path[i][j].x == 1)
					{
						dp[i][j][path[i][j].k].route = 0;
						path[i][j].k ++;
						dp[i][j][path[i][j].k].route = 1;
						
					}
				}
				else if(i!=0&&j==0)
				{
				//맨왼쪽에서 위로 
					if(path[i-1][j].k > path[i][j].k)
					{
						path[i][j].k = path[i-1][j].k;
					}
					for(int q=0;q<path[i][j].k;q++)
					{
						dp[i][j][q].route = 0;
					}
					dp[i][j][path[i][j].k].route = 1;
					if(path[i][j].x ==1)
					{
						dp[i][j][path[i][j].k].route = 0;
						path[i][j].k ++;
						dp[i][j][path[i][j].k].route = 1;						
					}					
				}
				else if(i==0&&j==0)continue;
				else
				{
					//위 왼
					if(path[i][j-1].k > path[i][j].k ) 
					{
						path[i][j].k = path[i][j-1].k;

					}
					
					if(path[i-1][j].k > path[i][j].k)
					{
						path[i][j].k = path[i-1][j].k;
					}
					// 왼 위 중에 더큰 k값으로 간다. 
					//dp 초기화 
					for(int q=0;q<=path[i][j].k;q++)
					{
						dp[i][j][q].route = 0;			
					}		 
					for(int q=0; q <= path[i-1][j].k;q++)
					{
						if(dp[i-1][j][q].route == 0)
						{
							continue;
						}
						else if((dp[i-1][j][q].route + dp[i][j][q].route) % 1000000 == 0)
						{
							dp[i][j][q].route=100000;
						}
						else
						{
							dp[i][j][q].route = (dp[i][j][q].route + dp[i-1][j][q].route) % 1000000;
						}				
					}
					for(int q=0; q <= path[i][j-1].k;q++)
					{
						if(dp[i][j-1][q].route == 0)
						{
							continue;
						}
						else if((dp[i][j-1][q].route + dp[i][j][q].route) % 1000000 == 0)
						{
							dp[i][j][q].route=100000;
						}
						else
						{
							dp[i][j][q].route = (dp[i][j][q].route + dp[i][j-1][q].route) % 1000000;
						}				
					}				
					// 마킹되어있으면 시프트 시킨다 
					if(path[i][j].x==1)
					{
						path[i][j].k++;
						for(int q = path[i][j].k;q>0;q--)
						{
							dp[i][j][q].route = dp[i][j][q-1].route;
						}
						
						dp[i][j][0].route=0;
					}
					//시프트완료~ 				
				}
			}
		}
		
		RR tmp1;
		RR tmp2;
		///////////////////////////cost 값 구하기
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<"i:"<<i<<endl;
				if(i<M-1)
				{
					for(int q=0;q<=path[i][j].k;q++)
					{
						if(dp[i+1][j][q + path[i+1][j].x].weight > dp[i][j][q].weight + path[i][j].w_b )
						{
							dp[i+1][j][q + path[i+1][j].x].weight = dp[i][j][q].weight + path[i][j].w_b;
							dp[i+1][j][q + path[i+1][j].x].str = dp[i][j][q].str.append("D");
						}
						else if(dp[i+1][j][q + path[i+1][j].x].weight == dp[i][j][q].weight + path[i][j].w_b )
						{
							for(int w=0;;w++)
							{
								if(dp[i+1][j][q + path[i+1][j].x].str[w] != dp[i][j][q].str[w])
								{
									if(dp[i][j][q].str[w] == 'D')
									{
										dp[i+1][j][q + path[i+1][j].x].str = dp[i][j][q].str.append("D");
										break;
									}
									else
									{
										break;
									}
									
								}
							}
						}
						
					}

				}
				
				if(j<N-1)
				{
					for(int q=0;q<=path[i][j].k;q++)
					{
						if(dp[i][j+1][q + path[i][j+1].x].weight > dp[i][j][q].weight + path[i][j].w_r )
						{
							dp[i][j+1][q + path[i][j+1].x].weight = dp[i][j][q].weight + path[i][j].w_r;
							dp[i][j+1][q + path[i][j+1].x].str = dp[i][j][q].str.append("R");
						}
						else if(dp[i][j+1][q + path[i][j+1].x].weight == dp[i][j][q].weight + path[i][j].w_r )
						{
							for(int w=0;;w++)
							{
								if(dp[i][j+1][q + path[i][j+1].x].str[w] != dp[i][j][q].str[w])
								{
									if(dp[i][j][q].str[w] == 'D')
									{
										dp[i][j][q + path[i+1][j].x].str = dp[i][j][q].str.append("R");
										break;
									}
									else
									{
										break;
									}
									
								}
							}
						}
						
					}
				}	
			}
		}
		
		
		
		/////////////////////////////////////// 

		//	출력시작~~~~~~~~~~~~~~~ 
		fout<<"Test Case No:"<<i+1<<endl;
		cout<<"Test Case No:"<<i+1<<endl;
		for(int j=0;j<=path[M-1][N-1].k;j++)
		{	
 
			if(dp[M-1][N-1][j].route !=0)//경로가없을시 보이지않는다. 
			{					
				cout<<"k:"<<j<<" count:"<<dp[M-1][N-1][j].route%100000<<" cost:"<<dp[M-1][N-1][j].weight<<endl;
				fout<<"k:"<<j<<" count:"<<dp[M-1][N-1][j].route%100000<<" cost:"<<dp[M-1][N-1][j].weight<<endl;
				//cout 경로출력 (0,0) -> (0,2) -> ........ (3,6) 끝 최저비용
				x=0;y=0;
				cout<<"(0,0)";
				fout<<"(0,0)";
				for(int q=0;q<M+N-2;q++)
				{		
					cout<<"->";	
					fout<<"->";
									
					if(dp[M-1][N-1][j].str[q]=='R') y++;
					else x++;
					
					cout<<"("<<x<<","<<y<<")";
					fout<<"("<<x<<","<<y<<")";
				}
				cout<<endl;
				fout<<endl;
			}
		}
		cout<<endl;
		fout<<endl;
		
	}
	fin.close();
	fout.close();
}
