#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mpi/mpi.h"

using namespace std;
int SIZE = 100;
int range = 100;

void showNumbers(int *numbers)
{
    std::string string;
    for ( int i = 0; i < SIZE; i++ ) {
        string = string + std::to_string(numbers[i]) + " ";
    }
    cout << string + "\n\n";
}

void swap(int *Mas, int i)
{
    int temp;
    temp=Mas[i];
    Mas[i]=Mas[i-1];
    Mas[i-1]=temp;
}

void shakerSort(int *Mas, int start, int n)
{
    int left, right, i;
    left = start;
    right = n-1;

    while (left <= right) {
        for (i = right; i >= left; i--)
            if (Mas[i-1] > Mas[i]) {
                swap(Mas, i);
            }
            left++;
        for (i = left; i <= right; i++)
            if (Mas[i-1] > Mas[i]) {
                swap(Mas, i);
            }
                right--;
    }
}

int main()
{
    bool working = true;

    while (working) {
        cout << "Enter size: ";
        cin >> SIZE;
        cout << "Enter range: ";
        cin >> range;

        int *numbers = new int[SIZE];

        time_t time (time_t* timer);
        srand(time(NULL));

        for (int i = 0; i < SIZE; i++) {
            numbers[i] = (rand() % range);
        }

        showNumbers(numbers);

	int MPI_INIT_THREAD(MPI_THREAD_SINGLE);
	shakerSort(numbers, 1, SIZE);


        showNumbers(numbers);
        
	int answer;
	
	
        while (true) {
            cout << "Repeat - 1, Exit - 0: ";
            cin >> answer;
            if (answer == 1) {
                break;
            } if (answer == 0) {
                exit(1);
            } else {
                cout << "Try again\n";
            }
        }
    }

    return 0;
}
