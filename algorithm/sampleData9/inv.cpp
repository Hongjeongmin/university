#include<iostream>
#include<fstream>
using namespace std;
int T;
int N[100001];
int P[100001];
int n;
long long int ans;
long long int cnt;
void Merge(int p,int q,int r)
{
	int i = p, j = q+1, k =p;
	cnt=0;
	while(i <=q || j <=r)
	{
		if(i>q)
		{
			P[k++] = N[j++];
			cnt++;
		}
		else if(j > r) 
		{
			P[k++] = N[i++];
			ans=ans+cnt;
		}
		else if(N[i] <= N[j])
		{
			P[k++] = N[i++];
			ans=ans+cnt;
		}
		else
		{
			P[k++] = N[j++];
			cnt++;
		}

	}
	for(int i=p; i<=r; i++)
	{
		N[i] =P[i];
	}
}
void MergeSort(int p,int r)
{
	if(p<r)
	{
		int q = (p+r)/2;
		MergeSort(p,q); // 2section
		MergeSort(q+1,r); // 2section
		Merge(p,q,r);
	}
}

int main(void)
{
	ifstream fin;
	ofstream fout;	
	fin.open("inv.inp");
	fout.open("inv.out");	
	fin>>T;	
	for(int i=1;i<=T;i++)
	{
		ans=0;
		cnt=0;
		fin>>n;
		for(int j=1;j<=n;j++)
		{
			fin>>N[j];
		}        

		MergeSort(1,n);
		
		fout<<ans<<endl;
		

	}		
}

