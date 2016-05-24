#define MAXLENGTH 1000  
#include <stdio.h> 
#include <string.h> 
void compute(char *a, char *b, char *c);  
int main(void)  
{   

char a[MAXLENGTH], b[MAXLENGTH], c[MAXLENGTH * 2];  

  

puts("Input multiplier :");  

gets(a);   

puts("Input multiplicand :");  

gets(b);  

  

compute(a, b, c);  

  

puts("Answer :");  

puts(c);  

getchar(); 
return 0; 

}  

  













void compute(char *a, char *b, char *c)  
{   
	int i, j, m, n;  
	long sum, carry;  
	m = strlen(a) - 1;  
	n = strlen(b) - 1;  
	for (i = m; i>= 0; i--)  
		a[i] -= '0';   
	for (i = n; i>= 0; i--)  
		b[i] -= '0';  
	c[m + n + 2] = '\0';  
	carry = 0;   
	for (i = m + n; i>= 0; i--) /* i为坐标和*/  
	{  
		sum = carry;  
		if ((j = i - m) < 0)  
			j = 0;   
		for ( ; j<=i&& j<=n; j++) /* j 为纵坐标*/  
			sum += a[i-j] * b[j]; /* 累计一组数的和*/  
		c[i + 1] = sum % 10 + '0'; /* 算出保留的数字*/  
		carry = sum / 10; /* 算出进位*/  
	}  
	
	if ((c[0] = carry+'0') == '0') /* if no carry, */  
		c[0] = '\040'; /* c[0] equals to space */  
}   

