#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

FILE *r_p = fopen("paper.inp", "r");
FILE *w_p = fopen("paper.out", "w");

int paper_count=0;
int papers[2001][4];
int paper_x_size[4001];
int paper_x_count=0;
int paper_y_size[4001];
int paper_y_count=0;
int space[4001][4001];
int n1=0, n2=0, n3=0;


void Init();
void paper_sort();
int compare(const void*, const void*);
void show_paper_state();
void reading_state(int, int);
int main()
{
   /*for (int i = 0; i < 2001; i++)
   {
      for (int j = 0; j < 4; j++)
      {
         papers[i][j] = 0;
      }
   }
   for (int i = 0; i < 4001; i++)
   {
      for (int j = 0; j < 4001; j++)
      {
         space[i][j] = 0;
         paper_x_size[j] = 0;
         paper_y_size[j] = 0;
      }
   }*/
   Init();
   paper_sort();
   show_paper_state();
   //cout << n1 << " " << n2 << " " << n3 << endl;
   fprintf(w_p, "%d %d %d\n", n1, n2, n3);
   /*cout << paper_x_count << endl<<"=>";
   for (int i = 0; i < paper_x_count; i++)
   {
      cout << paper_x_size[i] << " ";
   }
   cout << endl;

   for (int i = 0; i < paper_y_count; i++)
   {
      cout << paper_y_size[i] << " ";
   }
   cout << endl;

   for (int i = 0; i < paper_count; i++)
   {
      cout << papers[i][0]<<" " << papers[i][1] << " " << papers[i][2] << " " << papers[i][3] << endl;
   }*/
   fclose(w_p);
   fclose(r_p);
   return 0;
}

void Init()
{
   fscanf(r_p, "%d\n", &paper_count);
   paper_x_count = 0;
   paper_y_count = 0;
   n1 = 0;
   n2 = 0;
   n3 = 0;
   int check1=0 ,check2=0;
   for (int i = 0; i < paper_count; i++)
   {
      fscanf(r_p, "%d", &papers[i][0]);
      fscanf(r_p, "%d", &papers[i][1]);
      fscanf(r_p, "%d", &papers[i][2]);
      fscanf(r_p, "%d", &papers[i][3]);
      check1 = 0, check2 = 0;
      
      
      //x 좌표 압축
      for (int j = 0; j < paper_x_count; j++)
      {
         if (check1 == 1 && check2 == 1)
         {
            break;
         }
         
         if (paper_x_size[j] == papers[i][0])
         {
            check1 = 1;
         }
         if (paper_x_size[j] == papers[i][0] + papers[i][2])
         {
            check2 = 1;
         }
      }
      if (check1 == 0)
      {
         //cout << papers[i][0] << "추가" << endl;
         paper_x_size[paper_x_count++] = papers[i][0];
      }
      if (check2 == 0)
      {
         //cout <<papers[i][0]<<"+"<<papers[i][2] << "추가" << endl;
         paper_x_size[paper_x_count++] = papers[i][0] + papers[i][2];
      }
      
      check1 = 0, check2 = 0;
      //y좌표 압축
      for (int j = 0; j < paper_y_count; j++)
      {
         if (check1 == 1 && check2 == 1)
         {
            break;
         }

         if (paper_y_size[j] == papers[i][1])
         {
            check1 = 1;
         }
         if (paper_y_size[j] == papers[i][1] + papers[i][3])
         {
            check2 = 1;
         }
      }
      if (check1 == 0)
      {
         paper_y_size[paper_y_count] = papers[i][1];
         paper_y_count++;
      }
      if (check2 == 0)
      {
         paper_y_size[paper_y_count] = papers[i][1] + papers[i][3];
         paper_y_count++;
      }
   }
   
}

void paper_sort()
{
   qsort(paper_x_size, paper_x_count, sizeof(int), compare);
   qsort(paper_y_size, paper_y_count, sizeof(int), compare);
}

int compare(const void* a, const void* b)
{
   int num1 = *(int*)a;
   int num2 = *(int*)b;

   if (num1 < num2)
   {
      return -1;
   }
   else if (num1 > num2)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

void show_paper_state()
{
   int x_s_po = 0, x_e_po = 0, y_s_po = 0, y_e_po = 0;
   int count1 = 0, count2 = 0;
   for (int i = paper_count-1; i >-1; i--)
   {
      x_s_po = 0;
      x_e_po = 0;
      y_s_po = 0;
      y_e_po = 0;

      for (int j = 0; j < paper_x_count; j++)
      {
         if (papers[i][0] == paper_x_size[j])
         {
            x_s_po = j;
         }
         if (papers[i][0] + papers[i][2] == paper_x_size[j])
         {
            x_e_po = j;
            break;
         }
      }

      for (int j = 0; j < paper_y_count; j++)
      {
         if (papers[i][1] == paper_y_size[j])
         {
            y_s_po = j;
         }
         if (papers[i][1] + papers[i][3] == paper_y_size[j])
         {
            y_e_po = j;
            break;
         }
      }
      
      count1=0, count2=0;
      for (int j = y_s_po; j < y_e_po; j++)
      {
         for (int k = x_s_po; k < x_e_po; k++)
         {
            if (space[j][k] == 1)
            {
               count1++;
            }
            space[j][k] = 1;
            count2++;
         }
      }
      reading_state(count1, count2);
   }
}

void reading_state(int number1, int number2)
{
   if (number1 == 0)
   {
      n3++;
   }
   else if (number1 == number2)
   {
      n1++;
   }
   else
   {
      n2++;
   }
}
