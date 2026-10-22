/* CS100 Fall 2026 - HW2 Problem 3: Polynomial evaluation
 *
 * Evaluate P(x) at m given points; print each value rounded to 3 decimals.
 * An array is enough for the coefficients; do not use heap memory and do
 * not use <math.h> (your program is not linked against the math library).
 * Do not rename this file.
 */
#include <stdio.h>

int main(void)
{
    /* TODO: your code here */
     int n;
    double coeff[31];

    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        scanf("%lf", &coeff[i]);
    }

    int m;
    scanf("%d", &m);

    for (int k = 0; k < m; k++)
    {
        double x;
        scanf("%lf", &x);

        double res = coeff[n];
        for (int i = n - 1; i >= 0; i--)
        {
            res = res * x + coeff[i];
        }

        printf("%.3f\n", res);
    }

    return 0;
}
