#include<stdio.h>
#include<conio.h>
#include<graphics.h>
typedef struct node
{
	int v1,v2,c;
}edgecol;
edgecol edge[100];
int main()
{

    int vclr[20],i=0,j,c,v=0,crn,k=0,t1,t2,t;
   int graph[100][100];
   char ch,str[100];
    FILE *fp;
    int gd=DETECT,gm;
   initgraph(&gd,&gm, "c:\\turboc3\\bgi");





 clrscr();
 fp=fopen("peterson.txt","r");
  if(fp==NULL)
	printf("error in file opening\n");
 while((ch=getc(fp))!=EOF)                  /* opening and reading the data file */
 {
	if(ch=='0'||ch=='1')
	{
		graph[v][i++]=ch-'0';
	}
	else if(ch=='\n')
	{
	v++;
	i=0;
	}
  }
  v++;
/* for(i=0;i<v;i++)                           //printing of adjacency matrix
  {
	for(j=0;j<v;j++)
		printf("%d   ",graph[i][j]);
	printf("\n");
  }
      //	printf("%c",ch);
  printf("%d",v);                   */
 fclose(fp);                      /* closing of file */


	for(i=0;i<20;i++)	 //assigning color to edges
	vclr[i]=-1;

	vclr[0]=1;

	for(i=1;i<v;i++)
	{
		c=1;
		for(j=0;j<v;j++)
		{
			if(graph[i][j]==1)
			{
				if(vclr[j]==c)
				{
					c++;
					j=0;

				}

			}
		}
		vclr[i]=c;
	}




	k=0;
	for(i=0;i<v;i++)                  //finding edges with end vertices
	{
		for(j=i+1;j<v;j++)
		{
			if(graph[i][j]==1)
			{
				edge[k].v1=i;
				edge[k].v2=j;
				edge[k].c=-1;
				k++;
			}
		}
	}

   //   printf("no. of edge is %d ",k);
	edge[0].c=1;
	for(i=1;i<k;i++)                   //assigning color to edges
	{
		edge[i].c=1;
		for(j=0;j<k;j++)
		{
			if(edge[i].v1==edge[j].v1||edge[i].v1==edge[j].v2||edge[i].v2==edge[j].v1||edge[i].v2==edge[j].v2)
			{
				if(edge[i].c==edge[j].c&&i!=j)
				{
						edge[i].c+=1;
						j=0;
				}


			}
		}
	}

	crn=edge[0].c;

	for(i=1;i<k;i++)     //finding chromatic number
	{
	if(edge[i].c>crn)
	    crn=edge[i].c;
	}

       printf("Chromatic number is %d \n" ,crn);


  setcolor(4);                            /*boundary color*/
   for(i=0;i<v;i++)
   {
		if(i%2==0)
			t=i*10;
		else
			t=-i*10;
	circle(t+100*vclr[i],30+20*i,5);
	//setfillstyle(1,vclr[i]);
	floodfill(t+100*vclr[i],30+20*i,4);
	delay(50);
   }


   for(i=0;i<k;i++)
   {
		setcolor(edge[i].c);

		if(edge[i].v1%2==0)
			t1=edge[i].v1*10;
		else
			t1=-edge[i].v1*10;

		if(edge[i].v2%2==0)
			t2=edge[i].v2*10;
		else
			t2=-edge[i].v2*10;

		line(t1+100*vclr[edge[i].v1],30+20*edge[i].v1,t2+100*vclr[edge[i].v2],30+20*edge[i].v2);
       delay(50);
   }

   getch();
   return 0;

}
