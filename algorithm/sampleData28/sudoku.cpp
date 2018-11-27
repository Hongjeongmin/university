#include<iostream>
#include<fstream>
#include<algorithm>
#include<stdio.h>
using namespace std;

typedef struct
{
	int value;
	int area;
}Sudoku;

Sudoku S[10][10];
bool R[10][10];
bool C[10][10];
bool A[10][10];

void Get_Sudoku(ifstream &fin);
bool Make_Sudoku(int row,int col);
void Print_Sudoku(ofstream &fout,int &t);
void Reset_Sudoku();
int main(void)
{
	ifstream fin;
	ofstream fout;
	
	fin.open("sudoku.inp");
	fout.open("sudoku.out");
	
	//test Case
	int T;
	int row;
	int col;
	fin>>T;
	for(int t=1;t<=T;t++)
	{
		Get_Sudoku(fin);
		Reset_Sudoku();
		//행과 열과 지역에 대해서 중복되는값을 제거하기 위한것 
		for(int i=1;i<=9;i++)
		{
			for(int j=1;j<=9;j++)
			{
				if(S[i][j].value != 0)
				{
					R[i][S[i][j].value] = true;
					C[j][S[i][j].value] = true;
					A[S[i][j].area][S[i][j].value] = true;
				}
			}
		}		
		//
		Make_Sudoku(1,1);
		Print_Sudoku(fout,t);
	}		
	fin.close();
	fout.close();
	return 0;
}
void Get_Sudoku(ifstream &fin)
{
	char c;
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			fin>>S[i][j].value;
		}
	}
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			fin>>c;
			if(c=='a')
			{
				S[i][j].area =1;
			}
			else if(c=='b')
			{
				S[i][j].area =2;
			}
			else if(c=='c')
			{
				S[i][j].area =3;
			}
			else if(c=='d')
			{
				S[i][j].area =4;
			}
			else if(c=='e')
			{
				S[i][j].area =5;
			}
			else if(c=='f')
			{
				S[i][j].area =6;
			}
			else if(c=='g')
			{
				S[i][j].area =7;
			}
			else if(c=='h')
			{
				S[i][j].area =8;
			}
			else if(c=='i')
			{
				S[i][j].area =9;
			}																											
		}
	}		
}

bool Make_Sudoku(int row, int col)
{
	 
	//check row
	//check col
	//check area
	if(row == 9 && col == 9)// end node
	{
		if(S[row][col].value != 0) return true;
		
		int value = -1;
		for(int i=1;i<=9;i++)
		{
			if(R[row][i]==false && C[col][i]==false && A[S[row][col].area][i]==false)
			{
				value = i;
				break;
			}
		}
		if(value == -1) return false;
		else
		{
			S[row][col].value = value;
			R[row][value] = true;
			C[col][value] = true;
			A[S[row][col].area][value] = true;
			return true;
		}
	}
	else
	{
		if(col == 9)
		{
			if(S[row][col].value != 0)
			{
				if(Make_Sudoku(row+1,1)==true)return true;
				else return false;
			}
			else
			{
				int value =-1;
				for(int i=1;i<=9;i++)
				{
					if(R[row][i]==false && C[col][i]==false && A[S[row][col].area][i]==false)
					{
						R[row][i] = true;
						C[col][i] = true;
						A[S[row][col].area][i] = true;
						S[row][col].value = i;
						
						if(Make_Sudoku(row+1,1)==true) return true;
						else
						{
							R[row][i] = false;
							C[col][i] = false;
							A[S[row][col].area][i] = false;
							S[row][col].value = 0;
														
						}
						
					}
				}
				return false;
				
			}
		}
		else
		{
			if(S[row][col].value != 0)
			{
				if(Make_Sudoku(row,col+1)==true)return true;
				else return false;
			}
			else
			{
				int value =-1;
				for(int i=1;i<=9;i++)
				{
					if(R[row][i]==false && C[col][i]==false && A[S[row][col].area][i]==false)
					{
						R[row][i] = true;
						C[col][i] = true;
						A[S[row][col].area][i] = true;
						S[row][col].value = i;
						
						if(Make_Sudoku(row,col+1)==true) return true;
						else
						{
							R[row][i] = false;
							C[col][i] = false;
							A[S[row][col].area][i] = false;
							S[row][col].value = 0;								
						}
						
					}
				}
				return false;
				
			}
		}
		
	}
		
	
	
}

void Print_Sudoku(ofstream &fout,int &t)
{
//	cout<<"Test Case No: "<<t<<endl;
	fout<<"Test Case No: "<<t<<endl;
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			fout<<S[i][j].value<<" ";
//			cout<<S[i][j].value<<" ";
		}
		fout<<endl;
//		cout<<endl;
	}
	fout<<endl;
//	cout<<endl;	
}
void Reset_Sudoku()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			R[i][j] = false;
			C[i][j] = false;
			A[i][j] = false;
		}
	}
}
