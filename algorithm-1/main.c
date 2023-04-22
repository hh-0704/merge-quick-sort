#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int* make_rand(int* data) {
	for (int i = 0; i < 10; i++) {
		data[i] = (rand() % 100 + 1);
		printf("   %d", data[i]);
	}
	return data;
}

void Merge(int* data, int left, int mid, int right);

void printArray(int* data, int left, int right) {
	printf("[ ");
	for (int i = left; i <= right; i++) {
		printf("%d ", data[i]);
	}
	printf("]\n");
}

void MergeSort(int* data, int left, int right) {
	if (left < right) {
		int p = (left + right)/2;

		printf("분할: ");
		printArray(data, left, right);

		MergeSort(data, left, p);
		MergeSort(data, p+1, right);
		Merge(data, left, p, right);

		printf("합병: ");
		printArray(data, left, right);
	}
}

void Merge(int* data, int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	int temp[10];
	while (i <= mid && j <= right) {
		if (data[i] <= data[j]) {
			temp[k] = data[i];
			i++;
		}
		else {
			temp[k] = data[j];
			j++;
		}
		k++;
	}
	while (i <= mid) {
		temp[k] = data[i];
		i++;
		k++;
	}
	while (j <= right) {
		temp[k] = data[j];
		j++;
		k++;
	}
	for (int l = left; l <= right; l++) {
		data[l] = temp[l];
	}
}

void QuickSort(int* data, int left, int right) {
	if (left < right) {
		int p = rand() % (right - left + 1) + left;

		printf("피봇의 값: %d\n", data[p]);
		printf("정렬 전: ");
		printArray(data, left, right);
		
		int temp = data[p];
		data[p] = data[left];
		data[left] = temp;
		int pivot = data[left];
		int L = left + 1, R = right;
		while (L <= R) {
			while(data[L] < pivot && L <= right) {
				L++;
			}
			while (data[R] > pivot && R >= left+1) {
				R--;
			}
			if (L <= R) {
				temp = data[L];
				data[L] = data[R];
				data[R] = temp;
				L++;
				R--;
			}
		}

		temp = data[left];
		data[left] = data[R];
		data[R] = temp;

		printf("정렬 후: ");
		printArray(data, left, right);

		QuickSort(data, left, R - 1);
		QuickSort(data, R + 1, right);
	}
}


int main() {
	srand(time(NULL));
	int Mergedata[10];
	int Quickdata[10];
	printf("합병정렬에 들어간 데이터:");
	make_rand(Mergedata);
	printf("\n퀵정렬에 들어간 데이터:");
	make_rand(Quickdata);
	printf("\n");
	MergeSort(Mergedata, 0, 9);
	printf("\n\n");
	QuickSort(Quickdata, 0, 9);
	printf("정렬된 배열: [  ");
	for (int i = 0; i < 10; i++) {
		printf("%d  ", Quickdata[i]);
	}
	printf("]\n");
	return 0;
}