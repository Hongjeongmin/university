#include<iostream>
#include<fstream>
int T;
int len;
int arr[100000000];
int cnt[100000000];
int p;
int tmp; 
using namespace std;
int towgin(int end, int &tmp)//이진법으로 tmp 자리찾기 
{
	int start=0;
	int mid;
	while(true)
	{
		mid = (start+end)/2;
		if(arr[mid]>tmp)
		{
			if(start==mid)
			{
				return mid;
			} 
			end = mid-1;
		}
		else
		{
			if(start==mid)
			{
				return mid+1;
			}
			start =mid+1;
		}
	}	
} 
int main(void)
{
	int buffer;
	int buffer_cnt;
	ifstream fin;
	ofstream fout;
	
	fin.open("LIS.inp");
	fout.open("LIS.out");
	
	fin>>T;
	for(int i=0;i<T;i++)
	{
		p=0;//초기 배열 가리키는 위치 
		fin>>len;
		fin>>arr[0];
		cnt[0]=1;
		for(int j=1;j<len;j++)
		{
			fin>>tmp;
			
			if(arr[p] < tmp)
			{
				// 배열의 모든 값보다 지금 들어온 값이 크면
				p++;
				arr[p] = tmp; // 끝에다가 들어오는 값 추가
				cnt[p] = cnt[p-1];
			}
			else if(arr[0] > tmp)
			{
				arr[0] = tmp;
				cnt[0] = (cnt[0] +1) % 1000000007; 
			}
			else
			{
				//현재 tmp와 p-1까지의 배열 에서 들어갈수 잇는곳이 있나?
				buffer = towgin(p,tmp);
				cnt[buffer] = (cnt[buffer] + cnt[buffer-1]) % 1000000007; 
				arr[buffer] = tmp;
			}
	}
	//	cnt = (buffer_cnt*cnt) % 1000000007;
	//	for(int j=0;j<=p;j++)
	//	{
	//		cout<<arr[j]<<" ";
	//	}
		cout<<p+1<<" "<<cnt[p]<<endl;
		
	}
	
}
