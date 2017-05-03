/*Tanenbaum's solution: philosopher only get forks when both left and right available,
which means philosophers pick forks when their neighbors are not eating,
return both forks when finish eating.
http://www.cs.grinnell.edu/~weinman/courses/CSC213/2012F/labs/philosophers.html
https://www.cs.indiana.edu/classes/p415-sjoh/hw/project/dining-philosophers/index.htm
Since eating time is random, there is no starvation.
*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "mt19937ar.c"

#define philos_num 5
#define hungry 0
#define thinking 1
#define eating 2
#define left (phi_id+philos_num-1)%philos_num
#define right (phi_id+1)%philos_num

char *philos_names[]= {"Kaiyuan","Trevor","Sophia","Plato","Kevin"};
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

void think(int phi_id){
	printf(" philosopher %s is thinking now !\n",philos_names[phi_id]);
	sleep(RandomNumberGenerator(20,1));
}

void eat(int phi_id){
	printf("philosopher %s is eating now !",philos_names[phi_id]);
	sleep(RandomNumberGenerator(9,2));
}

void test(int phi_id){
	//if(phi_status[phi_id]==hungry&&phi_status[left]!=eating&&phi_status[right]!=eating){
	//	phi_status[phi_id]=eat;
}

void get_forks(int phi_id){
pthread_mutex_lock(&mutex);
//test();
pthread_mutex_unlock(&mutex);
}


void put_forks(int phi_id){

}







void *philosopher(void *arg){
	int phi_id=*(int *)arg;
	while(1){
		think(phi_id);
		get_forks(phi_id);
		eat(phi_id);
		put_forks(phi_id);
	}
}

int main(int argc, char *argv[]){
	int i;
	pthread_t phi[phi_num];
	int id[phi_num];
	for(i=0;i<phi_num;i++){
		id[i]=i;
		pthread_create(&phi[i],NULL,philosopher,(void*)(&id[i]));
	}
	for(i=0;i<phi_num;i++){
		pthread_join(phi[num],NULL);
	}
}

int RandomNumberGenerator(int Max, int Min){
	int randNum = 0;
    randNum = (int)genrand_int32();
	randNum = abs(randNum);
	randNum %= (Max - Min) + Min;
    if (randNum < Min){	//Because modual can bring the number below the min
		randNum = RandomNumberGenerator(Max, Min);
		}
    else if( randNum > Max) { //Never be used but we have it
            randNum = RandomNumberGenerator(Max, Min);
    }
    return randNum;
}
