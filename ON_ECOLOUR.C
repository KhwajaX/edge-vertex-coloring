#include<stdio.h>
#include<conio.h>
#include<graphics.h>

/*int check_degree(int x,int v,int m[][100])
{
	int i,deg;
	for(i=0;i<v;i++)
	{
		if(m[x][i]==1)
			deg++;
	}

	return deg;
}
*/
typedef struct node
{
	int v1,v2,c;
}edgecol;
edgecol edge[100];
int main()
{

    int vclr[20],i=0,j,c,v=0,crn,k=0;
    int v1,v2,e,ch=1;
   int graph[100][100],deg,d;
   char str[100];
    FILE *fp;
    int gd=DETECT,gm;
   initgraph(&gd,&gm, "c:\\turboc3\\bgi");





 clrscr();
 /*fp=fopen("graph.txt","r");
  if(fp==NULL)
	printf("error in file opening\n");
 while((ch=getc(fp))!=EOF)                  // opening and reading the data file
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
  printf("%d",v);
 fclose(fp);    */                  // closing of file



 for(i=0;i<100;i++)
 {

     for(j=0;j<100;j++)
     {
	 graph[i][j]=0;
     }
 }

 for(i=0;i<20;i++)	 //assigning color to edges
	vclr[i]=-1;

	vclr[0]=1;


 while(ch==1)
 {
	clrscr();

 printf("enter end point of vertex and edge\n");
 scanf("%d%d%d",&v1,&v2,&e);
 if(v2>v-1)
    v=v2+1;
 if(v1>v-1)
    v=v1+1;
 graph[v1][v2]=e;
 graph[v2][v1]=e;

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

      // printf("Chromatic number is %d \n" ,crn);





       printf("The number of edges:%d",k);
	printf("The number of vertex is %d",v);
	if(crn==1&&v==1)        										/*finding graph class*/
	strcpy(str," It is a pendent vertex");
	  else if(crn==1&&v>1)
	    strcpy(str," It is a forest graph");
    else if(crn==2)
	   strcpy(str," It is a bipartite graph");
    else if(crn==3)
	   strcpy(str," It is a tripartite graph");
    else
	strcpy(str," It is a simple graph");


    if(crn==3&&k==15&&v==10)
	strcpy(str,"  It is a peterson graph");



	if(v==k+1)
	{
		if((crn==2&&k>=1)||(crn==1&&k==0))
			printf("It is a star graph  ");

	}

	if(k==2*(v-1))
	{
		if((v%2==0&&crn==4)||(v%2==1&&crn==3))
			printf("It is a wheel graph  ");
	}


	/*deg=check_degree(0,v,graph);
	for(i=0;i<v;i++)
	{
		d=check_degree(i,v,graph);
		if(d==deg)
			continue;
		else
			break;

	}
	if(i==v)
		printf("It is a regular graph");


	if(v==k)
	{
		if(v%2==0&&crn==2)
			printf("It is a cycle graph");
		else if(v%2==1&&crn==3)
			printf("It is a cycle graph");
	}

	if(k<=(3*v-6))
		printf("It is a planar graph ");   */


       setcolor(14);

       printf("%s",str);
	 printf("  The Chromatic number is:%d " ,crn);



  setcolor(4);                            /*boundary color*/
   for(i=0;i<v;i++)
   {
	circle(100*vclr[i],30+20*i,5);
	//setfillstyle(1,vclr[i]);
	floodfill(100*vclr[i],30+20*i,4);
   }


   for(i=0;i<k;i++)
   {
		setcolor(edge[i].c);
		line(100*vclr[edge[i].v1],30+20*edge[i].v1,100*vclr[edge[i].v2],30+20*edge[i].v2);
   }

    printf("Do you want to continue enter (1/0)\n");
   scanf("%d",&ch);

 }
   getch();
   return 0;

}
