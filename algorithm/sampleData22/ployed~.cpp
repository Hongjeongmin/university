#include<iostream>
#include<fstream>
#define INF 987654321
using namespace std;

int T;// 0~90 테스트케이스 
int N;// 1~500 정점의 개수 
int M;// 1~10000 간선의수 
int K;// 1~3 질문의 개수 
int result1,result2;
class Dp
{
	public:
		int i;
		int j;
};
Dp dp[501][501];

int D[501][501]={0};
int P[501][501][501]={0};
void Swap(int& a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
void Qurey(int a,int b,double distance)
{
	int tmp;
	for(int i=0;;i++)
	{
		tmp = P[a][b][i];
		if(tmp==-1) break;
		
	//	if(i!=0) cout<<a<<" "<<b<<"루틴:"<<i<<" "<<i<<" "<<i<<" "<<i<<endl;
		
		if(tmp==0)
		{
		//	cout<<"a-b:"<<a<<"-"<<b<<endl;
			if(a>b) Swap(a,b);
			
			if(result1>a)
			{
				result1=a;result2=b;
			}
			else if(result1==a&&result2>b)
			{
				result2=b;
			}
		}
		else
		{
			if(distance-D[a][tmp]<0)
			{
				//왼쪽에잇다 distance는 그대로 넘겨주자 
		//		cout<<"왼쪽에있다"<<endl; 
			 	Qurey(a,tmp,distance);
			}
			else if(distance-D[a][tmp]>0)
			{
				//오른쪽에잇다  distance는 a~tmp 값을 뺀것을 넘겨주자
		//		cout<<"오른쪽에있다"<<endl;
				Qurey(tmp,b,distance-D[a][tmp]); 
			}
			else
			{
				//같을때 tmp에서 만난다
		//		cout<<"i-i"<<endl;
				if(result1>tmp)
				{
					result1 = tmp;result2=tmp;
				} 
				else if(result1==tmp&&result2>tmp)
				{
					result2=tmp;
				}
			}
		}
		
	}
}
void Floyd()
{
	int tmp;
	 
	for(int k=1;k<=N;k++)//D^1 ~ D^n 까지 구하기 
	{
		
		////////////////////D구하기
		for(int i=1;i<=N;i++)//전치행렬이므로 
		{
			for(int j=i+1;j<=N;j++)
			{
				if(k==i || k==j) continue;
				
				if((D[i][j]==INF &&D[i][k]==INF) || (D[i][j]==INF &&D[k][j]==INF)) continue;
				
				tmp = D[i][k] + D[k][j];
				if(tmp < D[i][j])
				{
					D[i][j] = tmp;
					D[j][i] = tmp;
					P[i][j][0] = k;
					P[i][j][1] = -1;
					P[j][i][0] = k;
					P[j][i][1] = -1;
				} 
				else if(tmp == D[i][j])
				{
					D[i][j] = tmp;
					D[j][i] = tmp;
					
					for(int q=1;;q++)
					{
						if(P[i][j][q]==-1)
						{
							P[i][j][q]=k;
							P[j][i][q]=k;
							P[i][j][q+1]=-1;
							P[j][i][q+1]=-1;	
							break;
						}
					}				
				}
			}
		}
	}
}

int main(void)
{
	for(int i=1;i<=500;i++)
	{
		P[i][i][1]=-1;
	}
	int a;
	int b;
	int _i;
	int _j;
	int _w;
	double distance;
	ifstream fin;
	ofstream fout;
	
	fin.open("contact.inp");
	fout.open("contact.out");
	
	fin>>T; //테스터 케이스 입력 
	
	for(int i=1;i<=T;i++)//테스터 케이스만큼 실행 
	{


		fin>>N;fin>>M;fin>>K; // 정점 간석 질문 입력

		for(int q=1;q<=N;q++)//초기화 작업 D^0 번째 
		{
			for(int w=1;w<=N;w++)
			{
				if(q==w)
				{
					continue;
				}
				D[q][w] = INF; // INF 무한대값
				P[q][w][0]=0;
				P[q][w][1]=-1;//-1은 아직 입력이 없엇다는소리~! 
			}
		}
		for(int j=1;j<=M;j++)//간선 정보들 입력 
		{
			fin>>_i;fin>>_j;fin>>_w;
			// 전치행렬이므로  
			D[_i][_j] = _w;
			D[_j][_i] = _w;
		}
		Floyd();// D^n 과 P^n 구하기
							 
		for(int j=1;j<=K;j++)//질문에대한 답변 
		{
			fin>>a;fin>>b;
			result1=INF;result2=INF;distance = (double)D[a][b]/2; 
			Qurey(a,b,distance);
			cout<<result1<<" "<<result2<<endl;
			fout<<result1<<" "<<result2<<endl;
		}
	}	
}
