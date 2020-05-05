#include<iostream>
#include<cstdlib>
#include <time.h>
using namespace std;
struct pointer{
    int val;
    pointer *next;
};
pointer *top = NULL;


double theseSecs = 0.0;
double startSecs = 0.0;
int endSecs = 1;
double secs;
double CPUsecs = 0.0;
double CPUutilisation = 0.0;
double answer = 0;
int type;
clock_t starts;

void start_CPU_time()
{
	starts = clock();
	;
	return;
}

void end_CPU_time()
{
	CPUsecs = (double)(clock() - starts) / (double)CLOCKS_PER_SEC;
	return;
}

struct timespec tp1;
void getSecs()
{https://github.com/johandui/benchmark.gittime(CLOCK_REALTIME, &tp1);
	theseSecs = tp1.tv_sec + tp1.tv_nsec / 1e9;
	return;
}

void start_time()
{
	getSecs();
	startSecs = theseSecs;
	return;
}

void end_time()
{
	getSecs();
	secs = theseSecs - startSecs;
	return;
}

bool check_time()
{
	getSecs();
	secs = theseSecs - startSecs;
	return endSecs  > secs;
}
bool isReady(){
	return 	(type == 1 && check_time()) || type == 2;
}


// [3]-> [2]->[1]->[NULL]
void push(int k){
    pointer *x;
    x = new pointer;
    x->val = k;
    x->next = top;
    top = x;
}
bool isEmpty(){
    return top == NULL;
}
int pop(){
    if(isEmpty())
        return 0;
    top = top->next;
    delete top;
    return 1;
}

void print(){
    pointer *p;
    //p = new pointer;
    for(p = top; p!= NULL; p = p->next)
        cout << p->val << " ";
    cout << endl;
}
void empty(){
    top = NULL;
}

void justDoIt(int j){
 
    for(int i = 0; i < j; i++){
        push(rand() % 100);
    }
    for(int i = 0; i < j; i++)
        pop(); 
}
int main(){
    int j;
    cin >> j;
    srand (time(NULL));

    
	start_time();
	start_CPU_time();
    justDoIt(j);
    
	end_time();
	end_CPU_time();
    CPUutilisation = CPUsecs / secs * 100.0;
	printf("\nElapsed Time %7.4f, CPU Time %7.4f, CPU Ut %3.0f%\n",
		   secs, CPUsecs, CPUutilisation);

    return 0;
}

