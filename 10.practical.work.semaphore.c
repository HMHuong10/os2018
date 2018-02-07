#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>

#define BUFFER_SIZE 10

typedef struct {
	char type;
	int amount;
	char unit;
} item;

item buffer[BUFFER_SIZE];
int first=0;
int last=0;

sem_t sem;

void produce(item *i){
	while ((first+1) % BUFFER_SIZE == last){
	}

	sem_wait(&sem);
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
	sem_post(&sem);
}

item *consume(){
	item *i = malloc(sizeof(item));
	while(first == last){
	}

	sem_wait(&sem);
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	sem_post(&sem);

	return i;
}

void *thread_producer(void *param){
	item *i1 = (item *) malloc(sizeof(item));
	i1->type = '1';
	i1->amount = 50;
	i1->unit = '1';
	item *i2 = (item *) malloc(sizeof(item));
	i2->type = '0';
	i2->amount = 2;
	i2->unit = '0';
	item *i3 = (item *) malloc(sizeof(item));
	i3->type = '1';
	i3->amount = 100;
	i3->unit = '1';
	produce(i1);
	printf("first: %d", first);
	printf("\nlast: %d", last);
	produce(i2);
	printf("\nfirst: %d", first);
	printf("\nlast: %d", last);
	produce(i3);
	printf("\nfirst: %d", first);
	printf("\nlast: %d", last);
}

void *thread_consumer(void *param){
	consume();
	printf("\nfirst: %d", first);
	printf("\nlast: %d", last);
	consume();
	printf("\nfirst: %d", first);
	printf("\nlast: %d\n", last);
}

int main(){
	pthread_t tid, tid1;

	sem_init(&sem, 0, 1);
	pthread_create(&tid, NULL, thread_producer, NULL);
	pthread_create(&tid1, NULL, thread_consumer, NULL);
	pthread_join(tid1, NULL);
	sem_destroy(&sem);

	return 0;
}

