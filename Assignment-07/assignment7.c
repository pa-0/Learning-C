#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int check_root(float a, float b, float c, float root)
{
	float val;
	val = a*root*root + b*root + c ;
	if (val == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

float *roots_of_eq(float a, float b, float c)
{
	static float roots[2];
	roots[0]= (-b + sqrt((b*b)-(4*a*c)))/(2*a);
	roots[1]= (-b - sqrt((b*b)-(4*a*c)))/(2*a);
	return roots;
}


void main()
{
	int f1,f2;
	float a,b,c;
	float *roots;

	f1=f2=1;
	printf("Enter the value of A : ");
	scanf("%f",&a);
	printf("Enter the value of B : ");
	scanf("%f",&b);
	printf("Enter the value of C : ");
	scanf("%f",&c);

	roots=roots_of_eq(a,b,c);
	printf("The solution using the '+' operator is: %f\n", roots[0]);
	f1=check_root(a,b,c,roots[0]);
	if(f1==1)
	{
		printf("However, You might wanna check that !");
	}
	printf("The solution using the '-' operator is: %f\n", roots[1]);

	f2=check_root(a,b,c,roots[1]);
	if(f2==1)
	{
		printf("However, You might wanna check that !");
	}

}
