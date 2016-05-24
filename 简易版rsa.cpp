#include <stdio.h>
#include<string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000
 
long jiami(long a,int e,int r);	//	加密； 
long jiemi(long a,int d,int r);//解密 ； 
int zhishu_creat(void);//随机生成质数； 
int creat_r(int q,int p); 
int gongyue(int p,int q);//随机生成公钥；			
int ksm(int a,int b,int c); 
int siyue(int e,int p,int q);

int main(void)
{	
	int d,i,r,e,zhishu_p,zhishu_q;
	long C,P;
	
	printf("1.加密。\n2.解密\n");
	scanf("%d",&i);
	
	if(i==1){
		while(1){
			zhishu_p=zhishu_creat();
			zhishu_q=zhishu_creat();
			r=creat_r(zhishu_p,zhishu_q); 
			e=gongyue(zhishu_p,zhishu_q); 
			printf("公钥为：（%d，%d）",r,e);
			d=siyue(e,zhishu_p,zhishu_q);
			printf("私钥为：（%d,%d）",r,d);
			printf("请输入需加密的明文P=");
			scanf("%ld",&P);
			C=jiami(P,e,r);
			printf("加密后的密文为C=%ld\n",C);
			if(P!=C)
				break;
			printf("明文与密文相同请重新输入质数");
		}	
	}
	else if(i==2){
		printf("请输入私钥解密（r,d）：");
		scanf("%d%d",&r,&d);
		printf("请输入要解密的密文：C=");
		scanf("%ld",&C);
			P=jiemi(C,d,r);
		printf("P=%ld",P);
	
	}	
	else{
		printf("您的输入有误！");
	}
	
	return 0;
	}


long jiemi(long a,int d,int r)
{
	long b;
	b=ksm(a,d,r);
	return b;
}
int zhishu_creat(void)
{
	int m,i,k;
	while(1){
    	printf("请输入一个素数：");
		scanf("%d",&m);
		k=sqrt(m);
		for(i=2;i<=k;i++)
       		if(m%i==0)
          		break;
    	if(i>k)
        	return m;
    	else
        	printf("%d 不是素数。请重新输入！\n",m);
	}
}

int creat_r(int q,int p)
{
	int r;
	r=p*q;
	return r;
}

int gongyue(int p,int q){
	int e,max,i,j;
	if(p>q)
		max=p;
	else
		max=q;
	e=max+5;	
	while(1){
		i=(int)sqrt(e);
		for(j=2;j<=i;j++)
			if(e%j==0)
				break;
		if(j>i)
			break;
		else
			e++;						
	}
	return e;
}
int ksm(int a,int b,int c)
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
long jiami(long a,int e,int r)
{ 
	long b;
	b=ksm(a,e,r);
	return b;
}
int siyue(int e,int p,int q){
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

