#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
using namespace std;

class Lectangles
{
	public:
		int x;
		int y;
		int w;
		int h;
};

bool XXX(const Lectangles& tmp1,const Lectangles& tmp2)
{
	if(tmp1.x != tmp2.x) return tmp1.x < tmp2.x;
	return tmp1.y<tmp2.y;
}
bool YYY(const Lectangles& tmp1,const Lectangles& tmp2)
{
	if(tmp1.y != tmp2.y) return tmp1.y<tmp2.y;
	return tmp1.x < tmp2.x;
}
Lectangles L[10001]; // Max of number of lectangle is 10,000
int N;
int W,H; // it is result of input data

void Procedure()
{
	bool TR = true;
	int max_value;
	while(TR)
	{
		TR = false;
		//lower shift
		sort(L,L+N,YYY);
		for(int i=0;i<N;i++)
		{
			if(L[i].y == 0 ) continue;
			max_value=0;
			for(int j =0 ; j < i ; j++)
			{
				if((L[j].x >= L[i].x && L[j].x < (L[i].x + L[i].w)) || ((L[j].x + L[j].w) >L[i].x && (L[j].x + L[j].w) <= (L[i].x + L[i].w)) || (L[j].x <= L[i].x &&(L[j].x + L[j].w) >= (L[i].x + L[j].w))) 
				{
					//°ãÄ¡¸é 
					max_value = max(max_value,L[j].y+L[j].h);
				}
			}
			if(L[i].y == max_value) continue; // it is not fall 
			TR = true;
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
				if ( ((L[j].y >= L[i].y && L[j].y < (L[i].y + L[i].h)) || ((L[j].y + L[j].h) > L[i].y && (L[j].y + L[j].h) <= (L[i].y + L[i].h))) || (L[j].y <= L[i].y && (L[j].y + L[j].h) >= (L[i].y + L[i].h)) )
				{
					//°ãÄ¡¸é 
					max_value = max(max_value,L[j].x+L[j].w);
				}	
			}
			if(L[i].x == max_value) continue;
			TR = true;
			L[i].x = max_value;
		}	
	}
	W=0;
	H=0;
	for( int i = 0 ; i < N ; i++)
	{
		W = max (W,L[i].x+L[i].w);
		H = max (H,L[i].y+L[i].h); 
	}
	
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
			L[j].w = p - x;
			L[j].h = q - y; 
		}
		Procedure();
		cout<< W << " " << H << endl;
		fout<< W << " " << H << endl;
			 
	}
}
