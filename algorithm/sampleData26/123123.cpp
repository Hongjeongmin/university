#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#define INF 987654321
using namespace std;

class Lectangles
{
	public:
		int x;
		int y;
		int p;
		int q;
};

bool XXX(const Lectangles& tmp1,const Lectangles& tmp2)
{
	if(tmp1.x<tmp2.x) return true;
	else if(tmp1.x==tmp2.x && tmp1.y<tmp2.y) return true;
	else return false; 
}
bool YYY(const Lectangles& tmp1,const Lectangles& tmp2)
{
	if(tmp1.y<tmp2.y) return true;
	else if(tmp1.y==tmp2.y && tmp1.x<tmp2.x) return true;
	else return false; 
}
Lectangles L[10000]; // Max of number of lectangle is 10,000
int N;
int W,H; // it is result of input data

void Procedure()
{
	int x = INF;
	int y = INF;
	int p = 0;
	int q = 0;
	bool real = true;
	int max_value;
	while(real)
	{
		real = false;
		//lower shift
		sort(L,L+N,YYY);
		for(int i=0;i<N;i++)
		{
			if(L[i].y == 0 ) continue;
			max_value=0;
			for(int j =0 ; j < i ; j++)
			{
				if ( ((L[j].x >= L[i].x && L[j].x < L[i].p) || (L[j].p >L[i].x && L[j].p <= L[i].p)) || (L[j].x <= L[i].x && L[j].p >= L[i].p))
				{
					//°ãÄ¡¸é 
					max_value = max(max_value,L[j].q);
				}
			}
			if(L[i].y == max_value) continue; // it is not fall 
			real = true;
			L[i].y = max_value;
		}
		//left shift 
		sort(L,L+N,XXX);
		for(int i=0;i<N;i++)
		{
			if(L[i].x == 0) continue;
			max_value=0;
			for(int j =0 ; j< i ; j++)
			{
			if ( ((L[j].y >= L[i].y && L[j].y < L[i].q) || (L[j].q > L[i].y && L[j].q <= L[i].q)) || (L[j].y <= L[i].y && L[j].q >= L[i].q) ) 
				{
					//°ãÄ¡¸é 
					max_value = max(max_value,L[j].p);
				}	
			}
			if(L[i].x == max_value) continue;
			real = true;
			L[i].x = max_value;
		}	
	}
    for ( int i = 0 ; i < N ; i++ ) 
	{
            q = max(q,L[i].q);
            p = max(p,L[i].p);
            x = min(x,L[i].x);
            y = min(y,L[i].y);
    }
	W = p-x;
	H = q-y;
}

int main(void)
{
	ifstream fin;
	ofstream fout;
	int T;
	int x,y;//lower-left vertex
	int p,q;//upeer-right vetex
	
	fin.open("block.inp");
	fout.open("block.out");
	
	fin>>T;
	
	for(int i=0;i<T;i++)
	{
		fin >> N; // number of lectangle
		for(int j=0;j<N;j++)
		{
			fin>>x;fin>>y; // Lower-left vertex
			fin>>p;fin>>q; // Upper-right vertex
			L[j].x = x;
			L[j].y = y;
			L[j].p = p;
			L[j].q = q; 
		}
		Procedure();
		cout<< W << " " << H << endl;
		fout<< W << " " << H << endl;
			 
	}
}
