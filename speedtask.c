#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "heaplib.h"
#include "speedtask.h"

// task specific, feel free to remove these
#define ITERS       4096
#define ORIGINAL_SIZE   48
#define LARGER_SIZE   88
#define SMALLER_SIZE 8

/* NOTICE: this file determines the size of the heap that is created
 * and passed to the standalone_speedtask function via the function get_heap_size
 * whether you choose to have this as a #define or a local variable is
 * totally up to you
 *
 * Since you don't know much about the overhead of the library code
 * written by others, you should be a bit generous with the heap size
 * if your task is making many individual calls to hl_alloc
 */
#define HEAP_SIZE (2 * ITERS * (ORIGINAL_SIZE + LARGER_SIZE))

// you might not want to #define this if the actual number of 
// operations could vary and you want to keep track as the program runs. 
unsigned int num_ops = 1 + (3 * ITERS);


// however you store/calculate it, you must support this function call
unsigned int get_heap_size() {
	return HEAP_SIZE;
}

// however you store/calculate it, you must support this function call
unsigned int get_num_ops() {
  unsigned int num_ops = 1;
  int i;


  for (i = 0; i < ITERS; i++) {
    num_ops += 1;
  }
  
  // Re-allocate blocks so that they are bigger.
  for (i = 0; (i < ITERS/2) ; i++) {
    num_ops += 1;
  }


  // Release all the blocks.
  for (i = 1; i < (ITERS/2); i+=2) {
    num_ops += 1;
  }

  // Re-allocate blocks so that they are smaller.
  for (i = (ITERS/2) ; i < ITERS ; i++) {
    num_ops += 1;
  }

  // Release all the blocks.
  for (i = (ITERS/2); i < ITERS; i+=2) {
    num_ops += 1;
  }
  return num_ops;
}


/* This is just an example task. Replace it with your code.
 * NOTE: your code will test others' library code. If YOUR test segfaults,
 * that will be bad for YOU. So program defensively.
 * 
 * Provide a short description of your task here:
 * 
 */


void standalone_speedtask(void *heap) {
  int num_ops = 0;
  int i;
  void *ptrs[ITERS];
  
  if (!hl_init(heap, HEAP_SIZE))
	  return;

  for (i = 0; i < ITERS; i++) {
    num_ops += 1;
	  ptrs[i] = hl_alloc(heap, ORIGINAL_SIZE);
  }
  
  // Re-allocate blocks so that they are bigger.
  for (i = 0; (i < ITERS/2) ; i++) {
    num_ops += 1;
	  if (ptrs[i]) ptrs[i] = hl_resize(heap, ptrs[i], LARGER_SIZE);
  }


  // Release all the blocks.
  for (i = 1; i < (ITERS/2); i+=2) {
    if (ptrs[i])
      num_ops += 1;
      hl_release(heap, ptrs[i]);
  }

  // Re-allocate blocks so that they are smaller.
  for (i = (ITERS/2) ; i < ITERS ; i++) {
    num_ops += 1;
    if (ptrs[i]) ptrs[i] = hl_resize(heap, ptrs[i], SMALLER_SIZE);
  }

  // Release all the blocks.
  for (i = (ITERS/2); i < ITERS; i+=2) {
    num_ops += 1;
	  if (ptrs[i])
		  hl_release(heap, ptrs[i]);
  }
}
