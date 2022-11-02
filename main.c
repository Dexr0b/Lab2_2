#include <stdio.h>
#include <stdlib.h>
#include <math.h>



double l_re(double a, double b, unsigned int intervals);
double r_re(double a, double b,  unsigned int intervals);
double trapecia(double a, double b,  unsigned int intervals);
double Simps (double a, double b, unsigned int intervals);
double integrand_expression( double x );
double a=0, b=0;
double measurement_error=0, I1=0, I2=0;
int intervals, var, i;
double integral_s=0;

int main()
{
  while (1)
  {
    printf("\n\tThe left boundary a = %.2lf",a );
    scanf("%lf", &a);
    printf("\n\tThe right boundary b = %.2lf",b );
    scanf("%lf", &b);
    do
    {
      printf("\tEnter the number of partition intervals (N>0)\nN=");
      scanf("%u", &intervals);
    }
    while (intervals <= 0);
    do
    {
      printf("\nChoose the method of calculating:\n");
      printf("\t1. By Left Rectangles:\n");
      printf("\t2. By Right Rectangles:\n");
      printf("\t3. By Trapecia:\n");
      printf("\t4. By Simps(parabola method):\n");
      scanf("%u", &var);
    if (var != 1 && var != 2 && var != 3 && var != 4)
        printf("\nYou are mistaken! Please enter number from 1-4\n");
    }
     while (var != 1 && var != 2 && var != 3 && var != 4);
    system("cls");
    switch (var)
    {
    case 1:
    {
         integral_s = l_re(a, b, intervals);
      printf("\n\n\t*Left Rectangles method*\n");
      printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d \n\ti1 = %.8lf",a, b, integral_s, intervals);
    }break;
    case 2:
    {
      integral_s = r_re(a, b, intervals);
      printf("\n\n\t======*Right Rectangles method*======\n");
      printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d \n\ti1 = %.8lf", a, b , integral_s, intervals);
    }
    break;
    case 3:
    {
      integral_s = trapecia(a, b, intervals);
      printf("\n\n\t======*trapecia method *======\n");
      printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d \n\ti1 = %.8lf", a, b, integral_s, intervals);
    }
    break;
    case 4:
    {
      integral_s = Simps(a, b, intervals);
      printf("\n\n\t======*simps's method *======\n");
      printf("\n\ta = %.2lf \n\tb = %.2lf \n\tIntegral = %.8lf \n\tN = %d \n\ti1 = %.8lf", a, b, integral_s, intervals);
    }
    break;
    }
  }
  return 0;
}
double l_re(double a, double b, unsigned int intervals)
{
  double integral_s = 0, x = 0, h;
  unsigned int i;
  h = (b - a) / intervals;
  x = a;
  for (i = 0; i <= (intervals - 1); i++)
  {
    integral_s += integrand_expression(x);
    x += h;
  }
  return integral_s * h;
}
double r_re(double a, double b, unsigned int intervals)
{
  double integral_s = 0, x = 0, h;
  unsigned int i;
  h = (b - a) / intervals;
  x = a + h;
  for (i = 0; i <= intervals; i++)
  {
    integral_s += integrand_expression(x);
    x += h;
  }
  return integral_s * h;
}
double trapecia(double a, double b, unsigned int intervals)
{
  double integral_s = 0, x = 0, h;
  unsigned int i;
  h = (b - a) / intervals;
  x = a + h;
  for (i = 0; i <= (intervals - 1); i++)
  {
    integral_s += (integrand_expression(x) + integrand_expression(x + h)) / 2;
    x += h;
  }
  return integral_s * h;
}
double Simps(double a, double b, unsigned int intervals)
{
	double integral_s = 0, sum1 = 0, sum2 = 0, h = 0;
	h = (b - a) / intervals;
	for (int i = 1; i <= (intervals - 1); i++)
	{
		if (i%2!=0)
			sum1 += integrand_expression(a + h * i);
		else
			sum2 += integrand_expression(a+ h * i);
	}
	return (integrand_expression(a) + integrand_expression(b) + 4 * sum1 + 2 * sum2) * h / 3;
}
double integrand_expression(double x)
{
	return pow(x,4)+ 3*x;
}
