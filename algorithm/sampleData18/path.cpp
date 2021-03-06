#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int INF = 300012342;
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
		int route=1;
		int weight=0;
		string str;
};
Path path[100][100];
RR dp[100][100][201];
//////////////////DP 추가 오버플로우 처리 how 경로출력? 
void gogo(int M,int N)
{
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(i<M-1)
			{
				for(int q=0;q<=path[i][j].k;q++)
				{
					dp[i+1][j][q + path[i+1][j].x].weight = dp[i][j][q].weight + path[i][j].w_b;
					dp[i+1][j][q + path[i+1][j].x].str = dp[i][j][q].str;
					dp[i+1][j][q + path[i+1][j].x].str.append("D");
				}
			}
			
			if(j<N-1 && i!=0)
			{
				for(int q=0;q<=path[i][j].k;q++)
				{
					if(dp[i][j+1][q + path[i][j+1].x].weight > dp[i][j][q].weight + path[i][j].w_r)
					{
						dp[i][j+1][q + path[i][j+1].x].weight = dp[i][j][q].weight + path[i][j].w_r;
						dp[i][j+1][q + path[i][j+1].x].str = dp[i][j][q].str;
						dp[i][j+1][q + path[i][j+1].x].str.append("R");
					}
					else if(dp[i][j+1][q + path[i][j+1].x].weight == dp[i][j][q].weight + path[i][j].w_r)
					{
						for(int w=0;;w++)
						{
							if(dp[i][j][q].str[w] == 'D' && dp[i][j+1][q + path[i][j+1].x].str[w] == 'R')
							{
								dp[i][j+1][q + path[i][j+1].x].str = dp[i][j][q].str;
								dp[i][j+1][q + path[i][j+1].x].str.append("R");
								break;
							}
						}
					}
				}
			}
			else if(j<N-1 && i==0)
			{
				for(int q=0;q<=path[i][j].k;q++)
				{
					dp[i][j+1][q + path[i][j+1].x].weight = dp[i][j][q].weight + path[i][j].w_r;
					dp[i][j+1][q + path[i][j+1].x].str = dp[i][j][q].str;
					dp[i][j+1][q + path[i][j+1].x].str.append("R");
				}				
			}
		}
	}
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
	dp[0][0][0].weight=0;
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
		//////////////////////////////////////////받기끝//// 
		for(int a=0;a<M;a++)
		{
			for(int b=0;b<N;b++)
			{
				if(a==0&&b!=0)
				{
				//맨위에서 왼쪽 
					if(path[a][b-1].k > path[a][b].k )
					{
						path[a][b].k = path[a][b-1].k;	
					} 
					
					for(int q=0;q<path[a][b].k;q++)
					{
						dp[a][b][q].route = 0;
						dp[a][b][q].weight =INF;
						dp[a][b][path[a][b].k].str="";
					}
					dp[a][b][path[a][b].k].route = 1;
					dp[a][b][path[a][b].k].weight =INF;
					dp[a][b][path[a][b].k].str="";
					
					//시프트 
					if(path[a][b].x == 1)
					{
						dp[a][b][path[a][b].k].route = 0;					
						dp[a][b][path[a][b].k].weight =INF;
						dp[a][b][path[a][b].k].str="";						
						path[a][b].k ++;
						dp[a][b][path[a][b].k].route = 1;
						dp[a][b][path[a][b].k].weight =INF;
						dp[a][b][path[a][b].k].str="";
					}
				}
				else if(a!=0&&b==0)
				{
				//맨왼쪽에서 위로 
					if(path[a-1][b].k > path[a][b].k)
					{
						path[a][b].k = path[a-1][b].k;
					}
					for(int q=0;q<path[a][b].k;q++)
					{
						dp[a][b][q].route = 0;
						dp[a][b][q].weight =INF;
						dp[a][b][q].str="";
					}
					dp[a][b][path[a][b].k].route = 1;
					dp[a][b][path[a][b].k].weight =INF;
					dp[a][b][path[a][b].k].str="";
					if(path[a][b].x ==1)
					{
						dp[a][b][path[a][b].k].route = 0;
						dp[a][b][path[a][b].k].weight = INF;
						dp[a][b][path[a][b].k].str="";
						path[a][b].k ++;
						dp[a][b][path[a][b].k].route = 1;
						dp[a][b][path[a][b].k].weight = INF;
						dp[a][b][path[a][b].k].str="";												
					}					
				}
				else if(a==0&&b==0)continue;
				else
				{
					//위 왼
					if(path[a][b-1].k > path[a][b].k ) 
					{
						path[a][b].k = path[a][b-1].k;

					}
					
					if(path[a-1][b].k > path[a][b].k)
					{
						path[a][b].k = path[a-1][b].k;
					}
					// 왼 위 중에 더큰 k값으로 간다. 
					//dp 초기화 
					for(int q=0;q<=path[a][b].k;q++)
					{
						dp[a][b][q].route = 0;
						dp[a][b][q].weight = INF;	
						dp[a][b][q].str="";
					}		 
					for(int q=0; q <= path[a-1][b].k;q++)
					{
						if(dp[a-1][b][q].route == 0)
						{
							continue;
						}
						else if((dp[a-1][b][q].route + dp[a][b][q].route) % 1000000 == 0)
						{
							dp[a][b][q].route=100000;	
						}
						else
						{
							dp[a][b][q].route = (dp[a][b][q].route + dp[a-1][b][q].route) % 1000000;
						}				
					}
					for(int q=0; q <= path[a][b-1].k;q++)
					{
						if(dp[a][b-1][q].route == 0)
						{
							continue;
						}
						else if((dp[a][b-1][q].route + dp[a][b][q].route) % 1000000 == 0)
						{
							dp[a][b][q].route=100000;						
						}
						else
						{
							dp[a][b][q].route = (dp[a][b][q].route + dp[a][b-1][q].route) % 1000000;						
						}				
					}				
					// 마킹되어있으면 시프트 시킨다 
					if(path[a][b].x==1)
					{
						path[a][b].k++;
						
						dp[a][b][path[a][b].k].weight=INF;
						dp[a][b][path[a][b].k].str="";
						for(int q = path[a][b].k;q>0;q--)
						{
							dp[a][b][q].route = dp[a][b][q-1].route;
						}
						dp[a][b][0].str="";
						dp[a][b][0].route=0;
						dp[a][b][0].weight=INF;
					}
					//시프트완료~ 				
				}
			}
		}
/*
			for(int w=0;w<M;w++)
			{
				for(int e=0;e<N;e++)
				{
					cout<<path[w][e].k<<" ";
				}
				cout<<endl;
			}
*/			
		///////////////////////////cost 값 구하기
		
		gogo(M,N);
		/*
		for(int q=0;q<=path[M-1][N-1].k;q++)
		{
			cout<<"K: "<<q<<endl;
			for(int w=0;w<M;w++)
			{
				for(int e=0;e<N;e++)
				{
					cout<<dp[w][e][q].weight<<" ";
				}
				cout<<endl;
			}
		}
		*/
		
		/////////////////////////////////////// 

		//	출력시작~~~~~~~~~~~~~~~ 
		fout<<"Test Case No:"<<i+1<<endl;
	//	cout<<"Test Case No:"<<i+1<<endl;
		for(int j=0;j<=path[M-1][N-1].k;j++)
		{	
 
			if(dp[M-1][N-1][j].route !=0 && dp[M-1][N-1][j].route% 100000 !=0)//경로가없을시 보이지않는다. 
			{					
		//		cout<<"k:"<<j<<" count:"<<dp[M-1][N-1][j].route%100000<<" cost:"<<dp[M-1][N-1][j].weight<<endl;
				fout<<"k:"<<j<<" count:"<<dp[M-1][N-1][j].route % 100000<<" cost:"<<dp[M-1][N-1][j].weight<<endl;
		
				x=0;y=0;

				for(int q=0;q<dp[M-1][N-1][j].str.size();q++)
				{		
					fout<<"("<<x<<","<<y<<")";
					fout<<"->";
									
					if(dp[M-1][N-1][j].str[q]=='R') y++;
					else x++;
				}
		//		cout<<endl;
				fout<<"("<<M-1<<","<<N-1<<")"<<endl;
			//	fout<<endl;
			}
		}
	//	cout<<endl;
		fout<<endl;
		
	}
	fin.close();
	fout.close();
}
