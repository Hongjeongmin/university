#include<iostream>
#include<fstream>

using namespace std;
int T;
int n;
int N[1001];
int dp[2][1004];
int br;
int dr;

int MAX2(int a, int b)
{
   int MAX = a >= b ? a : b;
   return MAX;
}

int MAX3(int a, int b, int c)
{
   int MAX = a >= b ? a : b;
   MAX = MAX >= c ? MAX : c;
   return MAX;
}
int Look(int who,int present)//index nuber
{

	int &ref = dp[who][present];
	
	if(ref != -1472554565)
	{
		return ref;
	}
	
	if(present==n)
	{
		ref = N[n];

		return ref;	 
	} 
	int a1,a2,a3;// is each sum value
	
	if(present==n-1||present>n)
	{
	//	////cout<<"present==n-1"<<endl;
		ref = -99999999;
	//	cout<<"dp["<<present<<"]="<<ref<<"  N["<<present<<"]="<<N[present]<<endl;
		return ref;
	} 
	
	if(who==0)//0is �ڿ� �ΰ� 
	{
	
		a2=Look(1,present+3);
		a3=Look(1,present+4);
		ref = MAX2(a2,a3);
		ref = ref + N[present];
	}
	else
	{
		a1=Look(0,present+2);
		a2=Look(1,present+3);
		a3=Look(1,present+4);
		ref = MAX3(a1,a2,a3);
		ref = ref + N[present];		
	}	
		return ref;		
}
int main(void)
{
	int result1;
	int result2;
	int result3;
	int result;
	int b1,b2,b3;
	ifstream fin;
	ofstream fout;
	
	fin.open("card.inp");
	fout.open("card.out");

	fin>>T;
	for(int i=1;i<=T;i++)
	{
		for(int x=0;x<=1004;x++)
		{
			for(int y=0;y<=1;y++)
			{
				dp[y][x]= -1472554565;
			}				
		}
		fin>>n;
		for(int j=1;j<=n;j++)
		{
			fin>>N[j];
		}
		
		b1 = Look(1,4);
		b2 = Look(1,5);
		result1 = MAX2(b1,b2);
		result1 = result1 + N[1];
		b1 = Look(0,4);
		b2 = Look(1,5);
		b3 = Look(1,6);
		result2 = MAX3(b1,b2,b3);
		result2 = result2+N[2];
	
		b1 = Look(0,5);
		b2 = Look(1,6);
		b3 = Look(1,7);
		result3 = MAX3(b1,b2,b3);
		result3 = result3+N[3];
		result = MAX3(result1,result2,result3);	
	//	cout<<result<<endl;
		fout<<result<<endl;
	}	
}