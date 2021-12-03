#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1(double x);
double func2(double x);
double method_hord(double x0, double x1, double y, double (*function)(double));
double method_half_div(double x0, double x1, double y, double (*function)(double));
double method_newton(double x, double y, double (*function1)(double), double (*function2)(double));

int main()
{
    int variant;
    do
    {
        printf("Vyberit' metod:\n");
        printf("(1 - Metod hord; 2 - Metod polovynnih; 3 - Metod Newtona)\n");
        scanf("%d", &variant);
    }	while (variant < 1 && variant > 3);

    double x0;
	printf("Vvedit' zminni:\nx0 = ");
	scanf("%lf", &x0);

  	double x1;
	printf("x1 = ");
	scanf("%lf", &x1);

  	double y;
	printf("y = ");
	scanf("%d", &y);

  	double result;
  	switch (variant)
    {
      case 1:
        result = method_hord(x0, x1, y, func1);
        break;
      case 2:
        result = method_half_div(x0, x1, y, func1);
        break;
      case 3:
        result = method_newton(x0, y, func1, func2);
        break;
    }
  	printf("result = %f\n", result);
}

double func1(double x)
{
    return pow(x + 2, 3) - pow(x, 3);
}

double func2(double x)
{
    return 3.1415 / 180 * cos(3.1415 * x / 180) + 1 / (x * x);
}

double method_hord(double x0, double x1, double y, double (*function)(double))
{
    double f0;
    double f;
    int i = 0;

    do
    {
        f = function(x1);
        f0 = function(x0);
        x1 = x1 - f / (f - f0) * (x1 - x0);
        ++i;
  	} while (fabs(f) > y && i < 1000);

    return x1;
}

double method_half_div(double x0, double x1, double y, double (*function)(double))
{
    double x;
  	double f;
    int i = 0;

    do
    {
        x = (x0 + x1) / 2;
        f = function(x);
        if (f > 0)
        {
            x1 = x;
        }
        else
        {
            x0 = x;
        }
        ++i;
  	} while (fabs(f) > y && i <  1000);

    return x;
}

double method_newton(double x, double y, double (*function1)(double), double (*function2)(double))
{
    double f;
    int i = 0;

    do
    {
        f = function1(x);
        x = x - function1(x)/function2(x);
        ++i;
    } while(fabs(f) > y && i < 1000);

    return x;
}
