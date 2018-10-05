#include <iostream>
#include <fstream>
using namespace std;
int T;
int n;
int N[1000];
int front;
int back;
int sum;
int alice,computer;
void look(int front, int  back,int who)//a is alice sum b is computer sum
{
	if(front == back)
	{
		if(who==1)// Alice turn is 1
		{
			alice = N[front];
			computer = 0;
			return;
		}
		else// computer turn is 0
		{
			computer = N[front];
			alice = 0;
			return;
		}
		
	}
	int left_alice;
	int left_computer;
	int right_alice;
	int right_computer;
	int alice_sum;
	int computer_sum;
	look(front+1,back,(who+1)%2);//left pick up
	if(who==1)
	{
		left_alice = alice + N[front];
		left_computer = computer;
	}
	else
	{
		left_alice = alice;
		left_computer = computer + N[front];
	}
	
	look(front,back-1,(who+1)%2);// right picr up	
	if(who==1)
	{
		right_alice = alice + N[back];
		right_computer = computer;
	}
	else
	{
		right_alice = alice;
		right_computer = computer + N[back];
	}
	
	if(who==1)
	{
		if(left_alice>right_alice)
		{
			alice = left_alice;
			computer = left_computer;
		}
		else
		{
			alice = right_alice;
			computer = right_computer;
		}
	}
	else
	{
		if(left_computer>right_computer)
		{
			alice = left_alice;
			computer = left_computer;
		}
		else
		{
			alice = right_alice;
			computer = right_computer;
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
		fin>>n;
		for(int j=0;j<n;j++)
		{
			fin>>N[j];
		}
		look(0,n-1,1);
		
		fout<<alice<<endl;
	//	cout<<alice<<endl;
		
		
	}
	
}
