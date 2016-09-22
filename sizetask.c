#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "heaplib.h"
#include "sizetask.h"

#define ITERS          64
#define REQ_SIZE       64
#define SEED 50

/* This is just an example task. Replace it with your code.
 * 
 * Provide a short description of your task here:
 For this task, we have a lot of calls to alloc, resize and free.
 We want to see how much our heap we are actualy ablet to use.
 So calling re-size and release will allow us to see how much
 internal fragmentation there is. 

 We fixed a seed to a random number geneator (so that our version of 
 pass_sizetask will run the same random numers on each students' heaplib.c).
 The randomness component demonstrates how well our heap can perform
 utilization-wise in circumstances where calls to alloc are not conventiently 
 placed right after one another.
 * 
 *
 */


bool pass_sizetask(unsigned int heap_size) {
	void *heap, *ptrs[ITERS];
	bool success = true;
    int i;
	
	heap = malloc(heap_size); // allocate the heap
	success = hl_init(heap, heap_size);
	srand(SEED); // Fix seed to random number generator 

	for (i = 0; i < (ITERS/2) && success; i++) {
		int BLOCK_SIZE = (rand() % (heap_size-50)) + 8;
		ptrs[i] = hl_alloc(heap, BLOCK_SIZE);
		if ((i % 5 == 0) && (i != 5) && (i % 3 != 0)) {
			hl_release(heap, ptrs[i-5]);
		}

		if ((i % 3 == 0) && (i != 3) && (i % 5 != 0)) {
			hl_resize(heap, ptrs[i-3], (BLOCK_SIZE + 8));
		}
		success = (ptrs[i] != NULL);
	}

	for (i = (ITERS/2); i < ITERS/2 && success; i++) {
		int BLOCK_SIZE = (rand() % (heap_size-50)) + 6;
		ptrs[i] = hl_alloc(heap, BLOCK_SIZE);
		if ((i % 5 == 0) && (i != 5) && (i % 3 != 0)) {
			hl_release(heap, ptrs[i-5]);
		}

		if ((i % 3 == 0) && (i != 3) && (i % 5 != 0)) {
			hl_resize(heap, ptrs[i-3], (BLOCK_SIZE-6));
		}
		success = (ptrs[i] != NULL);
	}

	free(heap); // free the heap
	return success;	
}

