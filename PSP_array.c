#include<stdio.h>

void ShellSort(int*, int);
void displayVector(int*, int);

int main(void)
{
	int array[] = { 12, -2, 4, 5, 6, 4, 2, 554, 2321, 1, -5, 3, 997, 2, 4, 4, 52, 23, 4, 1, 2, 1, 3, 33, 9999};
	int len = sizeof(array) / sizeof(int);

	printf("Arreglo desordenado:\n");
	displayVector(array, len);

	ShellSort(array, len);

	printf("Arreglo Ordenado:\n");
	displayVector(array, len);
	
}

void displayVector(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			printf("[%d, ", arr[i]);
			continue;
		}

		if (i == size - 1)
		{
			printf("%d]\n",arr[i]);
			break;
		}

		printf("%d, ", arr[i]);
	}

	printf("\n");
}

void swap(int *arr, int n, int p)
{
	int temp = arr[n];
	arr[n] = arr[p];
	arr[p] = temp;
}

void ShellSort(int *arr, int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2)
		for (int i = gap; i < size; i++)
			for (int j = i - gap; j >= 0 && arr[j] >= arr[j + gap]; j -= gap)
				swap(arr, j, j + gap);
}
