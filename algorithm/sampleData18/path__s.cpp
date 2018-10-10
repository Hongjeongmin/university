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
		int route=1;
		int weight=0;
		string str;
};

Path path[100][100];
Path dp[100][100][201];
//////////////////DP 추가 오버플로우 처리 how 경로출력? 
Path Route(int m,int n,int k,int k_count)//초기화 된값이라고 과정 
{										// k_count 초기값은 path[m-1][n-1].x; 값 
	//cout<<"시작"<<endl;

	k_count += path[m][n].x;
	
	Path &ref = dp[m][n][k-k_count];
	if(ref.weight !=0 || ref.x==500)
	{
		return ref;
	}
	
	if(k_count > k)
	{
		ref.x=500;
		return 	ref;
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
			ref.x = 500;
			return ref;
		}
		
	}
	else if(m!=0 && n==0)
	{
	//	cout<<"m==0 && n!=0"<<endl;
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
			ref.x =500;
			return ref;
		}
	}
	else
	{
		Path route_m;
		Path route_u;
		//그외~  k-k_count 내가 받아야할값 
		route_m = Route(m,n-1,k,k_count);
		route_u = Route(m-1,n,k,k_count);
 
		if(route_m.x == k-k_count && route_u.x == k-k_count)
		{
			//두경로중 웨이트작은값 선택해서 리턴
			//route수는 두경로에서 왓던수 더해줌~ 
			if(route_m.weight + path[m][n-1].w_r >= route_u.weight + path[m-1][n].w_b )
			{
				//위쪽에서 온게 가중치가 작을경우
				//같은경우도 위에있는걸 채택 
				//경로는 위에 꺼를 가져오거 weight와 x값 수정해서 리턴 
				route_u.weight += path[m-1][n].w_b;
				route_u.x += path[m][n].x;
				route_u.route = (route_u.route%100000 + route_m.route%100000)%100000;
				ref = route_u;
				ref.str.append("D");
				return ref; 
			}
			else
			{
				// 왼쪽에서 온게 가중치가 작을경우
				 route_m.weight += path[m][n-1].w_r;
				 route_m.x += path[m][n].x;
				 route_m.route = (route_m.route%100000 + route_u.route%100000)%100000;
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
			ref.x =500;
			return ref; 
		} 
	}
}

int main(void)
{
	Path result;
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
					path[q][w].str.clear();
					for(int e=0;e<=K;e++)
					{
						dp[q][w][e].x=0;
						dp[q][w][e].weight=0;
						dp[q][w][e].str.clear();
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
		
	//	cout<<"M:"<<M<<"N:"<<N<<"K:"<<K<<endl;
	//	fout<<"Test Case No:"<<i+1<<endl;
		cout<<"Test Case No:"<<i+1<<endl;
		for(int j=0;j<=K;j++)
		{	
			result = Route(M-1,N-1,j,0);
 
			if(result.x != 500)//경로가없을시 보이지않는다. 
			{
				//F(x) k일때 카운트 cost 계산~ count수는 하위 5개자리로 처리~
				//최소비용 cost가 동일시에는 아래 방향으로 먼저 진행하는 경로선택~				
				cout<<"k:"<<j<<" count:"<<result.route<<" cost:"<<result.weight<<endl;
				//fout<<"k:"<<j<<" count:"<<count<<" cost:"<<cost<<endl;
				//cout 경로출력 (0,0) -> (0,2) -> ........ (3,6) 끝 최저비용
				x=0;y=0;
				for(int q=0;q<M+N-2;q++)
				{
					if(q!=0) cout<<"->";
					result.str[q];
				}
				cout<<endl;
			}
		}
		
	}
	fin.close();
	fout.close();
}
