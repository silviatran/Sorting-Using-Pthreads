//Silvia Tran
//CECS 325-01
//Prog 4 - Sorting Contest Using PThreads
//03/27/2024
//I certify that this program is my own original work.
//I did not copy any part of this program from any other source.
//I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <pthread.h>
#include <string>
using namespace std;

struct sortStuff {
    int *start;
    int size;
};

void bubble(int A[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void *bridge(void *ptr) {
    sortStuff *arg = (sortStuff *)ptr;
    bubble(arg->start, arg->size);
    return NULL;
}

void merge(int A[], int left[], int right[], int leftSize, int rightSize) {
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            A[k] = left[i];
            i++;
        }
        else
        {
            A[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < leftSize)
    {
        A[k] = left[i];
        i++;
        k++;
    }
    while (j < rightSize)
    {
        A[k] = right[j];
        j++;
        k++;
    }
}


int main(int argc, char *argv[])
{
    ifstream input_file;
    ofstream output_file;

    input_file.open(argv[1]);

    const int array_size = 1000000;
    int *numbers = new int[array_size];
    int count = 0;

    while (input_file >> numbers[count] && count < array_size)
    {
        count++;
    }

    input_file.close();

    pthread_t t0, t1, t2, t3, t4, t5, t6, t7;
    sortStuff ss0, ss1, ss2, ss3, ss4, ss5, ss6, ss7;
    int iret0, iret1, iret2, iret3, iret4, iret5, iret6, iret7;
    const int section_size = array_size / 8;
    
    ss0.start = &numbers[0];
    ss0.size = section_size;
    ss1.start = &numbers[section_size];
    ss1.size = section_size;
    ss2.start = &numbers[2 * section_size];
    ss2.size = section_size;
    ss3.start = &numbers[3 * section_size];
    ss3.size = section_size;
    ss4.start = &numbers[4 * section_size];
    ss4.size = section_size;
    ss5.start = &numbers[5 * section_size];
    ss5.size = section_size;
    ss6.start = &numbers[6 * section_size];
    ss6.size = section_size;
    ss7.start = &numbers[7 * section_size];
    ss7.size = section_size;

    iret0 = pthread_create(&t0, NULL, bridge, (void *)&ss0);
    iret1 = pthread_create(&t1, NULL, bridge, (void *)&ss1);
    iret2 = pthread_create(&t2, NULL, bridge, (void *)&ss2);
    iret3 = pthread_create(&t3, NULL, bridge, (void *)&ss3);
    iret4 = pthread_create(&t4, NULL, bridge, (void *)&ss4);
    iret5 = pthread_create(&t5, NULL, bridge, (void *)&ss5);
    iret6 = pthread_create(&t6, NULL, bridge, (void *)&ss6);
    iret7 = pthread_create(&t7, NULL, bridge, (void *)&ss7);

    pthread_join(t0, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    pthread_join(t6, NULL);
    pthread_join(t7, NULL);

    cout << "Thread 0 returns: " << iret0 << endl;
    cout << "Thread 1 returns: " << iret1 << endl;
    cout << "Thread 2 returns: " << iret2 << endl;
    cout << "Thread 3 returns: " << iret3 << endl;
    cout << "Thread 4 returns: " << iret4 << endl;
    cout << "Thread 5 returns: " << iret5 << endl;
    cout << "Thread 6 returns: " << iret6 << endl;
    cout << "Thread 7 returns: " << iret7 << endl;

    int temp[array_size];
    int step = section_size;
    while (step < array_size)
    {
        for (int i = 0; i < array_size; i += 2 * step)
        {
            merge(temp + i, numbers + i, numbers + i + step, step, min(step, array_size - i - step));
        }
        step *= 2;
        for (int i = 0; i < array_size; ++i)
        {
            numbers[i] = temp[i];
        }
    }

    output_file.open(argv[2]);

    for (int i = 0; i < array_size; ++i)
    {
        output_file << numbers[i] << endl;
    }

    output_file.close();

    delete[] numbers;

    return 0;
}