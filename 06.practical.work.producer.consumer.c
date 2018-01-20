// Example of producer-consumer

#include<unistd.h>
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

int main(){
	item *i1 = (item *) malloc(sizeof(item));
	i1->type = '1';
	i1->amount = 50;
	i1->unit = '1';
	item *i2 = (item *) malloc(sizeof(item));
	i2->type = '0';
	i2->amount = 2;
	i2->unit = '0';
	produce(i1);
	printf("first: %d", first);
	printf("\nlast: %d", last);
	produce(i2);
	printf("\nfirst: %d", first);
	printf("\nlast: %d", last);
	consume();
	printf("\nfirst: %d", first);
	printf("\nlast: %d\n", last);
}
