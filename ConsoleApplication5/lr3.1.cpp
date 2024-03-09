#include <stdio.h>
#include <conio.h>
#include <math.h>

void scanArray(float*, int);

void printArray(float*, int);

float* findMin(float*, int);

float* findMax(float*, int);

float mid1(float*, float*);

void main() {
	int n;

	printf("Enter array size:\n");

	scanf("%i", &n);

	float a[100];

	float *p = a;

	scanArray(p, n);

	printf("Min = %.2f \n", *findMin(p, n));

	printf("Max = %.2f \n", *findMax(p, n));

	printf("mid = %.3f \n", mid1(findMin(p, n), findMax(p, n)));

	printArray(p, n);

	getch();
}

float* findMax(float *a, int n) {
	float* r = a;

	for (int i = 1; i < n; i++) {
		if (a[i] > *r) {
			r = a + i;
		}
	}
	return r;
}

float* findMin(float *a, int n) {
	float* r = a;
	for (int i = 1; i < n; i++) {
		if (a[i] < *r) {
			r = a + i;
		}
	}
	return r;
}

float mid1(float *a, float *b) {
	float c = 0;
	int count = 0;
	if (a < b) {
		while ((a + 1) < b) {
			c = c + *(a + 1);
			a++;
			count++;
		}
	}
	else if (a > b) {
		while ((b + 1) < a) {
			c = c + *(b + 1);
			b++;
			count++;
		}
	}
	if (count > 0) {
		return c / count;
	}
	else {
		return 0;
	}
}

void scanArray(float *a, int n) {
	printf("Enter %i array items\n", n);
	for (int i = 0; i < n; i++)
		scanf("%f", a + i);
}

void printArray(float *start, int size) {
	for (int i = 0; i < size; i++) {
		printf("%.0f ", *start);
		start += 1;
	}
	printf("\n");
}