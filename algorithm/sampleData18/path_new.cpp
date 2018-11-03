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
		int x=0;

};
class RR
{
	public:
		int x=0;
		int route=-10;
		int weight=0;
		string str;
};
Path path[100][100];
RR dp[100][100][201];
//////////////////DP 추가 오버플로우 처리 how 경로출력? 

RR Route(int m,int n,int k)//초기화 된값이라고 과정 
{	
	RR &ref = dp[m][n][k];											// k_count 초기값은 path[m-1][n-1].x; 
	if(ref.route != -10)
	{
		return ref;
	}

	if(k<0)
	{
		ref.route=0;
		return ref;
	}
	
	if(m==0&&n==0)
	{
		if(k-path[m][n].x==0)
		{
			ref.route=1;
			ref.weight=0;
			return ref;
		}
		else
		{
			ref.route=0;
			return ref;
		}
	}
	
	if(path[m][n].x==1)
	{
		if(m==0&&n!=0)
		{
			ref = Route(m,n-1,k-1);
			ref.str.append("R");
			ref.weight += path[m][n-1].w_r;
			return ref;
		}
		else if(m!=0&&n==0)
		{
			ref = Route(m-1,n,k-1);
			ref.str.append("D");
			ref.weight += path[m-1][n].w_b;
			return ref;
		}
		else
		{
			RR m_ = Route(m,n-1,k-1);
			RR u_ = Route(m-1,n,k-1);
			m_.weight += path[m][n-1].w_r;
			u_.weight += path[m-1][n].w_b;
			
			if(m_.route!=0 && u_.route!=0)
			{
				if(m_.weight > u_.weight)
				{
					m_.str.append("R");
					m_.route = (m_.route +u_.route)%100000;
					ref = m_;
					return ref;
				}
				else if(m_.weight == u_.weight)
				{
					for(int i=0;;i++)
					{
						if(m_.str[i]!=u_.str[i])
						{
							if(m_.str[i]=='D')
							{
								m_.str.append("R");
								m_.route = (m_.route +u_.route)%100000;
								ref = m_;
								return ref;						
							}
							else
							{
								u_.str.append("D");
								u_.route = (m_.route +u_.route)%100000;
								ref = u_;
								return ref;						
							}
						}
					}
				}
				else
				{
					u_.str.append("D");
					u_.route = (m_.route +u_.route)%100000;
					ref = u_;
					return ref;
				}										
			}
			else if(m_.route==0)
			{
				ref = Route(m-1,n,k-1);
				ref.str.append("D");
				ref.weight += path[m-1][n].w_b;
				return ref;				
			}
			else if(u_.route==0)
			{
				ref = Route(m,n-1,k-1);
				ref.str.append("R");
				ref.weight += path[m][n-1].w_r;
				return ref;			
			}
			else
			{
				ref.route=0;
				return ref;
			}
		}
	}
	else
	{
		if(m==0&&n!=0)
		{
			ref = Route(m,n-1,k);
			ref.str.append("R");
			ref.weight += path[m][n-1].w_r;
			return ref;
		}
		else if(m!=0&&n==0)
		{
			ref = Route(m-1,n,k);
			ref.str.append("D");
			ref.weight += path[m-1][n].w_b;
			return ref;
		}
		else
		{
			RR m_ = Route(m,n-1,k);
			RR u_ = Route(m-1,n,k);
			m_.weight += path[m][n-1].w_r;
			u_.weight += path[m-1][n].w_b;
			
			if(m_.weight > u_.weight)
			{
				m_.str.append("R");
				m_.route = (m_.route +u_.route)%100000;
				ref = m_;
				return ref;
			}
			else if(m_.weight == u_.weight)
			{
				for(int i=0;;i++)
				{
					if(m_.str[i]!=u_.str[i])
					{
						if(m_.str[i]=='D')
						{
							m_.str.append("R");
							m_.route = (m_.route +u_.route)%100000;
							ref = m_;
							return ref;						
						}
						else
						{
							u_.str.append("D");
							u_.route = (m_.route +u_.route)%100000;
							ref = u_;
							return ref;						
						}
					}
				}
			}
			else
			{
				u_.str.append("D");
				u_.route = (m_.route +u_.route)%100000;
				ref = u_;
				return ref;
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
					for(int e=0;e<=K;e++)
					{
						dp[q][w][e].route=-10;
					}			
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
		
		cout<<"Test Case No:"<<i+1<<endl;
		fout<<"Test Case No:"<<i+1<<endl;
		for(int j=0;j<=K;j++)
		{	
			result = Route(M-1,N-1,j);
 
			if(result.route !=0)//경로가없을시 보이지않는다. 
			{
				
				//F(x) k일때 카운트 cost 계산~ count수는 하위 5개자리로 처리~
				//최소비용 cost가 동일시에는 아래 방향으로 먼저 진행하는 경로선택~				
				cout<<"k:"<<j<<" count:"<<result.route<<" cost:"<<result.weight<<endl;
				fout<<"k:"<<j<<" count:"<<result.route<<" cost:"<<result.weight<<endl;
				//cout 경로출력 (0,0) -> (0,2) -> ........ (3,6) 끝 최저비용
				x=0;y=0;
				cout<<"(0,0)";
				fout<<"(0,0)";
				for(int q=0;q<M+N-2;q++)
				{		
					cout<<"->";	
					fout<<"->";
									
					if(result.str[q]=='R') y++;
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
