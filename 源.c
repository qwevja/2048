#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 4

int add(int n[4][4])
{
    int xy[16][2]; int count = 0;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (n[i][j] == 0)
            {
                xy[count][0] = i;
                xy[count][1] = j;
                count++;

            }
        }
    }
    if(count==0)
        return -1;
    int a = rand() % count;
    int b = rand() % 2+1;
    n[xy[a][0]][xy[a][1]] = b*2;

}
//+2/4
int locchange(int n[4][4],char a)
{
    if(a=='w')
        for (size_t i = 0; i < max; i++)
        {
            int count = 0;
            for (size_t j = 0; j < max; j++)
            {
                if (n[j][i] != 0)
                {
                    n[count][i] = n[j][i];
                    if(j!=count)
                    n[j][i] = 0;
                    count++;
                }
            }
        }
    if (a == 's')
        for (size_t i = 0; i <4; i++)
        {
            int count = max-1;
            for (int j = max-1; j>=0; j--)
            {//j==x
                if (n[j][i] != 0)
                {
                    n[count][i] = n[j][i];
                    if (j != count)
                        n[j][i] = 0;
                    count--;
                }
            }
        }
    if (a == 'a')
        for (size_t i = 0; i < max; i++)
        {
            int count = 0;
            for (size_t j = 0; j < max; j++)
            {//j==y
                if (n[i][j] != 0)
                {
                    n[i][count] = n[i][j];
                    if (j != count)
                        n[i][j] = 0;
                    count++;
                }
            }
        }
    if (a == 'd')
        for (size_t i = 0; i < 4; i++)
        {
            int count = max - 1;
            for (int j = max - 1; j >= 0; j--)
            {//j==x
                if (n[i][j] != 0)
                {
                    n[i][count] = n[i][j];
                    if (j != count)
                        n[i][j] = 0;
                    count--;
                }
            }
        }
}
int sam(int n[4][4],char a)
{
    if(a=='w')
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (n[i][j] == n[i + 1][j])
            {
                n[i][j] *= 2;
                n[i + 1][j] = 0;
            }
        }
    }
    if (a == 's')
        for (size_t i = max-1; i >0; i--)
        {
            for (size_t j = 0; j <4; j++)
            {//j==y
                if (n[i][j] == n[i -1][j])
                {
                    n[i][j] *= 2;
                    n[i -1][j] = 0;
                }
            }
        }
    if (a == 'a')
        for (size_t i = 0; i<max; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {//j==y
                if (n[i][j] == n[i][j+1])
                {
                    n[i][j] *= 2;
                    n[i][j+1] = 0;
                }
            }
        }
    if (a == 'd')
        for (size_t i = max - 1; i > 0; i--)
        {
            for (size_t j = max-1; j >0; j--)
            {//j==y
                if (n[i][j] == n[i][j -1])
                {
                    n[i][j] *= 2;
                    n[i][j -1] = 0;
                }
            }
        }
}

int qwe(int n[4][4])
{
    int i =0 ;
    char a = 'w';
    
    do 
    {
        a = getchar();
    } while (a == '\n');
    locchange(n, a);
 
    sam(n, a);
    locchange(n, a);
    add(n);
    
    for (size_t i = 0; i < max; i++)
    {
        for (size_t j = 0; j < max; j++)
        {
            printf("%2d ", n[i][j]);
        }
        printf("\n");
    } 
    if (i == -1)
        return 0;
    if (a != 'p')
            qwe(n);

}
int main(void)
{
    srand((unsigned int)time(NULL));
    int n[4][4] = { 0 };
    char a = 'w';
    printf("a=='p'时结束:\n");
    add(n);
    for (size_t i = 0; i < max; i++)
    {
        for (size_t j = 0; j < max; j++)
        {
            printf("%2d ", n[i][j]);
        }
        printf("\n");
    }

    qwe(n);
    printf("游戏结束");
    return 0;
}