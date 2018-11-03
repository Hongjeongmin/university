#include<iostream>
#include<fstream>
using namespace std;
int T;
int len;
int arr[100001];
int p;
int tmp; 

class List
{
	public:
		int cnt=0;
		int size;
		List *next=NULL;
};
List list[100001];
List *head;
List *n_list; 

void init_list(int& p,int& size)//�ʱ�ȭ�ϴ��۾� ó�� ���̰� ������� 
{
	list[p].next = NULL;
	list[p].size = size;
	if(p==0)
	{
		list[p].cnt=1;
	}
	else
	{
		list[p].cnt=0;
		head = &list[p-1];
	//	cout<<"p: "<<p-1<<endl;
		while(true)
		{
	//		cout<<"size: "<<head->size<<" cnt: "<<head->cnt<<endl;
			if(size>head->size) list[p].cnt = (list[p].cnt + head->cnt)%1000000007;	
			if(head->next==NULL) break;
			head = head->next;
		}
	//	cout<<"p: "<<p<<endl;
	//	cout<<"size: "<<list[p].size<<" cnt: "<<list[p].cnt<<endl;		
	}
}
void new_list(int& p,int& size)// �ʱ�ȭ���� �迭�� ���Ӱ� ������  
{
	n_list = &list[p];
	while(true)
	{
		if(n_list->next == NULL) 
		{
			n_list->next = new List[1];
			n_list = n_list->next;
			break;
		}
		n_list = n_list->next;
	}
	n_list->size=size;	
	if(p==0)
	{	
		n_list->cnt=1;
	}
	else
	{
		head = &list[p-1];
		while(true)
		{
			if(size>head->size) n_list->cnt =(n_list->cnt + head->cnt)%1000000007;
			
			if(head->next == NULL) break;
			head = head->next;
		}		
	}
	
}
int how(int& p)
{
	int cnt=0;
	head = &list[p];
	
	while(true)
	{
		cnt = (cnt + head->cnt)%1000000007;
		if(head->next==NULL)break;
		head= head->next;
	}
	return cnt;
}

int towgin(int end, int &tmp)//���������� tmp �ڸ�ã�� 
{
	int start=0;
	int mid;
	while(true)
	{
		mid = (start+end)/2;
		if(arr[mid]>=tmp)
		{
			if(start==mid)
			{
				return mid;
			} 
			end = mid;
		}
		else
		{
			if(start==mid)
			{
				return mid+1;
			}
			start =mid;
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
		p=0;//�ʱ� �迭 ����Ű�� ��ġ 
		fin>>len;
		fin>>arr[0];
		init_list(p,arr[0]);
		for(int j=1;j<len;j++)
		{
			fin>>tmp;
			
			if(arr[p] < tmp)
			{
				// �迭�� ��� ������ ���� ���� ���� ũ��
				p++;
				arr[p] = tmp; // �����ٰ� ������ �� �߰�
				init_list(p,tmp);
			}
			else
			{
				//���� tmp�� p-1������ �迭 ���� ���� �մ°��� �ֳ�?
				buffer = towgin(p,tmp); 
				arr[buffer] = tmp;
				new_list(buffer,tmp);
			}
		}

	//	cout<<p+1<<" "<<how(p)%1000000007<<endl;
		fout<<p+1<<" "<<how(p)%1000000007<<endl;	
	}	
}
	

