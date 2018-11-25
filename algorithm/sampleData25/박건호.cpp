#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

template<typename T>
void swap_(T& _input1, T& _input2)
{
   T Temp = _input1;
   _input1 = _input2;
   _input2 = Temp;
}

const int INF = 10e8 + 777;

ifstream fin;
ofstream fout;

struct p
{
   int floor;
   int down;
   int up;
};
/*
class p
{
public:
   int floor;
   int down;
   int up;

   p() : floor(0), down(0), up(0) {}
   p(int floor_, int down_, int up_) : floor(floor_), down(down_), up(up_) {}
   bool operator <(p &W);
   bool operator >(p &W);
};

bool p::operator<(p &W)
{
   if (this->floor < W.floor)
      return true;
   else if (this->floor == W.floor && this->down > W.down)
      return true;
   else if (this->floor == W.floor && this->down == W.down && this->up > W.up)
      return true;
   else
      return false;
}

bool p::operator>(p &W)
{
   if (this->floor > W.floor)
      return true;
   else if (this->floor == W.floor && this->down < W.down)
      return true;
   else if (this->floor == W.floor && this->down == W.down && this->up < W.up)
      return true;
   else
      return false;
}
*/

struct map_
{
   int min[501];
   int sum;
};

pair<int, int> best[201][201];
p c[501];
map_ map[201][201];

int main()
{
   fin.open("elevator.inp");
   fout.open("elevator.out");

   int T, n, K; // n : ž�°� ��, k : ���� ���� Ƚ��
   int maxFloor, a, b, MOON[501];
   int temp[501], temp2, temp3;
   fin >> T;
   while (T--)
   {
      maxFloor = 0;
      fin >> n >> K;
      //c.clear();
      for (int i = 0; i < n; i++)
      {
         //fin >> f >> down >> up;
         fin >> c[i].floor >> c[i].down >> c[i].up;
         //c.push_back(p(f, down, up));
         maxFloor = max(maxFloor, c[i].floor);
      }
      //sort(c.begin(), c.end());
      

      

      // c.back().floor
      // maxFloor
      // K�� 1�� �� ����
      for (int i = 1; i <= maxFloor; i++) // ������ ���� ����
      {
         map[i][1].sum = 0;
         for (int j = 0; j < n; j++) // ����� ���� ����
         {
            if (c[j].floor > i) // ������ �ö󰡾� �Ѵ�.
            {
               map[i][1].min[j] = c[j].up * (c[j].floor - i);
            }
            else
            {
               a = c[j].up * (c[j].floor - 1);
               b = c[j].down * (i - c[j].floor);
               map[i][1].min[j] = min(a, b);
            }
            map[i][1].sum += map[i][1].min[j];
         }
      }
      cout << "=================================" << endl;

      for (int i = 2; i <= K; i++) // K�� ���� ����
      {
         for (int j = 1; j <= maxFloor; j++) // F�� ���� ����
         {
            map[j][i].sum = 0;
            temp3 = INF;
            for (int jj = i; jj < j; jj++) // �ٷ� ������ ����
            {
               temp2 = 0;
               for (int k = 0; k < n; k++) // ����� ���� ����
               {
                  if (c[k].floor > j) // ������ �ö󰣴�
                  {
                     temp[k] = c[k].up * (c[k].floor - j);
                  }
                  else
                  { 
                     a = c[k].up * (c[k].floor - 1);
                     b = c[k].down * (j - c[k].floor);
                     temp[k] = min(a, b);
                  }
                  if (map[jj][i - 1].min[k] < temp[k]) // ���� ���� ���� ���� ��
                  {
                     temp[k] = map[jj][i - 1].min[k];
                  }
                  temp2 += temp[k];
               }
               if (temp3 > temp2)
               {
                  temp3 = temp2;
                  for (int k = 0; k < n; k++)
                     MOON[k] = temp[k];
               }
            }
            map[j][i].sum = temp3;
            for (int jj = 0; jj < n; jj++)
               map[j][i].min[jj] = MOON[jj];
            //for (int k = 0; k < n; k++)
            //   map[j][i].sum += map[j][i].min[k];
            //if (map[j - 1][i].sum < map[j][i].sum && map[j - 1][i].sum != 0)
            //   map[j][i].sum = map[j - 1][i].sum;
         }
      }


      int min_ = INF;
      for (int i = 2; i <= maxFloor; i++)
      {
         cout << i << "�� : " << map[i][K].sum << endl;
         if (min_ > map[i][K].sum)
            min_ = map[i][K].sum;
      }

      fout << min_ << endl;
   }

   fin.close();
   fout.close();
   return 0;
}
