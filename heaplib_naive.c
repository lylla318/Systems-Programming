#include <stdlib.h>
#include <stdio.h>
#include "heaplib.h"

/* Useful shorhand: casts a pointer to a (char *) before adding */
#define ADD_BYTES(base_addr, num_bytes) (((char *)(base_addr)) + (num_bytes))

/* You must implement these functions according to the specification given in
 * heaplib.h. You can define any types you like to this file.
 */

typedef struct heap_header_t {
	unsigned int size;
	int bytes_free;
	char *next_free;
} heap_header_t ;

/* This is an example of a helper print function that you may find
 * useful for programming and debugging purposes.  Reminder to always
 * wrap all print statments inside an #ifdef so that the default
 * compile does not include them.  Function calls and printfs will
 * kill your performance and create huge output files, for which we
 * will have ZERO TOLERANCE.
 */
void print_heap(heap_header_t *heap) {
	printf("heap starts at addr %p\n"
		   "total size = %d\n"
		   "bytes free = %d\n"
		   "next free byte begins at addr %p\n",
		   heap, heap->size, heap->bytes_free, heap->next_free);
}


int hl_init(void *heapptr, unsigned int heap_size) {

	heap_header_t *heap = (heap_header_t *)heapptr;
	
	heap->size = heap_size;
	heap->next_free = ADD_BYTES(heap, sizeof(heap_header_t));
	heap->bytes_free = heap_size - sizeof(heap_header_t);
	
    #ifdef PRINT_DEBUG
        print_heap(heap);
    #endif

   	
	return 1; // Success!

}

void *hl_alloc(void *heapptr, unsigned int block_size) {

	heap_header_t *heap = (heap_header_t *)heapptr;
	void *blockptr = heap->next_free;
	
	heap->next_free = heap->next_free + block_size;
	heap->bytes_free = heap->bytes_free - block_size;
	
	return blockptr; // Success!
	
}

void hl_release(void *heapptr, void *blockptr) {

}

void *hl_resize(void *heapptr, void *blockptr, unsigned int new_block_size) {

	return hl_alloc(heapptr, new_block_size);

}

