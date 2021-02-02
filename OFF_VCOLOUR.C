#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int check_degree(int x,int v,int m[][100])
{
	int i,deg;
	for(i=0;i<v;i++)
	{
		if(m[x][i]==1)
			deg++;
	}
	
	return deg;
}
int main()
{

    int vclr[20],i=0,j,c,v=0,crn;
   int graph[100][100],d,deg,edge=0;
   char ch,str[100];
    FILE *fp;
    int gd=DETECT,gm;
   initgraph(&gd,&gm, "c:\\turboc3\\bgi");





 clrscr();
 fp=fopen("graph.txt","r");
  if(fp==NULL)
	printf("error in file opening\n");
 while((ch=getc(fp))!=EOF)        						          /* opening and reading the data file */
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
/* for(i=0;i<v;i++)                          						 //printing of adjacency matrix
  {
	for(j=0;j<v;j++)
		printf("%d   ",graph[i][j]);
	printf("\n");
  }
      //	printf("%c",ch);
  printf("%d",v);                   
 fclose(fp); */		             									 /* closing of file */


	for(i=0;i<20;i++)	 											/*finding chomatic number*/
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

	crn=vclr[0];

	for(i=1;i<v;i++)
	{
	if(vclr[i]>crn)
	    crn=vclr[i];
	}


	for(i=0;i<v;i++)
	{
		for(j=i+1;j<v;j++)
		{
			if(graph[i][j]==1)
				edge++;
		}
	}
	printf("The number of edges:%d",edge);
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


    if(crn==3&&edge==15&&v==10)
	strcpy(str,"  It is a peterson graph");
	
	
	
	deg=check_degree(0,v,graph);
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
		
		
	if(v==edge)
	{
		if(v%2==0&&crn==2)
			printf("It is a cycle graph");
		else if(v%2==1&&crn==3)
			printf("It is a cycle graph");
	}
	
	if(edge<=(3*v-6))
		printf("It is a planar graph ");
		
	if(v==edge+1)
	{
		if((crn==2&&edge>=1)||(crn==1&&edge==0))
			printf("It is a star graph  ");
		
	}
	
	if(edge==2*(v-1))
	{
		if((v%2==0&&crn==4)||(v%2==1&&crn==3))
			printf("It is a wheel graph  ");
	}

       setcolor(14);
      
       printf("%s",str);
	 printf("  The Chromatic number is:%d " ,crn);

  setcolor(4);                           							 /*boundary color*/
   for(i=0;i<v;i++)
   {
	circle(100*vclr[i],50+50*i,5);
	setfillstyle(1,vclr[i]);
	floodfill(100*vclr[i],50+50*i,4);
   }

   setcolor(4);                      							    /*color of edges*/
   for(i=0;i<v;i++)
   {

	for(j=i+1;j<v;j++)												/*printing of edges*/
	{
		if(graph[i][j]==1)
		{
			line(100*vclr[i],50+50*i,100*vclr[j],50+50*j);
		}
	}
   }
   getch();
   return 0;

}
