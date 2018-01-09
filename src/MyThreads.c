/*
 * MyThreads.c
 *
 *  Created on: Jan 8, 2018
 *      Author: philippe
 *
 *  Exercise: 	- Write a program with 20 threads, which all wait for you to enter a value.
 *  		Each thread will add a random number, wait for this total time (between 0 and 100 ms)
 *  		and printf it together with its thread_id.
 *
 *  Use:	- pthread_create(pthread_t *thread, const pthread_attr_t *attr,
 *  			void * (*start_routine) (void *), void *arg);
 */

//default includes
#include <stdio.h>
#include <stdlib.h>

//specific includes
#include <pthread.h>

#define NO_THREADS 5

void * random_wait(void * id) {
	printf("in thread %d: start.\n", (int) *id);
	pthread_exit(NULL);
}

int main() {
	//
	pthread_t wait_threads[NO_THREADS];

	for(int i = 0; i<NO_THREADS; ++i){
		printf("start thread %d\n", i);
		pthread_create(wait_threads[i], NULL,
	}
	return 0;
}

