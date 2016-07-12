/*Sean Kee*/
/*Dynamic Allocation Sorting System v1.0.0*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void *sortAsc(const int *output) {
	int i;
	int j;
	int *ptr = output;
	for (i = 0; i < sizeof(output)/4; i++) {
		for (j = 0; j < sizeof(output)/4; j++) {
			if (*(output + j) <= *(output + i))
				*ptr = *(output + j);
		}
		ptr++;
	}
}

int *sortDes(int *output) {
}

int main() {
	int *original; /*Creates original pointer*/
	original = (int *) malloc(10 * sizeof(int)); /*Assigns Dynamic memory,10 ints of 4 bytes each*/

	int size; /*User input for array size*/
	printf("Input the array size\n#: ");
	scanf("%d", &size);

	original = realloc(original, size * sizeof(int)); /*Reallocates enough space based on the size inputted by the user*/
	
	int *ascending = (int *) malloc(size * sizeof(int));
	int *descending = (int *) malloc(size * sizeof(int));

	int i; /*counter*/

	srand(time(NULL));

	for(i = 0; i < size; i++) { /*Fills the original with random numbers between 1 and 100 */
		*(original + i) = (rand() % 100);
		*(ascending + i) = *(original + i);
		*(descending + i) = *(original + i);
	}
	
	sortAsc(ascending);
//	descending = sortDes(descending);

	printf("Original Numbers\n");
	for(i = 0; i < size; i++) {
		printf("%d\n", *(original + i));
	}
	printf("****\n");
	printf("Numbers in Ascending order");
	for(i = 0; i < size; i++) {
		printf("%d\n", *(ascending + i));
	}

	free(original); /*Frees dynamic array 'original*/
	free(ascending);
	free(descending);

	return 0;
}
