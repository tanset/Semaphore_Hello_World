/*
 * =====================================================================================
 *
 *       Filename:  semaphore_hello_world.c
 *
 *    Description: This file demonstrates the use of POSIX threads - A hello world program 
 *
 *        Version:  1.0
 *        Created:  11/03/2020 07:50:04 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ABHISHEK SAGAR
 *   Organization:  Juniper Networks
 *    Modified by:  Howie Chang
 *    Modified on:  2025/06/04
 * 	
 *
 * =====================================================================================
 */

/*
 * compile using :
 * gcc -g -c semaphore_hello_world.c -o semaphore_hello_world.o
 * gcc -g semaphore_hello_world.o -o semaphore_hello_world.exe -lpthread
 * Run : ./semaphore_hello_world.exe
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> /* For working with POSIX threads*/
#include <unistd.h>  /* For pause() and sleep() */
#include <errno.h>	 /* For using Global variable errno */
#include <semaphore.h>

sem_t sem;
pthread_t threads[5];

#define PERMIT_COUNT 2

/* A thread callback fn must have following prototypes 
 * void *(*thread_fn)(void *)
 * */
static void *
thread_fn_callback(void *arg) {
	char *thread_name = (char*)arg;
	int i;
	sem_wait(&sem);
	for(i = 0; i < 5; i++){
		printf("%s entered in critical section\n", thread_name);
		sleep(1);
	}
	sem_post(&sem);
	return NULL;
}

void
thread_create(pthread_t *thread_handle, void *arg) {
	int rc =  pthread_create(thread_handle, 
							NULL, 
							thread_fn_callback, 
							arg);
	if(rc != 0){
		printf("Error occurred");
		exit(0);
	}
}
int
main(int argc, char **argv){
	sem_init(&sem, 0, PERMIT_COUNT);
	thread_create(&threads[0], "thread0");
	thread_create(&threads[0], "thread1");
	thread_create(&threads[0], "thread2");
	thread_create(&threads[0], "thread3");
	thread_create(&threads[0], "thread4");
	int i ;
	for ( i = 0; i < 5; i++ ) {
		pthread_join(threads[i], NULL);
	}
	sem_destroy(&sem);
	return 0;
}

