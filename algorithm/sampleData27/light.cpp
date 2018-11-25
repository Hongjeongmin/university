#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
class Light
{
	public:
		int left;
		int right;
		
		bool operator>(Light &L) const{
			if(this->left > L.left) return true;
			return false;
		}
		bool operator<(Light &L) const{
			if(this->left < L.left) return true;
			return false;
		}			
		
};
Light light[100001];
int N;
int K;
int MAX;

int How_many_count(int left,int right)
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
			if(light[w].left>left) break;
			
			if(light[w].right>=left && light[w].right > big_r)
			{
				big_r = light[w].right;
				locate = w;
			}
		}
		if(locate == -1|| MAX < right) return -1; 
		cnt++;
		
		if(right<=light[locate].right) return cnt;	
		left = light[locate].right;
	}
}

int main(void)
{
	int cnt;
	int left;
	int right;
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
		fin>>light[i].left;
		fin>>light[i].right;
		if(light[i].right>MAX) MAX = MAX=light[i].right;
	} 
	sort(light,light + N);
//	for(int i=0;i<N;i++)cout<<light[i].left<<" "<<light[i].right<<endl;
	
	fin>>K;
	for(int i=1;i<=K;i++)
	{
		fin>>left;fin>>right;
		result = How_many_count(left,right);

		fout<<result<<endl;
	//	cout<<result<<endl;	
	}
	fin.close();
	fout.close();
	
	return 0;
}
