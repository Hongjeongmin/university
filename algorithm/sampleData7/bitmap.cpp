#include<iostream>
#include<fstream>
using namespace std;
char z;
int cnt=0;
void gototheD(char **arr,int h_s,int h_e,int v_s,int v_e,ofstream& fout);
void gototheB(char **arr,int h_s,int h_e,int v_s,int v_e,ofstream& fout,ifstream& fin);
int main(void)
{
	int n;
	int m;
	char c;
	ifstream fin;
	ofstream fout;
	fin.open("bitmap.inp");
	fout.open("bitmap.out");
	
	
	
	while(true)
	{
		fin>>c;
		if(c=='B')
		{
			cnt=0;
			fin>>n;
			fin>>m;
			fout<<"D"<<" "<<n<<" "<<m<<endl;	
			char **arr = new char*[n];
			for(int i=0;i<n;i++)
			{
				arr[i] = new char[m];
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					fin>>arr[i][j];
				}
			}
			gototheD(arr,0,n-1,0,m-1,fout);
		}
		else if(c=='D')
		{
			cnt=0;
			fin>>n;
			fin>>m;
			fout<<"B"<<" "<<n<<" "<<m<<endl;
			cout << "B";
			char **arr = new char*[n];
			for(int i=0;i<n;i++)
			{
				arr[i] = new char[m];
			}
			gototheB(arr,0,n-1,0,m-1,fout,fin);
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					fout<<arr[i][j];
					cnt++;
					if(cnt==50)
					{
						fout<<endl;
						cnt=0;
					}
				}
			}
									
		}
		else
		{
			break;
		}
		if(cnt!=0)
		{
			fout<<endl;
		}
	}
	fin.close();
	fout.close();
}
void gototheD(char **arr,int h_s,int h_e,int v_s,int v_e,ofstream& fout)
{
	z=arr[h_s][v_s];
	for(int i=h_s;i<=h_e;i++)
	{
		for(int j=v_s;j<=v_e;j++)
		{
			if(z!=arr[i][j])
			{
				z='D';
				break;
			}
			
		}
		if(z=='D') break;
	}
	
	if(z=='0')
	{
		fout<<"0";
		cnt++;
		if(cnt==50)
		{
			fout<<endl;
			cnt=0;
		}
	}
	else if(z=='1')
	{
		//cout<<"fout"<<endl;
		fout<<"1";
		cnt++;
		if(cnt==50)
		{
			fout<<endl;
			cnt=0;
		}
	}
	else
	{
		fout<<"D";
		cnt++;
		if(cnt==50)
		{
			fout<<endl;
			cnt=0;
		}		
		if(h_s==h_e && v_s!=v_e)
		{	
			//cout<<"1quater"<<endl;
			gototheD(arr,h_s,h_e,v_s,(v_s+v_e)/2,fout);//1qauter
			//cout<<"2quater"<<endl;	
			gototheD(arr,h_s,h_e,(v_s+v_e)/2+1,v_e,fout);//2qauter			
		}
		else if(h_s!=h_e && v_s==v_e)
		{
			gototheD(arr,h_s,(h_s+h_e)/2,v_s,v_e,fout);//1qauter
			gototheD(arr,(h_s+h_e)/2+1,h_e,v_s,v_e,fout);					
		}
		else
		{
			//cout<<"1quater"<<endl;
			gototheD(arr,h_s,(h_s+h_e)/2,v_s,(v_s+v_e)/2,fout);//1qauter
			//cout<<"2quater"<<endl;	
			gototheD(arr,h_s,(h_s+h_e)/2,(v_s+v_e)/2+1,v_e,fout);//2qauter
			//cout<<"3quater"<<endl;
			gototheD(arr,(h_s+h_e)/2+1,h_e,v_s,(v_s+v_e)/2,fout);//3quater
			//cout<<"4quater"<<endl;
			gototheD(arr,(h_s+h_e)/2+1,h_e,(v_s+v_e)/2+1,v_e,fout);//4quater		
		}
	}		
}
void gototheB(char **arr,int h_s,int h_e,int v_s,int v_e,ofstream& fout,ifstream& fin)
{
	fin>>z;
	//cout<<z<<endl;
	if(z=='D')
	{
		//cout<<"isD"<<endl;
		if(h_s==h_e && v_s!=v_e)
		{	
			gototheB(arr,h_s,h_e,v_s,(v_s+v_e)/2,fout,fin);	
			gototheB(arr,h_s,h_e,(v_s+v_e)/2+1,v_e,fout,fin);		
		}
		else if(h_s!=h_e && v_s==v_e)
		{
			gototheB(arr,h_s,(h_s+h_e)/2,v_s,v_e,fout,fin);
			gototheB(arr,(h_s+h_e)/2+1,h_e,v_s,v_e,fout,fin);					
		}
		else
		{
			gototheB(arr,h_s,(h_s+h_e)/2,v_s,(v_s+v_e)/2,fout,fin);
			gototheB(arr,h_s,(h_s+h_e)/2,(v_s+v_e)/2+1,v_e,fout,fin);
			gototheB(arr,(h_s+h_e)/2+1,h_e,v_s,(v_s+v_e)/2,fout,fin);
			gototheB(arr,(h_s+h_e)/2+1,h_e,(v_s+v_e)/2+1,v_e,fout,fin);		
		}		
	}
	else if(z=='1')
	{
		//cout<<"is1"<<endl;
		for(int i=h_s;i<=h_e;i++)
		{
			for(int j=v_s;j<=v_e;j++)
			{
				arr[i][j]='1';
			}
		}
	}
	else if(z=='0')
	{
		//cout<<"is0"<<endl;
		for(int i=h_s;i<=h_e;i++)
		{
			for(int j=v_s;j<=v_e;j++)
			{
				arr[i][j]='0';
			}
		}		
	}
}
