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
	fout.open("test.inp");
	
	srand((unsigned int)time(NULL));
	
	int T,N,M,K;
	fout<<1<<endl;
	//fout << M << " " << N << " " << K << endl;
	for(int t=0;t<T;t++)
	{
		v.clear();
		
		fout <<500<<" ";
		fout <<498+498<<" ";
		fout <<1<<endl;
		
		for(int i=1;i<498+498;i++)
		{
			fout<<(1)<<" "<<(i+1)<<" "<<(11)<<endl;
			fout<<(i+1)<<" "<<(500)<<" "<<(5)<<endl;
		}
		
		for(int i=0;i<K;i++)
		{
			fout<<(1)<<" "<<500<<endl;
		}

	}
	return 0;
}
