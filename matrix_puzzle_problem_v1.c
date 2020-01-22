#include<conio.h>
#include<stdio.h>
#include<malloc.h>
int init[10][10],goal[10][10];
long long int level;
struct node{

  int ss[10][10];
  long long int level;
  struct node *next;
  struct node *pre;
  char move;
};
void checkexist(struct node *mat,int x,int y,int w);
void fun(int x,int y);
void printresult(struct node *last,char ch,int x,int y);
int checkequality(int mat1[][10],int mat2[][10],int x,int y);
void upmove(int mat[][10],int x,int y);
void downmove(int mat[][10],int x,int y);
void leftmove(int mat[][10],int x,int y);
void rightmove(int mat[][10],int x,int y);
void print(int mat[][10],int x,int y);
void apply(struct node *mat,int x,int y);
void copy(int mat1[][10],int mat2[][10],int x,int y);
struct node *start;
int main()
{
    int x,y,i,j;

    struct node *temp;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->next=NULL; temp->level=0; temp->pre=NULL; temp->move='i';
     printf("enter matrix dimensions  X and Y\n");
     scanf("%d%d",&x,&y);
      printf("******************** Enter only integer\t ******   0 (zero) is taken as blank******************* \n");
      printf("enter source matrix\n");
      for(i=0;i<x;i++)
       {
        for(j=0;j<y;j++)
    {
        scanf("%d",&init[i][j]);
        temp->ss[i][j]=init[i][j];
    }}

    start=temp;
    printf("\nenter goal matrix\n");
    for(int i=0;i<x;i++)
    {for(int j=0;j<y;j++)
      {
        scanf("%d",&goal[i][j]);
      }
    }
    printf("\nenter number of level upto you want to check => ");
    scanf("%d",&level);
    if(checkequality(init,goal,x,y))
    {
        printf("match found");
    }
     else{
        fun(x,y);
     }

}
void fun(int x,int y)
 {
     struct node *run;
        run=start;
     while(run!=NULL)
         {     apply(run,x,y);
               run=run->next;
         }
 }
void apply(struct node *mat,int x,int y)
 {
         if(mat->level==level)
         {
             return;
         }
           int i,j;
           struct node *mat1,*mat2,*mat3,*mat4;
           mat1=(struct node *)malloc(sizeof(struct node));
           mat1->next=NULL; mat1->level=mat->level+1; mat1->pre=mat; mat1->move=mat->move;
           mat2=(struct node *)malloc(sizeof(struct node));
           mat2->next=NULL; mat2->level=mat->level+1; mat2->pre=mat; mat2->move=mat->move;
           mat3=(struct node *)malloc(sizeof(struct node));
           mat3->next=NULL; mat3->level=mat->level+1;  mat3->pre=mat; mat3->move=mat->move;
           mat4=(struct node *)malloc(sizeof(struct node));
           mat4->next=NULL; mat4->level=mat->level+1; mat4->pre=mat; mat4->move=mat->move;
                      copy(mat1->ss,mat->ss,x,y);
                     copy(mat2->ss,mat->ss,x,y);
                     copy(mat3->ss,mat->ss,x,y);
                     copy(mat4->ss,mat->ss,x,y);

             upmove(mat1->ss,x,y);
             if(checkequality(mat1->ss,goal,x,y)==1)
            {
                  printf("\nup  level=> %ld\n",mat1->level);
                 printf("\n ************************match  found**************************************");
                 printresult(mat1,'u',x,y);
                 printf("\npree any key to continue");
                 getch();
            }
             else {
                   checkexist(mat1,x,y,1);
             }
            leftmove(mat2->ss,x,y);
            if(checkequality(mat2->ss,goal,x,y)==1)
            {
                printf("\nleft  level=> %ld\n",mat2->level);
                printf("\n ************************match  found************************************** ");
                printresult(mat2,'l',x,y);
                printf("\npree any key to continue");
                getch();
           }
                         else {
                   checkexist(mat2,x,y,2);
             }
            rightmove(mat3->ss,x,y);
            if(checkequality(mat3->ss,goal,x,y)==1)
            {
                printf("\nright  level=> %ld\n",mat3->level);
             printf(" ************************match  found**************************************");
              printresult(mat3,'r',x,y);
             printf("\npree any key to continue");
              getch();
              }

                      else {
                   checkexist(mat3,x,y,3);
             }

            downmove(mat4->ss,x,y);
             if(checkequality(mat4->ss,goal,x,y)==1)
                 {    printf("\ndown  level=> %ld\n",mat4->level);
                     printf("\n************************match  found**************************************");
                     printresult(mat4,'d',x,y);
                     printf("\npree any key to continue");
                      getch();
                }
             else {
                   checkexist(mat4,x,y,4);
                  }
 }

void printresult(struct node *last,char ch,int x,int y)
 {
     struct node *run,*temp[level];
     long int i=0,j;
     run=last->pre;
    temp[i]=last; i++;
     while(run!=NULL)
     {
         temp[i]=run; i++;
         run=run->pre;
     }
     printf("\n\n");
     for(j=i-2;j>0;j--)
     {
            if(temp[j]->move=='u'){ printf("\nUP");}
            if(temp[j]->move=='r'){ printf("\nRIGHT");}
            if(temp[j]->move=='l'){ printf("\nLEFT");}
            if(temp[j]->move=='d'){ printf("\nDOWN");}
             //printf("%c\t",temp[j]->move);
             print(temp[j]->ss,x,y);
              //printf("\n moves %c\t",ch);
     }
            if(ch=='u'){ printf("\nUP");}
            if(ch=='r'){ printf("\nRIGHT");}
            if(ch=='l'){ printf("\nLEFT");}
            if(ch=='d'){ printf("\nDOWN");}
            print(temp[j]->ss,x,y);
 }
 void print(int mat[][10],int x,int y)
{
    int i,j;
    for(i=0;i<x;i++)
    {
        printf("\n");
        for(j=0;j<y;j++)
        {
            printf("%d\t",mat[i][j]);
        }
    }
}
 void copy(int mat1[][10],int mat2[][10],int x,int y)
{
    int i,j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
              mat1[i][j]=mat2[i][j];
        }
    }
}
  checkexist(struct node *mat,int x,int y,int w)
{
    int i,j;
     struct node *temp,*t;
     temp=start;
      int p=0,ee[10][10];
        while(temp!=NULL)
        {
            /*for(i=0;i<x;i++)
            {
                for(j=0;j<y;j++)
                {
                  ee[i][j]=temp->ss[i][j];
                }
            }*/
              copy(ee,temp->ss,x,y);
             p=checkequality(ee,mat->ss,x,y);
            if(p==1)
            {
                return;
            }
            temp=temp->next;
        }
        t=(struct node *)malloc(sizeof(struct node));
        t->next=NULL;
        if(w==1){ mat->move='u'; printf("\nup    level=> %ld",mat->level);}
        if(w==4){ mat->move='d'; printf("\ndown  level=> %ld",mat->level);}
        if(w==2){ mat->move='l';printf("\nleft   level=> %ld",mat->level);}
        if(w==3){ mat->move='r';printf("\nright  level=> %ld",mat->level);}

         copy(t->ss,mat->ss,x,y);
         t->level=mat->level;
         t->move=mat->move;
         t->pre=mat->pre;

        temp=start;
       while(temp->next!=NULL)
       {
           temp=temp->next;
       }
      temp->next=t;
      return;
}
    void upmove(int mat[][10],int x,int y)
{
    int i,j,temp;
    for(i=1;i<x;i++)
     {
         for(j=0;j<y;j++)
         {
               if(mat[i][j]==0)
               {
                  temp=mat[i-1][j];
                   mat[i-1][j]=0;
                   mat[i][j]=temp;
                  // printf("up");
                   goto step;
               }
         }
    }
    step:{
         printf("");
    }
}
void downmove(int mat[][10],int x,int y)
{
    int i,j,temp;
    for(i=0;i<(x-1);i++)
     {
         for(j=0;j<y;j++)
         {
               if(mat[i][j]==0)
               {
                 //  int temp;
                   temp=mat[i+1][j];
                   mat[i+1][j]=0;
                   mat[i][j]=temp;
                  // printf("down");
                   goto step;
               }
         }
    }
   step:{
           printf("");
   }
}
void leftmove(int mat[][10],int x,int y)
{
    int i,j,temp;
    for(i=0;i<x;i++)
     {
         for(j=1;j<y;j++)
         {
               if(mat[i][j]==0)
               {
                //   int temp;
                   temp=mat[i][j-1];
                   mat[i][j-1]=0;
                   mat[i][j]=temp;
                  // printf("left");
                   goto step;
               }
         }
    }
    step:{

           printf("");
    }
}
void rightmove(int mat[][10],int x,int y)
{
    int i,j,temp;
    for(i=0;i<x;i++)
     {
         for(j=0;j<(y-1);j++)
         {
               if(mat[i][j]==0)
               {
                //   int temp;
                   temp=mat[i][j+1];
                   mat[i][j+1]=0;
                   mat[i][j]=temp;
                           // printf("right");
                   goto step;
               }
         }
    }
    step:{
             printf("");
    }
}
int checkequality(int mat1[][10],int mat2[][10],int x,int y)
{
    int i,j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            if(mat1[i][j]!=mat2[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}


