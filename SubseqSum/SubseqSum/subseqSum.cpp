#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
#define COUNT 1e7
int getSubseqSum1(int A[], int n);
int getSubseqSum2(int A[], int n);
int main()
{
	clock_t start1, end1, start2, end2;
	int sum1, sum2;
	int A[] = { 1, 2, 3, -2, 4, 5, 6, 7, 8, 9, -1, -4 };
	start1 = clock();
	for (int i = 0; i < COUNT; i++)
	{
		sum1 = getSubseqSum1(A, 12);
	}
	end1 = clock();
	start2 = clock();
	for (int i = 0; i < COUNT; i++)
	{
		sum2 = getSubseqSum2(A, 12);
	}
	end2 = clock();
	cout << "max sum1:" << sum1 << " time:" << setiosflags(ios::fixed) << (double)(end1 - start1) / CLK_TCK << endl;
	cout << "max sum2:" << sum2 << " time:" << setiosflags(ios::fixed) << (double)(end2 - start2) / CLK_TCK<< endl;
	return 0;
}

int getSubseqSum1(int A[], int n)
{
	int i, j, k;
	int thisSum = 0;
	int maxSum = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			for (k = i; k < j; k++)
				thisSum += A[k];
			if (thisSum > maxSum)
				maxSum = thisSum;
			thisSum = 0;
		}
	}
	return maxSum;
}
int getSubseqSum2(int A[], int n)
{
	int i, j, k;
	int thisSum = 0;
	int maxSum = 0;
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			thisSum += A[j];
			if (thisSum > maxSum)
				maxSum = thisSum;
		}
		thisSum = 0;
	}
	return maxSum;
}