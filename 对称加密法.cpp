//密钥：XJBRHN 
#include <stdio.h>
#include <math.h>
#define MAX 7 

void number_change_b(void);
void number_change_a1(void);
void number_change_a2(void);
void exchange(void);
void output(void);

char b[MAX]={'X','J','B','R','H','N'};
char a[MAX];

int main(void)
{	
	
	int i=1,change=0;
	FILE *p;

	number_change_b();
	p=fopen("E:/明文.txt","r");
	for(;;){
		for(change=0;change<=5;change++)
			a[change]='*';
		fgets(a,MAX,p);
		number_change_a1();
		exchange();
		number_change_a2();
		output();
		if(feof(p))
			break;
	}
	fclose(p);
	p=fopen("E:/明文.txt","w");
	fclose(p);
	return 0;
	
}

void exchange(void)
{ 
	int i=-1,change;
	while (i<=5)
	{	
		i++;
		if(a[i]>27)
			continue;
		if(a[i]=='*')
			break;
		change=a[i];
		a[i]=(b[i]+change)%27;
		
	}		
}
void output(void)
{
	int i=0;
	FILE *r;
	r=fopen("E:/密文.txt","a+");
	for(;i<=5;i++)	
		fprintf(r,"%c",a[i]);
	fclose(r);	
}

void number_change_b(void)
{
	int i=0;
	for(;i<=5;i++)
	{
		switch(b[i]) {
			case 'A' : b[i]=01;
							break;
			case 'B' : b[i]=02;
							break;
			case 'C' : b[i]=03;
							break;
			case 'D' : b[i]=04;
							break;							
			case 'E' : b[i]=05;
							break;							
			case 'F' : b[i]=06;
							break;							
			case 'G' : b[i]=07;
							break;
			case 'H' : b[i]=8;
							break;							
			case 'I' : b[i]=9;
							break;							
			case 'J' : b[i]=10;
							break;
			case 'K' : b[i]=11;
							break;
			case 'L' : b[i]=12;
							break;
			case 'M' : b[i]=13;
							break;							
			case 'N' : b[i]=14;
							break;							
			case 'O' : b[i]=15;
							break;							
			case 'P' : b[i]=16;
							break;
			case 'Q' : b[i]=17;
							break;							
			case 'R' : b[i]=18;
							break;							
			case 'S' : b[i]=19;
							break;
			case 'T' : b[i]=20;
							break;
			case 'U' : b[i]=21;
							break;
			case 'V' : b[i]=22;
							break;							
			case 'W' : b[i]=23;
							break;							
			case 'X' : b[i]=24;
							break;							
			case 'Y' : b[i]=25;
							break;
			case 'Z' : b[i]=26;
							break;							
			case ' ' : b[i]=00;
							break;																					
		}	
	}
}
void number_change_a1(void)
{
	int i=0;
	for(;i<=5;i++)
	{
		switch(a[i]) {
			case 'A' : a[i]=01;
							break;
			case 'B' : a[i]=02;
							break;
			case 'C' : a[i]=03;
							break;
			case 'D' : a[i]=04;
							break;							
			case 'E' : a[i]=05;
							break;							
			case 'F' : a[i]=06;
							break;							
			case 'G' : a[i]=07;
							break;
			case 'H' : a[i]=8;
							break;							
			case 'I' : a[i]=9;
							break;							
			case 'J' : a[i]=10;
							break;
			case 'K' : a[i]=11;
							break;
			case 'L' : a[i]=12;
							break;
			case 'M' : a[i]=13;
							break;							
			case 'N' : a[i]=14;
							break;							
			case 'O' : a[i]=15;
							break;							
			case 'P' : a[i]=16;
							break;
			case 'Q' : a[i]=17;
							break;							
			case 'R' : a[i]=18;
							break;							
			case 'S' : a[i]=19;
							break;
			case 'T' : a[i]=20;
							break;
			case 'U' : a[i]=21;
							break;
			case 'V' : a[i]=22;
							break;							
			case 'W' : a[i]=23;
							break;							
			case 'X' : a[i]=24;
							break;							
			case 'Y' : a[i]=25;
							break;
			case 'Z' : a[i]=26;
							break;							
			case ' ' : a[i]=00;
							break;
			case'\n' : a[i]=27;
							break;																									
		}
	}
}

void number_change_a2(void)
{
	int i=0;
	for(;i<=5;i++)
	{
		switch(a[i]) {
			case 01 : a[i]='A';
							break;
			case 02 : a[i]='B';
							break;
			case 03 : a[i]='C';
							break;
			case 04 : a[i]='D';
							break;							
			case 05 : a[i]='E';
							break;							
			case 06 : a[i]='F';
							break;							
			case 07 : a[i]='G';
							break;
			case 8 : a[i]='H';
							break;							
			case 9 : a[i]='I';
							break;							
			case 10 : a[i]='J';
							break;
			case 11 : a[i]='K';
							break;
			case 12 : a[i]='L';
							break;
			case 13 : a[i]='M';
							break;							
			case 14 : a[i]='N';
							break;							
			case 15 : a[i]='O';
							break;							
			case 16 : a[i]='P';
							break;
			case 17 : a[i]='Q';
							break;							
			case 18 : a[i]='R';
							break;							
			case 19 : a[i]='S';
							break;
			case 20 : a[i]='T';
							break;
			case 21 : a[i]='U';
							break;
			case 22 : a[i]='V';
							break;							
			case 23 : a[i]='W';
							break;							
			case 24 : a[i]='X';
							break;							
			case 25 : a[i]='Y';
							break;
			case 26 : a[i]='Z';
							break;							
			case 00 : a[i]=' ';
							break;																					
		}
	}
}

