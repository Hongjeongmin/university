#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
class Light
{
	public:
		int l;
		int r;
		
		bool operator>(Light &L) const{
			if(this->l > L.l) return true;
			return false;
		}
		bool operator<(Light &L) const{
			if(this->l < L.l) return true;
			return false;
		}			
		
};
Light light[100001];
int N;
int K;
int MAX;

int How_many_count(int l,int r)
{
	int cnt=0;
	int locate;
	int big_r=0;
	int tmp; // 0은 아직 기회는 잇는 것 
	int w=0;
	while(true)
	{
		locate = -1;
		for(;w<N;w++)
		{
			if(light[w].l>l) break;
			
			if(light[w].r>=l && light[w].r > big_r)
			{
				big_r = light[w].r;
				locate = w;
			}
		}
		if(locate == -1|| MAX < r) return -1; 
		cnt++;
		
		if(r<=light[locate].r) return cnt;	
		l = light[locate].r;
	}
}

int main(void)
{
	int cnt;
	int l;
	int r;
	int result;
	int locate;
	int big;
	ifstream fin;
	ofstream fout;
	fin.open("light.inp");
	fout.open("light.out");
	
	fin>>N;
	//가로등 정보 받기 
	MAX=0;
	for(int i=0;i<N;i++)
	{
		fin>>light[i].l;
		fin>>light[i].r;
		if(light[i].r>MAX) MAX = MAX=light[i].r;
	} 
	sort(light,light + N);
//	for(int i=0;i<N;i++)cout<<light[i].l<<" "<<light[i].r<<endl;
	
	fin>>K;
	for(int i=1;i<=K;i++)
	{
		fin>>l;fin>>r;
		result = How_many_count(l,r);

		fout<<result<<endl;
	//	cout<<result<<endl;	
	}
	fin.close();
	fout.close();
	
	return 0;
}
