#include<iostream>
#include<fstream>
#define INF 987654321
using namespace std;

int T;// 0~90 �׽�Ʈ���̽� 
int N;// 1~500 ������ ���� 
int M;// 1~10000 �����Ǽ� 
int K;// 1~3 ������ ���� 
int result1,result2;

int D[501]; // ���ͽ�Ʈ�� 
int W[501][501]={0}; // ��� ������ 
int P[501][501];//��� 
int S[501];//�湮 
void Swap(int& a,int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
void Qurey(int a,int b,double distance)
{
	int tmp;
	int tmp1;
	int tmp2;
	
	for(int i=0;;i++)
	{
		if(P[b][i] == -1) break;
		
		tmp = P[b][i];
		
		if(distance - W[tmp][b] <0)
		{
			// tmp �� b ���̿� �ִ� �� 
			tmp1 = tmp; tmp2 = b;
			if(tmp1>tmp2)Swap(tmp1,tmp2);
			if(result1>tmp1)
			{
				result1=tmp1;result2=tmp2;
			}
			else if(result1==tmp1 && result2>tmp2)
			{
				result2=tmp2;
			}
		}
		else if(distance - W[tmp][b] >0)
		{
			//a�� tmp ���̿� �ִ�.
			Qurey(a,tmp,distance-W[tmp][b]); 
		}
		else
		{
			// tmp��ġ���� ������~ 
			if(result1>tmp)
			{
				result1=tmp;result2=tmp;
			}
			else if(result1==tmp && result2>tmp)
			{
				result2=tmp;
			}			
			
		}
	} 
	
}
void Dijkstra(int a, int b)//��ȯ�ϴ� ���� �Ÿ�! 
{
	int dt=INF;
	int tmp; 
	int check;
	for(int i=1;i<=N;i++)
	{
		S[i] = 0; // �湮�ߴ��� ���ߴ����� �ʱ�ȭ ���ݴϴ�.
		P[i][0] = -1; // ��� �ʱ�ȭ�� ���ݴϴ�.  
		D[i] = W[a][i];
		if(D[i] !=0 && D[i] !=INF) // a->i�� �����ִ� ���� ������� 
		{
			if(dt > D[i])
			{
				dt = D[i];
				check = i; // ��ΰ� ���������� ��ŷ 
			}
			P[i][0] = a;
			P[i][1] = -1;	
		}
	}
	S[a] = 1; // a���� ����ϹǷ� �翬�� �湮�߰���?? 

	for(int T=1;T<N;T++)
	{		
		dt = INF;
		for(int j=1;j<=N;j++)
		{
			if(S[j]==1) continue;
			if(dt>D[j]) 
			{
				dt = D[j];
				check = j;
			}
		}
		S[check] =1;	
		for(int i=1;i<=N;i++)
		{
			if(S[i] == 1 ) continue;

			if(W[check][i] == INF) continue;

			if(D[i] > D[check] + W[check][i])
			{	
				D[i] = D[check] + W[check][i];
				P[i][0] = check;
				P[i][1] =-1; // ����ʱ�ȭ  
			}
			else if(D[i] == D[check] + W[check][i])
			{
				for(int j=1;;j++)
				{
					if(P[i][j]==-1)
					{
						P[i][j] = check;
						P[i][j+1] = -1;
						break;
					}
				}
			}
		}
	}
	//D���� a���� ������ ���ΰ��� �ִ� �Ÿ��� ����Ǿ���. 
	//P���� �ִܰŸ� ��ΰ� ���� �Ǿ��ִ�. 
}

int main(void)
{
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
	
	fin>>T; //�׽��� ���̽� �Է� 
	
	for(int i=1;i<=T;i++)//�׽��� ���̽���ŭ ���� 
	{
		fin>>N;fin>>M;fin>>K; // ���� ���� ���� �Է�

		for(int q=1;q<=N;q++)//�ʱ�ȭ �۾� D^0 ��° 
		{
			for(int w=1;w<=N;w++)
			{
				if(q==w)
				{
					continue;
				}
				W[q][w] = INF; // INF ���Ѵ밪
			}
		}
		for(int j=1;j<=M;j++)//���� ������ �Է� 
		{
			fin>>_i;fin>>_j;fin>>_w;
			// ��ġ����̹Ƿ�  
			W[_i][_j] = _w;
			W[_j][_i] = _w;
		}
				 
		for(int j=1;j<=K;j++)//���������� �亯 
		{
			fin>>a;fin>>b;
			Dijkstra(a,b);
			result1=INF;result2=INF;distance = (double)D[b]/2;
			//S �ߺ����� �迭�� P�ִܰŸ� �迭�ϼ� 
			Qurey(a,b,distance);
			//cout<<result1<<" "<<result2<<endl;
			fout<<result1<<" "<<result2<<endl;
		}
	}	
}
