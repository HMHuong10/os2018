#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 10

typedef struct {
	char type;
	int amount;
	char unit;
} item;

item buffer[BUFFER_SIZE];
int first=0;
int last=0;

void produce(item *i){
	while ((first+1) % BUFFER_SIZE == last){
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}

item *consume(){
	item *i = malloc(sizeof(item));
	while(first == last){
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
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
	pthread_t tid;
	pthread_create(&tid, NULL, thread_producer, NULL);
	pthread_join(tid, NULL);
	pthread_t tid1;
	pthread_create(&tid1, NULL, thread_consumer, NULL);
	pthread_join(tid1, NULL);
	return 0;
}

