#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int car_length; 
   char car_bank[10]; 
}Car;

typedef struct node Node;

struct node{
   Car* car;
   Node *next;
};


typedef struct {
   Node *head;
   Node *tail;
} Queue;

Queue *left_bank_cars = NULL;
Queue *right_bank_cars = NULL;

int is_empty(Queue *queue);
void insert_item(Queue *queue, Car *car);
Car* delete_item(Queue *queue);

int main(){
    int l, m, n, c, i, j;
    char ferry_bank[5];
    char car_bank[10];
    int car_length;
    int num_left_bank_cars = 0, num_right_bank_cars = 0, num_cars_ferried = 0, num_ferries = 0;
    char *token;
    char line[20];
    

    left_bank_cars = (Queue*) malloc(sizeof(Queue));
    left_bank_cars->head = NULL;
    left_bank_cars->tail = NULL;
    right_bank_cars = (Queue*) malloc(sizeof(Queue));
    right_bank_cars->head = NULL;
    right_bank_cars->tail = NULL;
    strcpy(ferry_bank, "left");

    scanf("%d", &c);
    
 
    for (i = 1; i <= c; i++) {
       
        scanf("%d %d", &l, &m);
  
        for (j = 1; j <= m; j++) {
        
            fgets(line, sizeof(line), stdin);
            token = strtok(line, " ");
            if (token != NULL)
                car_length = atoi(token);
            token = strtok(NULL, " ");
            if (token != NULL)
                strcpy(car_bank, token);
            Car *car = (Car*) malloc(sizeof(Car));
            car->car_length = car_length;
            strncpy(car->car_bank, car_bank, strlen(car_bank));
            if (strcmp(car_bank, "left") == 0) {
                
                insert_item(left_bank_cars, car);
                num_left_bank_cars++;
            } else if (strcmp(car_bank, "right") == 0) {
                insert_item(right_bank_cars, car);
                num_right_bank_cars++;
            }
            free(car);
        }
        
        while (num_cars_ferried <= m) {
            
            if (strcmp(ferry_bank, "left") == 0) {
                
                n = l * 100; 
                while (num_left_bank_cars > 0) {
                    if (!is_empty(left_bank_cars)) {

                        if (left_bank_cars->head->car->car_length <= n) {
                            printf("Decking a car from left...\n");
                            Car *car = delete_item(left_bank_cars);
                            if (car != NULL) {
                                n -= car->car_length;
                                num_left_bank_cars--;
                                num_cars_ferried++;
                                free(car);
                            }
                        }
                    } else
                        break;
                }
                num_ferries++;
                strcpy(ferry_bank, "right");
            } else if (strcmp(ferry_bank, "right") == 0) {
          
                n = l * 100; 
                while (num_right_bank_cars > 0) {
                    if (!is_empty(right_bank_cars)) {

                        if (right_bank_cars->head->car->car_length <= n) {
                            Car *car = delete_item(right_bank_cars);
                            if (car != NULL) {
                                n -= car->car_length;
                                num_right_bank_cars--;
                                num_cars_ferried++;
                                free(car);
                            }
                        }
                    } else
                        break;
                }

                num_ferries++;
                strcpy(ferry_bank, "left");
            }
            printf("Number of cars ferried:%d\n", num_cars_ferried);
            printf("Number of ferries:%d\n", num_ferries);
        }
    }
    return 0;

}

int is_empty(Queue *queue) {
   return (queue->head == NULL ? 1 : 0);
}

void insert_item(Queue *queue, Car *car) {
   Node* node = (Node*) malloc(sizeof(Node));
   node->car = car;
   node->next = NULL;
   printf("empty:%d\n", is_empty(queue));
   if (!is_empty(queue)) {

       queue->tail = node;
       printf("item inserted in tail.\n");
   } else {
       queue->tail = node;
       queue->head = node;
       printf("item inserted as head node:%d\n", queue->head->car->car_length);
   }
}

Car* delete_item(Queue *queue) {
   if (is_empty(queue))
       return NULL;
   Car* deleted_item = queue->head->car;

   queue->head = queue->head->next;

   return deleted_item;
}