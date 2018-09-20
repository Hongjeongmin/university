#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int stack[1000];
int top=-1;

void push(int &integer)
{
	stack[++top] = integer;
}
int pop()
{
	return stack[top--];
}
int main(void)
{
	int integer;
	int k;
	int cnt;
	int cnt_e;
	char ch;
	string remainder;
	ifstream fin;
	ofstream fout;
	
	fin.open("tree.inp");
	fout.open("tree.out");
	
	fin>>k;
	string str;
	getline(fin,remainder);
	for(int i =0;i<k;i++)
	{
	//	cout<<"k:"<<i+1<<"½ÃÀÛ!"<<endl;
		
		getline(fin,str);	
	//	cout<<str<<endl;
		fout<<str<<endl;
		//--------------------
	//	cout<<"Preorder"<<endl;
		fout<<"Preorder"<<endl;
		cnt=0;cnt_e=0;
		for(int j=0;j<str.length();j++)
		{
			if(str[j]!='(' && str[j]!=' ')
			{
				ch=str[j];
				break;
			}
		}
		for(int j=0;j<str.length();j++)
		{
			if(str[j]=='(')
			{
			//	cout<<"r"<<cnt<<endl;
				fout<<"r"<<cnt<<endl;
				cnt++;
			}
			else if(str[j]==ch)
			{
			//	cout<<str[j];
				fout<<str[j];
				j++;
				while(true)
				{
					if(str[j]==' ')
					{
					//	cout<<endl;
						fout<<endl;
						break;
					}
					else
					{
					//	cout<<str[j];
						fout<<str[j];
						j++;
					}
				}
			}
			else if(str[j]==')')
			{
				cnt_e++;
			}
			/*
			if(cnt==cnt_e)
			{
				break;
			}
			*/
		}
		//--------------------
	//	cout<<"Inorder"<<endl;
		fout<<"Inorder"<<endl;
		cnt=0;cnt_e=0;
		//--------------------
		for(int j=0;j<str.length();j++)
		{
			if(str[j] == '(')
			{				
				push(cnt);
				cnt++;
			}
			else if(str[j] == ch)
			{
			//	cout<<str[j];
				fout<<str[j];
				
				while(true)
				{
					j++;
					if(str[j]==' ')
					{
						j--;
					//	cout<<endl;
						fout<<endl;
						break;
					}
					else
					{
					//	cout<<str[j];
						fout<<str[j];
					}
				}
				
			}
			else if(str[j] == ')')
			{
				cnt_e++;
			}
			else if(str[j]== ' ')
			{
				if(str[j-1]!='(' && str[j+1]!=')')
				{
					integer = pop();
				//	cout<<"r";
				//	cout<<integer<<endl;
					fout<<"r";
					fout<<integer<<endl;	
				}
			}
			if(cnt==cnt_e) break;
			
		}
		//--------------------
		
	}
}
