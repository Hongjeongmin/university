#include <iostream>
#include <fstream>
using namespace std;
int T;
int n;
int N[1001];
int dp[1001][1001][2];
int front;
int back;


int look(int front, int  back,int who)//a is alice sum b is computer sum
{
	if(front == back)
	{
		//cout<<"½ÇÇàÁß"<<endl;
		if(who==1)// Alice turn is 1
		{
			return N[front];
		}
		else// computer turn is 0
		{
			return 0;  
		}
		
	}
	int& ref = dp[front][back][who];
	if(ref != -1)
	{
		return ref;
	}

	int left;
	int right;
	if(who==1)
	{
		left = N[front] + look(front+1,back,(who+1)%2);//left pick up
		right = N[back] +look(front,back-1,(who+1)%2);// right picr up
		if(left>right)
		{
			ref = left;
			return ref;	
		}
		else
		{
			ref = right;
			return ref;	
		}	
	}
	else
	{
		left = look(front+1,back,(who+1)%2);//left pick up
		right = look(front,back-1,(who+1)%2);// right picr up
		if(left>right)
		{
			ref = right;
			return ref;
		}
		else
		{
			ref = left;
			return ref;
		}

	}

}
int main(void)
{
	ifstream fin;
	ofstream fout;
	
	fin.open("card.inp");
	fout.open("card.out");
	fin>>T;
	
	for(int i=0;i<T;i++)
	{
		for(int j=0;j<1001;j++)
		{
			for(int k=0;k<1001;k++)
			{
				dp[j][k][0]=-1;
				dp[j][k][1]=-1;
			}
		}
		fin>>n;
		for(int j=0;j<n;j++)
		{
			fin>>N[j];
		}
		
		
		fout<<look(0,n-1,1)<<endl;
		//cout<<look(0,n-1,1)<<endl;
		
		
	}
	
}
