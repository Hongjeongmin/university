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

};
class RR
{
	public:
		int x=0;
		int route=1;
		int weight=0;
		string str;
};
Path path[100][100];
RR dp[100][100][201];
//////////////////DP 추가 오버플로우 처리 how 경로출력? 

RR Route(int m,int n,int k,int k_count)//초기화 된값이라고 과정 
{										// k_count 초기값은 path[m-1][n-1].x; 값 
	k_count += path[m][n].x;
	
	if(k_count >k)
	{
		RR X;
		X.x=500;
		X.weight=1;
		return X;
	}		

	RR &ref = dp[m][n][k-k_count];
	if(ref.weight !=0)
	{
		return ref;
	}

	if(m==0 && n==0)
	{
		//끝노드도착~ 
		ref.x = path[0][0].x;
		ref.weight=0;
		return ref;
	}
	else if(m==0 && n!=0)
	{
	//	cout<<"m!= && n==0"<<endl;
		//맨꼭대기에서 왼쪽으로만 가는경우~ 
		ref = Route(m,n-1,k,k_count);

		if(ref.x == k-k_count)
		{
			ref.weight += path[m][n-1].w_r;
			ref.x += path[m][n].x;
			ref.str.append("R");
			return ref; 
		}
		else
		{
			ref.weight=1;
			ref.x = 500;
			return ref;
		}
		
	}
	else if(m!=0 && n==0)
	{
		//맨왼쪽에서 위쪽으로만 가는경우~
		ref = Route(m-1,n,k,k_count);
		if(ref.x == k-k_count)
		{
			ref.weight += path[m-1][n].w_b;
			ref.x += path[m][n].x;
			ref.str.append("D");
			return ref;		
		}
		else
		{
			ref.weight=1;
			ref.x =500;
			return ref;
		}
	}
	else
	{
		RR route_m;
		RR route_u;
		//그외~  k-k_count 내가 받아야할값 
		route_m = Route(m,n-1,k,k_count);
		route_u = Route(m-1,n,k,k_count);
 
		if(route_m.x == k-k_count && route_u.x == k-k_count)
		{

			if(route_m.weight + path[m][n-1].w_r > route_u.weight + path[m-1][n].w_b )
			{
				route_u.weight += path[m-1][n].w_b;
				route_u.x += path[m][n].x;
				route_u.route = (route_u.route + route_m.route)%100000;
				ref = route_u;
				ref.str.append("D");
				return ref; 
			}
			else if(route_m.weight + path[m][n-1].w_r == route_u.weight + path[m-1][n].w_b)
			{
				for(int i=0;;i++)
				{
					if(route_m.str[i] != route_u.str[i])
					{
						if(route_m.str[i] == 'D')
						{
							 route_m.weight += path[m][n-1].w_r;
							 route_m.x += path[m][n].x;
							 route_m.route = (route_u.route + route_m.route)%100000;
							 ref = route_m;
							 ref.str.append("R");
							 return ref;						
						}
						else
						{
							route_u.weight += path[m-1][n].w_b;
							route_u.x += path[m][n].x;
							route_u.route = (route_u.route + route_m.route)%100000;
							ref = route_u;
							ref.str.append("D");
							return ref; 							
						}
						
					}
					
				}
			}
			else
			{
				// 왼쪽에서 온게 가중치가 작을경우
				 route_m.weight += path[m][n-1].w_r;
				 route_m.x += path[m][n].x;
				 route_m.route = (route_u.route + route_m.route)%100000;
				 ref = route_m;
				 ref.str.append("R");
				 return ref;
			}
		}
		else if(route_m.x== k-k_count)
		{
			//왼쪽에서 오는놈 경로채택 
			 route_m.weight += path[m][n-1].w_r;
			 route_m.x += path[m][n].x;
			 ref = route_m;
			 ref.str.append("R");
			 return ref;			
		} 
		else if(route_u.x==k-k_count)
		{
			//위쪽에서 오는놈 경로채택
			route_u.weight += path[m-1][n].w_b;
			route_u.x += path[m][n].x;
			ref = route_u;
			ref.str.append("D");
			return ref;			 
		}
		else
		{
			//둘다채택하지않음
			ref.weight=1;
			ref.x =500;
			return ref; 
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
						dp[q][w][e].weight=0;
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
			result = Route(M-1,N-1,j,0);
 
			if(result.x != 500 && result.route !=0)//경로가없을시 보이지않는다. 
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
