#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

	char pat1[]={"add"};
	char pat2[]={"sum"};
	char pat3[]={"substract"};
	char pat4[]={"difference"};
	char pat5[]={"multiply"};
	char pat6[]={"product"};
	char pat7[]={"divide"};
	char pat8[]={"quotient"};
int stack[10];
int top=-1;
int empty()
{
	if(top==-1)
	return 1;
	return 0;
}

void push(int item)
{
	stack[++top]=item;
}
int pop()
{
	int item;
	item=stack[top--];
	return item;
}

int match(char *str)
{

	int i=0,m=0;
	while(str[m]!='\0')
	{
		if(str[m]==pat1[i] || str[m]==pat2[i])
		{
			i++;m++;
			if(pat1[i]=='\0' || pat2[i]=='\0')
			{

				return 1;
			}
		}

		else if(str[m]==pat3[i] || str[m]==pat4[i])
		{
			i++;m++;
			if(pat3[i]=='\0' || pat4[i]=='\0')
			{

				return 2;
			}
		}

		else if(str[m]==pat5[i] || str[m]==pat6[i])
		{
			i++;m++;
			if(pat5[i]=='\0' || pat6[i]=='\0')
			{

				return 3;
			}
		}

		else if(str[m]==pat7[i] || str[m]==pat8[i])
		{
			i++;m++;
			if(pat7[i]=='\0' || pat8[i]=='\0')
			{

				return 4;
			}
		}
		else
		{
		 m++;

		 }


	}
 return 0;

}

int digsearch(char *str)
{
	int i;
	char ch;
	for(i=0;str[i]!='\0';i++)
	{
		ch=str[i];

		if(isdigit(ch))
		push(ch -'0');
	}
	if(empty())
	return 0;
	return 1;
}
int main()
{
	int mres,dres,a,b;
	char str[50];
	clrscr();
	printf("Enter the statement\n");
	gets(str);
	mres=match(str);
	dres=digsearch(str);
	if(dres==1)
	 {
		switch(mres)
		{
			case 1:
				b=pop();
				a=pop();
				push(a+b);
				break;
			case 2:
				b=pop();
				a=pop();
				push(a-b);
				break;
			case 3:
				b=pop();
				a=pop();
				push(a*b);
				break;
		       case 4:
				b=pop();
				a=pop();
				if(b!=0)
				push(a/b);
				break;

		       default :
				printf("Invalid Ketwords\n");
				exit(0);


		}
	 printf("The result is %d",pop());
	}
	else
	printf("Invalid Digits\n");


getch();
return 0;
}


