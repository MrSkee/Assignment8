/*Sean Kee*/
/*Dynamic Allocation Sorting System v1.0.0*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortAsc(int *output, int size) {
	int i; /*Number of Passes*/
	int j;
	int temp;
	int *ptr = output;
	for (i = 0; i < size - 1; i++) { 
		for (j = 0; j < size - 1; j++) {
			if (*(ptr + j) > *(ptr + j + 1)) { /*if the current number being checked is greater than the next one, swap places)*/
				temp = *(ptr + j);
				*(ptr + j) = *(ptr + j + 1);
				*(ptr + j + 1) = temp;
			}
		}
	}
}

int *sortDes(int *output, int size) {
	int i; /*Number of Passes*/
	int j;
	int temp;
	int *ptr = output;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1; j++) {
			if (*(ptr + j) < *(ptr + j + 1)) { /*Same thing as ascending, just backwards*/
			temp = *(ptr + j);
			*(ptr + j) = *(ptr + j + 1);
			*(ptr + j + 1) = temp;
			}
		}
	}
}


int main() {
	int *original; /*Creates original pointer*/
	original = (int *) malloc(10 * sizeof(int)); /*Assigns Dynamic memory,10 ints of 4 bytes each*/

	int size; /*User input for array size*/
	printf("Input the array size\n#: ");
	scanf("%d", &size);
		
	original = (int *) realloc(original, size * sizeof(int)); /*Reallocates enough space based on the size inputted by the user*/

	int *ascending = (int *) malloc(size * sizeof(int));
	int *descending = (int *) malloc(size * sizeof(int));

	int i; /*counter*/

	srand(time(NULL));
	
	for(i = 0; i < size; i++) { /*Fills the original with random numbers between 1 and 100 */
		*(original + i) = (rand() % 100);
		*(ascending + i) = *(original + i);
		*(descending + i) = *(original + i);
	}
	
	sortAsc(ascending, size);
	sortDes(descending, size);

	printf("Original Numbers\n");
	for (i = 0; i < size; i++) {
		printf("%d\n", *(original + i));
	}
	printf("****\n");
	printf("Numbers in Ascending order\n");
	for (i = 0; i < size; i++) {
		printf("%d\n", *(ascending + i));
	}

	printf("****\n");
	printf("Numbers in Descending order\n");
	for (i = 0; i < size; i++) {
		printf("%d\n", *(descending + i));
	}

	free(original); /*Frees dynamic memory*/
	free(ascending);
	free(descending);

	return 0;
}
