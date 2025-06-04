# Semaphore Hello World

This project demonstrates the use of POSIX threads and semaphores in C. It provides a simple "Hello World" style example to illustrate how semaphores can be used to control access to a critical section among multiple threads.

## Introduction

The program creates five threads, each of which tries to enter a critical section. A semaphore is used to limit the number of threads that can enter the critical section simultaneously (set by `PERMIT_COUNT`). This is a basic example for learning multithreading and synchronization in C using POSIX APIs.

## How It Works

- The main function initializes a semaphore with a permit count of 2.
- Five threads are created, each running the same callback function.
- Each thread waits on the semaphore before entering the critical section, prints a message, sleeps for a second, and repeats this five times.
- After finishing, the thread releases the semaphore.
- The main thread waits for all threads to finish before destroying the semaphore and exiting.

## Compilation

To compile and run the program, use the following commands in your terminal:

```sh
gcc -g -c semaphore_hello_world.c -o semaphore_hello_world.o
gcc -g semaphore_hello_world.o -o semaphore_hello_world.exe -lpthread
./semaphore_hello_world.exe
```

> **Note:**  
> On macOS, you may see deprecation warnings for `sem_init` and `sem_destroy`. These can be ignored for learning purposes.

## Requirements

- GCC or compatible C compiler
- POSIX threads library (`-lpthread`)
- Unix-like environment (Linux, macOS)

## License

This code is for educational purposes.
