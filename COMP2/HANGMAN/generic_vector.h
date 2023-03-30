#include "status.h"
#include "generic.h"

typedef void* GENERIC_VECTOR;

Status generic_vector_push_back(GENERIC_VECTOR hVector, Item value);
int generic_vector_get_size(GENERIC_VECTOR hVector);
int generic_vector_get_capacity(GENERIC_VECTOR hVector);
Item generic_vector_at(GENERIC_VECTOR hVector, int index);
Status generic_vector_pop_back(GENERIC_VECTOR hVector);
Boolean generic_vector_empty(GENERIC_VECTOR hVector);
void generic_vector_destroy(GENERIC_VECTOR* phVector);
GENERIC_VECTOR generic_vector_init_default(Status(*item_assignment)(Item* pLeft, Item right),void (*item_destroy)(Item* phItem));