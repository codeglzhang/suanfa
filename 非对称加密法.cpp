#include <stdio.h>
#include<string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

 
char jiami(char a,long e,long r);	//	加密； 
char jiemi(char a,long d,long r);//解密 ； 
int zhishu_creat(void);//随机生成质数； 
long creat_r(int q,int p); 
long gongyue(int p,int q);//随机生成公钥；			
int ksm(int a,long b,long c); 
long siyue(long e,int p,int q);

int main(void)
{	
	int i,zhishu_p,zhishu_q;
	long d,r,e;
	char ch;
	FILE *fp,*fq;
	
	fp=fopen("E:/加密.txt","a+");
	fq=fopen("E:/解密.txt","a+");
	printf("1.加密。\n2.解密\n");
	scanf("%d",&i);
	
	if(i==1){
		zhishu_p=zhishu_creat();
		zhishu_q=zhishu_creat();
		r=creat_r(zhishu_p,zhishu_q);
		e=gongyue(zhishu_p,zhishu_q);
		printf("公钥为：（%ld，%ld）",r,e);
		d=siyue(e,zhishu_p,zhishu_q);
		printf("私钥为：（%ld,%ld）",r,d);
		while(!feof(fp))
		{
			ch=fgetc(fp);
			ch=jiami(ch,e,r);
			fputc(ch,fq);
			
		}
		fclose(fq);
		fclose(fp);
	}
	else if(i==2){
		printf("请输入私钥解密（r,d）：");
		scanf("%ld%ld",&r,&d);
		while(!feof(fq)){
			ch=fgetc(fq);
			ch=jiemi(ch,d,r);
			fputc(ch,fp);
		}
	}	
	else{
		printf("您的输入有误！");
	}
	fclose(fq);
	fclose(fp);
	return 0;
	}


char jiemi(char a,long d,long r)
{
	char b;
	b=ksm(a,d,r);
	return b;
}
int zhishu_creat(void)
{
	int i,j,k;
	srand((unsigned) time(NULL));
	i=(rand()+100)%10000; 
	while(1){
		k=(int)sqrt(i);
   		for(j=2;j<=k;j++)
      		if(i%j==0)
         		break;
   		if(j>k)
       		break;
   		else
       		i=(rand()+100)%10000;
	}
	return i;
}

long creat_r(int q,int p)
{
	long r;
	r=p*q;
	return r;
}

long gongyue(int p,int q){
	int max,i,j;
	long e;
	if(p>q)
		max=p;
	else
		max=q;
	e=rand()%10000+max;
	while(1){
		i=(int)sqrt(e);
		for(j=2;j<=i;j++)
			if(e%j==0)
				break;
		if(j>i)
			break;
		else
			e=rand()%10000+max;						
	}

	return e;
}
int ksm(int a,long b,long c)
{  
	int ans=1; 
	a=a%c; 
	while(b>0){  
		if(b%2==1)  
			ans= (ans*a)%c; 
		b=b/2;  

		a = (a*a) % c;  

	}	 
	return ans; 
} 
char jiami(char a,long e,long r)
{ 
	char b;
	b=ksm(a,e,r);
	return b;
}
long siyue(long e,int p,int q){
	int d=0;
	long i,j;
	while(1){
		i=d*e;
		j=(p-1)*(q-1);
		if(i%j==1)
			break;
		d++;	
	}
	return d;
}

