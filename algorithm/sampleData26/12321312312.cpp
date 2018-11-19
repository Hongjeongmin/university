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
    bool ok = true;
	bool real = true;
    while ( ok ) 
	{
        ok = false;
        sort(L,L+N,YYY);
        for ( int i = 0 ; i < N ; i++ ) {
            if ( !L[i].y ) continue;
            int now =0;
            for ( int j = 0 ; j < i ; j++ )
                if ( ((L[j].x >= L[i].x && L[j].x < L[i].p) || (L[j].p >L[i].x && L[j].p <= L[i].p)) || (L[j].x <= L[i].x && L[j].p >= L[i].p)) 
                    now = max(now,L[j].q);
            if ( L[i].y == now ) continue;
            int diff=L[i].q-L[i].y;
            L[i].y = now;
            L[i].q = now+diff;
            ok = true;
        }
        sort(L,L+N,XXX);
        for ( int i = 0 ; i < N ; i++ ) {
            if ( !L[i].x ) continue;
            int now=0;
            for ( int j = 0 ; j < i ; j++ )
                if ( ((L[j].y >= L[i].y && L[j].y < L[i].q) || (L[j].q > L[i].y && L[j].q <= L[i].q)) || (L[j].y <= L[i].y && L[j].q >= L[i].q) ) 
                    now = max(now,L[j].p);
            if ( L[i].x == now ) continue;
            int diff=L[i].p-L[i].x;
            L[i].x = now;
            L[i].p = now+diff;
            ok = true;
        }
    }
	int xx = INF;
	int yy = INF;
	int pp;
	int qq;
        for ( int i = 0 ; i < N ; i++ ) {
            qq = max(qq,L[i].q);
            pp = max(pp,L[i].p);
            xx = min(xx,L[i].x);
            yy = min(yy,L[i].y);
        }
    W = pp-xx; H = qq-yy;
	
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
