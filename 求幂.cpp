#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int qiumi(int a,int b,int c)
{  
	int ans = 1; 
	a=a % c; 
	while(b>0){  
		if(b % 2 = = 1)  
			ans= (ans * a) % c; 
		b = b/2;  

		a = (a * a) % c;  

	}	 

	return ans; 

}  

