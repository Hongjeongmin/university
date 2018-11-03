#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef struct
{
	int a;
	int b;
}mem;

vector<mem> v;

int main()
{
	ofstream fout;
	fout.open("path.inp");
	
	srand((unsigned int)time(NULL));
	
	bool endflag;
	int T,M,N,K,a,b;
	cin >> T;// >> M >> N >> K;
	fout << T << endl << endl;
	//fout << M << " " << N << " " << K << endl;
	for(int t=0;t<T;t++)
	{
		
		
		
		v.clear();
		cin >> M >> N >> K;
		fout << M << " " << N << " " << K << endl;
		for(int i=0;i<K;i++)
		{
			while(true)
			{
				endflag=false;
				
				a = rand() % M;
				b = rand() % N;
				if((a != 0 && b != 0) && (a != M-1 && b != N-1))
				{
					if(i==0)
					{
						v.push_back({a,b});
					}
					else
					{
						for(int j=0;j<=i;j++)
						{
							if(a == v[i].a && b == v[i].b)
							{
								endflag=true;
								break;
							}
						}
						if(!endflag)
						{
							v.push_back({a,b});
						}
					}
				}
				else
					endflag=true;
				if(!endflag)
					break;
			}
			fout << v[i].a << " " << v[i].b << endl;
		}
		
		// 가로 코스트 받기
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N - 1; j++)
				fout << (rand() % 100) << " ";
			fout << endl;
		}
	
		// 세로 코스트 받기
		for (int i = 0; i < M - 1; i++)
		{
			for (int j = 0; j < N; j++)
				fout << (rand() % 100) << " ";
			fout << endl;
		}
		fout << endl;
	}
	
	
	
	
	return 0;
}
