#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>


	char pat1[]={"add"};
	char pat2[]={"sum"};
	char pat3[]={"subtraction"};
	char pat4[]={"difference"};
	char pat5[]={"multiply"};
	char pat6[]={"product"};
	char pat7[]={"divide"};
	char pat8[]={"quotient"};


int POW(int a,int b)
{
	if(b<0)
	return 1/POW(a,-b);
	else if(b==0)
	return 1;
	else if(b==1)
	return a;
	else
	return a*POW(a,b-1);
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


int digsearch(char *str,char *a,char *b)
{
	int c=0,n,i,j,f1=0,f2=0;
	char ch;
	n=strlen(str);

	while(str[c]!='\0')
	{
		ch=str[c];
		if(isdigit(ch))
		{
			for(i=c,j=0;str[i]!=' ';i++,j++)
			{
				a[j]=str[i];
				f1=1;
			}
			a[j]='\0';
		}
		if(f1==1)
		break;
		c++;
	}

	for(c=n;c>=0;c--)
	{
		ch=str[c];
		if(isdigit(ch))
		{
			for(i=c,j=0;str[i]!=' ';i--,j++)
			{
				b[j]=str[i];
				f2=1;
			}
			b[j]='\0';
		}
		if(f2==1)
		break;
	}
	strrev(b);
	if(f1==1&&f2==1)
	return 1;
	return 0;

}

int convert(char *s)
{
	int n,i,j,a[10],res=0;
	n=strlen(s);
	for(i=0;s[i]!='\0';i++)
	{
		a[i]=s[i]-'0';
	}

	for(i=n-1,j=0;i>=0;i--,j++)
	{
		res=res+a[i]*POW(10,j);
	}
	return res;

}

int main()
{
	int mres,dres,a,b,c;
	char ch='y',str[50],s1[10],s2[10];
	//clrscr();
	printf("################################################################################");
	printf("################################################################################");
	printf("#                                                                              #");
	while(ch=='y')
    {
	printf("#                           Enter the statement                                #");
	printf("#");
	fflush(stdin);
	gets(str);
	printf("#\n");
	mres=match(str);
	dres=digsearch(str,s1,s2);
	fflush(stdout);
	a=convert(s1);
	b=convert(s2);
	if(dres==1)
	 {
		switch(mres)
		{
			case 1: c=a+b;
    printf("#     The sum of %d and %d is %d                                               #",a,b,c);
				break;
			case 2:
				c=a-b;
    printf("#     The Difference of %d and %d is %d                                        #\n",a,b,c);
				break;
			case 3:
				c=a*b;
    printf("#     The Product of %d and %d is %d                                           #\n",a,b,c);
				break;
		       case 4:  if(b!=0)
				c=a/b;
    printf("#     The Quotient of %d and %d is %d                                          #\n",a,b,c);
				break;

		       default :
    printf("#     Invalid Keywords                                                         #\n");
				exit(0);


		}

	}
	else
	printf("#     Invalid Digits                                                            #\n");
	printf("#     Do you wan to continue(y/n)                                              #");
	printf("#");
	scanf("%c",&ch);
    }
    printf("#                                                                              #");
    printf("#                                                                              #");
    printf("#                                                                              #");
    printf("################################################################################");
    printf("################################################################################");
_getch();
return 0;
}
