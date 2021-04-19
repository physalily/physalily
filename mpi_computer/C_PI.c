// C_PI.c:

#include <math.h>
#include <stdio.h>

int main()
{
	long num_rects = 300000;
	long i;
	double x, height, width, area;
	double sum;
	width = 1.0 / (double)num_rects; // width of segment.
	sum = 0;
	for (i = 0; i < num_rects; i++)
	{
		x = (i + 0.5) * width; // x; distance to segment center in No. i.
		height = 4 / (1.0 + x * x);
		sum += height; // sum of segment height.
	}
	// segment area (calculate Pi)
	area = width * sum;

	printf("\n");
	printf(" Calculated Pi = %.16f\n", area);
	printf("          M_Pi = %.16f\n", M_PI);
	printf("Relative error = %.16f\n", fabs(area - M_PI);
	
	return 0;
}

