#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
   ifstream fin1, fin2;
   fin1.open("path.out");
   fin2.open("out1.out");

   bool check = true;
   string str1, str2;
   while (!fin1.eof() || !fin2.eof())
   {
   	
      getline(fin1, str1);
      getline(fin2, str2);
      if (str1 != str2)
      {
      	cout<<str1<<endl;
      	cout<<str2<<endl;
         check = false;
         break;
      }
   }

   if (check)
      cout << "정답" << endl;
   else
      cout << "오답" << endl;

   return 0;
}
