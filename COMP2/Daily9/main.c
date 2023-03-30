#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "priority_queue.c"

int main(int argc, char* argv[])
{
   PRIORITY_QUEUE hQueue = NULL;
   hQueue = priority_queue_init_default();
   if (hQueue == NULL)
   {
       printf("Failed to initialize\n");
       return;
   }
   priority_queue_insert(hQueue, 21, 10);
   priority_queue_insert(hQueue, 35, 5);
   priority_queue_insert(hQueue, 45, 3);
   priority_queue_insert(hQueue, 49, 2);
   priority_queue_insert(hQueue, 24, 6);

       printf("%d\n", priority_queue_front(hQueue, NULL));

       priority_queue_service(hQueue);
       printf("%d\n", priority_queue_front(hQueue, NULL));
       priority_queue_service(hQueue);
       printf("%d\n", priority_queue_front(hQueue, NULL));
       priority_queue_service(hQueue);
       printf("%d\n", priority_queue_front(hQueue, NULL));
       priority_queue_service(hQueue);
       printf("%d\n", priority_queue_front(hQueue, NULL));
       priority_queue_destroy(&hQueue);
   return 0;
}
