#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#define INF 987654321
using namespace std;

class Lectangles
{
	public:
		int x;
		int y;
		int p;
		int q;
};
class Tree
{
	public:
		int left;
		int right;
		int max;
		bool exist;
};

bool XXX(const Lectangles& tmp1,const Lectangles& tmp2)
{
	if(tmp1.x != tmp2.x) return tmp1.x < tmp2.x;
	return tmp1.y<tmp2.y;
}
bool YYY(const Lectangles& tmp1,const Lectangles& tmp2)
{
	if(tmp1.y != tmp2.y) return tmp1.y<tmp2.y;
	return tmp1.x < tmp2.x;
}
Lectangles L[10001]; // Max of number of lectangle is 10,000
Tree treeY[50001];
Tree treeX[50001];
int Max_scaleX;
int Max_scaleY;
int x_size;
int y_size;
int N;
int WWW,HHH; // it is result of input data
int look_maxY(int left,int right,int location)// size �� ���� �Ĵٺ���  
{
	// look at the maxY in the segment_tree and store sgment_tree
	if(left<=treeY[location].left && right>=treeY[location].right)
	{
		return treeY[location].max;
	}
	else if(left>treeY[location].left && right<treeY[location].right && treeY[location].exist == false)
	{
		return treeY[location].max;
	}
	else if(left==treeY[location].left && right<treeY[location].right && treeY[location].exist == false)
	{
		return treeY[location].max;
	}
	else if(left>treeY[location].left && right==treeY[location].right && treeY[location].exist == false)
	{
		return treeY[location].max;
	}	
	else if(left>treeY[location].left && right<treeY[location].right && treeY[location].exist == true)
	{
		return max(look_maxY(left,right,location*2),look_maxY(left,right,location*2+1));
	}
	else if(left==treeY[location].left && right<treeY[location].right && treeY[location].exist == true)
	{
		return max(look_maxY(left,right,location*2),look_maxY(left,right,location*2+1));
	}
	else if(left>treeY[location].left && right==treeY[location].right && treeY[location].exist == true)
	{
		return max(look_maxY(left,right,location*2),look_maxY(left,right,location*2+1));
	}
	else if(left<treeY[location].left && right>treeY[location].left && right<treeY[location].right && treeY[location].exist== false)
	{
		return treeY[location].max;
	}
	else if(left>treeY[location].left && left<treeY[location].right && right>treeY[location].right && treeY[location].exist== false)	
	{
		return treeY[location].max;
	}
	else if(left<treeY[location].left && right>treeY[location].left && right<treeY[location].right && treeY[location].exist== true)
	{
		return max(look_maxY(left,right,location*2),look_maxY(left,right,location*2+1));
	}
	else if(left>treeY[location].left && left<treeY[location].right && right>treeY[location].right && treeY[location].exist== true)
	{
		return max(look_maxY(left,right,location*2),look_maxY(left,right,location*2+1));
	}
	
	return 0;
}

int look_maxX(int left,int right,int location)// size �� ���� �Ĵٺ���  
{
	// look at the maxY in the segment_tree and store sgment_tree
	if(left<=treeX[location].left && right>=treeX[location].right)
	{
		return treeX[location].max;
	}
	else if(left>treeX[location].left && right<treeX[location].right && treeX[location].exist == false)
	{
		return treeX[location].max;
	}
	else if(left==treeX[location].left && right<treeX[location].right && treeX[location].exist == false)
	{
		return treeX[location].max;
	}
	else if(left>treeX[location].left && right==treeX[location].right && treeX[location].exist == false)
	{
		return treeX[location].max;
	}	
	else if(left>treeX[location].left && right<treeX[location].right && treeX[location].exist == true)
	{
		return max(look_maxX(left,right,location*2),look_maxX(left,right,location*2+1));
	}
	else if(left==treeX[location].left && right<treeX[location].right && treeX[location].exist == true)
	{
		return max(look_maxX(left,right,location*2),look_maxX(left,right,location*2+1));
	}
	else if(left>treeX[location].left && right==treeX[location].right && treeX[location].exist == true)
	{
		return max(look_maxX(left,right,location*2),look_maxX(left,right,location*2+1));
	}
	else if(left<treeX[location].left && right>treeX[location].left && right<treeX[location].right && treeX[location].exist== false)
	{
		return treeX[location].max;
	}
	else if(left>treeX[location].left && left<treeX[location].right && right>treeX[location].right && treeX[location].exist== false)	
	{
		return treeX[location].max;
	}
	else if(left<treeX[location].left && right>treeX[location].left && right<treeX[location].right && treeX[location].exist== true)
	{
		return max(look_maxX(left,right,location*2),look_maxX(left,right,location*2+1));
	}
	else if(left>treeX[location].left && left<treeX[location].right && right>treeX[location].right && treeX[location].exist== true)
	{
		return max(look_maxX(left,right,location*2),look_maxX(left,right,location*2+1));
	}
	
	return 0;
}

void make_Ytree(int left,int right, int distance,int location)// left : ���� ���� , right : ���� ���� , distance : �簢���� ���� , location : ���� ��� ��ġ 
{		
	if(treeY[location].left<left && treeY[location].right > right && treeY[location].exist == false) // ���� �ȿ� ������ �ڽ��� ���� �� 
	{		
		
		treeY[location*2].left = treeY[location].left;
		treeY[location*2].right = left;
		treeY[location*2].max = treeY[location].max;
		treeY[location*2].exist = false;
		
		treeY[location*2+1].left = left;
		treeY[location*2+1].right = treeY[location].right;
		treeY[location*2+1].max = max(distance,treeY[location].max);
		treeY[location*2+1].exist = true;
		
		treeY[(location*2+1)*2].left = left;
		treeY[(location*2+1)*2].right = right;
		treeY[(location*2+1)*2].max = distance;
		treeY[(location*2+1)*2].exist = false;
		
		treeY[(location*2+1)*2+1].left = right;
		treeY[(location*2+1)*2+1].right = treeY[location].right;
		treeY[(location*2+1)*2+1].max = treeY[location].max;
		treeY[(location*2+1)*2+1].exist = false;		
			
		treeY[location].exist = true;// �ڽ��� �����! 
		treeY[location].max = max(distance,treeY[location].max); // ū���� max������ ��ȯ!
	}
	else if(left == treeY[location].left && right < treeY[location].right && treeY[location].exist == false)//���ʿ� ���ļ� �����ȿ� ���ö� �׸��� �ڽ��� ������ 
	{
		treeY[location*2].left = left;
		treeY[location*2].right = right;
		treeY[location*2].max = distance;
		treeY[location*2].exist = false;
		
		treeY[location*2+1].left = right;
		treeY[location*2+1].right = treeY[location].right;
		treeY[location*2+1].max = treeY[location].max;
		treeY[location*2+1].exist = false;	
		
		treeY[location].exist = true;// �ڽ��� �����! 
		treeY[location].max = max(distance,treeY[location].max); // ū���� max������ ��ȯ!
	}
	else if(left > treeY[location].left && right == treeY[location].right && treeY[location].exist == false)//�����ʿ� ���ļ� �����ȿ� ���ö� �׸��� �ڽ��� ������ 
	{
		treeY[location*2].left = treeY[location].left;
		treeY[location*2].right = left;
		treeY[location*2].max = treeY[location].max;
		treeY[location*2].exist = false;
		
		treeY[location*2+1].left = left;
		treeY[location*2+1].right = right;
		treeY[location*2+1].max = distance;
		treeY[location*2+1].exist = false;	
		
		treeY[location].exist = true;// �ڽ��� �����! 
		treeY[location].max = max(distance,treeY[location].max); // ū���� max������ ��ȯ!		
		
	}
	else if(treeY[location].left>=left && treeY[location].right<=right)// ���� �ʰ��ؼ� ���� �� 
	{
		treeY[location].max = distance;
		treeY[location].exist = false;	
	}
	else if(treeY[location].left<=left && treeY[location].right >= right && treeY[location].exist == true)// ���� �ȿ� �ְ� �ڽ����� 
	{
		treeY[location].max = max(distance,treeY[location].max);
		make_Ytree(left,right,distance,location*2);
		make_Ytree(left,right,distance,location*2+1);
	}
	else if(left<treeY[location].left && right>treeY[location].left && right<treeY[location].right && treeY[location].exist== true) // ���� �ʰ� ������ ��ħ �ڽ����� 
	{
		treeY[location].max = max(distance,treeY[location].max);
		make_Ytree(treeY[location].left,right,distance,location*2);
		make_Ytree(treeY[location].left,right,distance,location*2+1);
	}
	else if(left>treeY[location].left && left<treeY[location].right && right>treeY[location].right && treeY[location].exist== true) // ������ �ʰ� ���� ��ħ �ڽ� ���� 
	{
		treeY[location].max = max(distance,treeY[location].max);
		make_Ytree(left,treeY[location].right,distance,location*2);
		make_Ytree(left,treeY[location].right,distance,location*2+1);	
	}
	else if(left<treeY[location].left && right>treeY[location].left && right<treeY[location].right && treeY[location].exist== false)
	{
	//������ �ʰ��ϰ� �������� ���������� �ڽ��� ������� 
		treeY[location*2].left = treeY[location].left;
		treeY[location*2].right = right;
		treeY[location*2].max = distance;
		treeY[location*2].exist = false;
		
		treeY[location*2+1].left = right;
		treeY[location*2+1].right = treeY[location].right;
		treeY[location*2+1].max = treeY[location].max;
		treeY[location*2+1].exist = false;
		
		treeY[location].exist=true;
		treeY[location].max = max(distance,treeY[location].max);
	}
	else if(left>treeY[location].left && left<treeY[location].right && right>treeY[location].right && treeY[location].exist== false)
	{
	//�������� �ʰ��ϰ� ������ ��ó������ �ڽ��� ���� ��� 
		treeY[location*2].left = treeY[location].left;
		treeY[location*2].right = left;
		treeY[location*2].max =treeY[location].max;
		treeY[location*2].exist = false;
		
		treeY[location*2+1].left = left;
		treeY[location*2+1].right = treeY[location].right;
		treeY[location*2+1].max = distance;
		treeY[location*2+1].exist = false;	
		
		treeY[location].exist=true;
		treeY[location].max = max(distance,treeY[location].max);
	}	
	//���̿ܿ��� ó�����մϴ� ^^ 
}

void make_Xtree(int left,int right, int distance,int location)// left : ���� ���� , right : ���� ���� , distance : �簢���� ���� , location : ���� ��� ��ġ 
{		
	if(treeX[location].left<left && treeX[location].right > right && treeX[location].exist == false) // ���� �ȿ� ������ �ڽ��� ���� �� 
	{		
		
		treeX[location*2].left = treeX[location].left;
		treeX[location*2].right = left;
		treeX[location*2].max = treeX[location].max;
		treeX[location*2].exist = false;
		
		treeX[location*2+1].left = left;
		treeX[location*2+1].right = treeX[location].right;
		treeX[location*2+1].max = max(distance,treeX[location].max);
		treeX[location*2+1].exist = true;
		
		treeX[(location*2+1)*2].left = left;
		treeX[(location*2+1)*2].right = right;
		treeX[(location*2+1)*2].max = distance;
		treeX[(location*2+1)*2].exist = false;
		
		treeX[(location*2+1)*2+1].left = right;
		treeX[(location*2+1)*2+1].right = treeX[location].right;
		treeX[(location*2+1)*2+1].max = treeX[location].max;
		treeX[(location*2+1)*2+1].exist = false;		
			
		treeX[location].exist = true;// �ڽ��� �����! 
		treeX[location].max = max(distance,treeX[location].max); // ū���� max������ ��ȯ!
	}
	else if(left == treeX[location].left && right < treeX[location].right && treeX[location].exist == false)//���ʿ� ���ļ� �����ȿ� ���ö� �׸��� �ڽ��� ������ 
	{
		treeX[location*2].left = left;
		treeX[location*2].right = right;
		treeX[location*2].max = distance;
		treeX[location*2].exist = false;
		
		treeX[location*2+1].left = right;
		treeX[location*2+1].right = treeX[location].right;
		treeX[location*2+1].max = treeX[location].max;
		treeX[location*2+1].exist = false;	
		
		treeX[location].exist = true;// �ڽ��� �����! 
		treeX[location].max = max(distance,treeX[location].max); // ū���� max������ ��ȯ!
	}
	else if(left > treeX[location].left && right == treeX[location].right && treeX[location].exist == false)//�����ʿ� ���ļ� �����ȿ� ���ö� �׸��� �ڽ��� ������ 
	{
		treeX[location*2].left = treeX[location].left;
		treeX[location*2].right = left;
		treeX[location*2].max = treeX[location].max;
		treeX[location*2].exist = false;
		
		treeX[location*2+1].left = left;
		treeX[location*2+1].right = right;
		treeX[location*2+1].max = distance;
		treeX[location*2+1].exist = false;	
		
		treeX[location].exist = true;// �ڽ��� �����! 
		treeX[location].max = max(distance,treeX[location].max); // ū���� max������ ��ȯ!		
		
	}
	else if(treeX[location].left>=left && treeX[location].right<=right)// ���� �ʰ��ؼ� ���� �� 
	{
		treeX[location].max = distance;
		treeX[location].exist = false;	
	}
	else if(treeX[location].left<=left && treeX[location].right >= right && treeX[location].exist == true)// ���� �ȿ� �ְ� �ڽ����� 
	{
		treeX[location].max = max(distance,treeX[location].max);
		make_Xtree(left,right,distance,location*2);
		make_Xtree(left,right,distance,location*2+1);
	}
	else if(left<treeX[location].left && right>treeX[location].left && right<treeX[location].right && treeX[location].exist== true) // ���� �ʰ� ������ ��ħ �ڽ����� 
	{
		treeX[location].max = max(distance,treeX[location].max);
		make_Xtree(treeX[location].left,right,distance,location*2);
		make_Xtree(treeX[location].left,right,distance,location*2+1);
	}
	else if(left>treeX[location].left && left<treeX[location].right && right>treeX[location].right && treeX[location].exist== true) // ������ �ʰ� ���� ��ħ �ڽ� ���� 
	{
		treeX[location].max = max(distance,treeX[location].max);
		make_Xtree(left,treeX[location].right,distance,location*2);
		make_Xtree(left,treeX[location].right,distance,location*2+1);	
	}
	else if(left<treeX[location].left && right>treeX[location].left && right<treeX[location].right && treeX[location].exist== false)
	{
	//������ �ʰ��ϰ� �������� ���������� �ڽ��� ������� 
		treeX[location*2].left = treeX[location].left;
		treeX[location*2].right = right;
		treeX[location*2].max = distance;
		treeX[location*2].exist = false;
		
		treeX[location*2+1].left = right;
		treeX[location*2+1].right = treeX[location].right;
		treeX[location*2+1].max = treeX[location].max;
		treeX[location*2+1].exist = false;
		
		treeX[location].exist=true;
		treeX[location].max = max(distance,treeX[location].max);
	}
	else if(left>treeX[location].left && left<treeX[location].right && right>treeX[location].right && treeX[location].exist== false)
	{
	//�������� �ʰ��ϰ� ������ ��ó������ �ڽ��� ���� ��� 
		treeX[location*2].left = treeX[location].left;
		treeX[location*2].right = left;
		treeX[location*2].max =treeX[location].max;
		treeX[location*2].exist = false;
		
		treeX[location*2+1].left = left;
		treeX[location*2+1].right = treeX[location].right;
		treeX[location*2+1].max = distance;
		treeX[location*2+1].exist = false;	
		
		treeX[location].exist=true;
		treeX[location].max = max(distance,treeX[location].max);
	}	
	//���̿ܿ��� ó�����մϴ� ^^ 
}
//bool Optimization[10001];
void test()
{
	treeY[1].right = 1000;// ���� ������Ѵ�.
	treeY[1].max = 0;
	treeY[1].exist = false;
	int left=90;
	int right=100;
	int max_value;
	make_Ytree(0,1000,10,1);
	make_Ytree(100,200,20,1);
	make_Ytree(150,250,15,1);
//	make_Ytree(100,120,320,1);
//	make_Ytree(70,80,100,1);
	max_value = look_maxY(left,right,1);
	cout<<"���: "<<max_value<<endl;
	int tmp=15;		
	cout<<"��� "<<treeY[tmp].left <<" "<<treeY[tmp].right<<" "<<treeY[tmp].max<<" "<<treeY[tmp].exist<<endl;		
}
void Procedure()
{

	bool TR = true;
	int distance;
	int max_value;
	
	while(TR)
	{
		TR = false;
	//	cout<<"Max_scaleY:"<<Max_scaleY<<endl;
		treeY[1].right = Max_scaleY;// ���� ������Ѵ�.
		treeY[1].max = 0;
		treeY[1].exist = false;
				
		//lower shift
		
		sort(L,L+N,YYY);

		for(int i=0;i<N;i++)
		{
			max_value = look_maxY(L[i].x,L[i].p,1);//�������� ����ū�� ��ȯ���� 
		
			distance = L[i].q - L[i].y;
			make_Ytree(L[i].x,L[i].p,distance + max_value,1);
			
			if(L[i].y == max_value)	continue; // it is not fall 
			
			TR = true;
			L[i].y = max_value;
			L[i].q = max_value + distance;
		}
		
		Max_scaleY = treeY[1].max;
		//left shift 

		sort(L,L+N,XXX);
		
		treeX[1].right = Max_scaleX;// ���� ������Ѵ�. 
		treeX[1].max = 0;
		treeX[1].exist = false;		
	//	cout<<"Max_scaleX:"<<Max_scaleX<<endl;
		for(int i=0;i<N;i++)
		{
			max_value = look_maxX(L[i].y,L[i].q,1); //�������� ����ū�� ��ȯ����
			
			distance = L[i].p - L[i].x;
			make_Xtree(L[i].y,L[i].q,distance + max_value,1);
			
			if(L[i].x == max_value) continue;
			
			TR = true;
			L[i].x = max_value;
			L[i].p = max_value + distance;
		}	
		Max_scaleX = treeX[1].max;
	}

}

int main(void)
{
	ifstream fin;
	ofstream fout;
	treeX[1].left = 0;
	treeY[1].left = 0;
	int T;
	int x,y;//lower-left vertex
	int p,q;//upeer-right vetex
	
	fin.open("block.inp");
	fout.open("block.out");
	
	fin>>T;
	
	for(int i=0;i<T;i++)
	{
		fin >> N; // number of lectangle
		Max_scaleX = 0;
		Max_scaleY = 0;
		for(int j=0;j<N;j++)
		{
			fin>>x;fin>>y; // Lower-left vertex
			fin>>p;fin>>q; // Upper-right vertex
			Max_scaleX = max(Max_scaleX,p);
			Max_scaleY = max(Max_scaleY,q);
			L[j].x = x;
			L[j].y = y;
			L[j].p = p;
			L[j].q = q;
		}
		Procedure();
		cout<< Max_scaleX << " " << Max_scaleY << endl;
		fout<< Max_scaleX << " " << Max_scaleY << endl;
			 
	}
	//test();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
