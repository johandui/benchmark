#include <iostream>
#include <cstdlib>
#include <time.h>
#include <thread>
using namespace std;

int a[100];
double theseSecs = 0.0;
double startSecs = 0.0;
int endSecs = 1;
double secs;
long counter = 0;
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
{
	clock_gettime(CLOCK_REALTIME, &tp1);
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
void print(int n)
{

	counter++;
/*	static int sol = 0;
	cout << "Solution:" << ++sol << endl
		 << "N:" << n << endl;
	int i, k;
	for (i = 1; i <= n; i++)
	{
		for (k = 1; k <= n; k++)
			if (a[i] == k)
				cout << " Q";
			else
				cout << " .";
		cout << '\t'
			 << a[i] << endl;
	}
	cout << endl;
	*/
}
bool check(int k, int i)
{
	int j;
	for (j = 1; j < k; j++)
		if (a[j] == i || abs(a[j] - i) == abs(j - k))
			return false;
	return true;
}
void queen(int k, int n)
{
	if(type == 1 && !check_time())
	return;
	int i;
	for (i = 1; i <= n; i++)
	{
		if (isReady)
		{
			if (check(k, i))
			{
				a[k] = i;
				if (k == n)
				print(n);
				else
					queen(k + 1, n);
			}
		}
		else
			break;
	}
}

int main()
{
	int i = 100;
	cout << "Type" << endl
		 << "1. Minute based" << endl
		 << "2. N based" << endl;
	cin >> type;
	if (type == 2)
	{
		cout << "Minimum input is 9!" << endl;
		cin >> i;
	}
	else 	{
		cout << "Please input minute" << endl;
		cin >> endSecs;
	}
	start_time();
	start_CPU_time();
	for (int j = 8; j <= i; j++)
	{
		if(isReady)
			queen(1, j);
	    else break;
	}
	end_time();
	end_CPU_time();
	CPUutilisation = CPUsecs / secs * 100.0;
	printf("\nSolutions: %i, Elapsed Time %7.4f, CPU Time %7.4f, CPU Ut %3.0f%\n",
		   counter, secs, CPUsecs, CPUutilisation);

	return 0;
}
