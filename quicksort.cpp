//QUICK SORT
//ia ultimul element ca piv, il pune piv in pozitia sa corecta in qayul sortat
//si le pune pe toate cele mai mioi decat acesta la stanga lui si pe toate cele mai mari la dreapta lui
#include <iostream>
#include<bits/stdc++.h>
#include <chrono>
#include <functional>
#include <random>
#include<stdio.h>
using namespace std;
using namespace std::chrono;
int T,piv,aux,i;

void swap(int *a, int *b)
{
    aux=*a;
    *a=*b;
    *b=aux;
}

int partition (int q[], int I, int S)
{
     piv=q[S];    // pivot
     i=I-1;  //index elm mai mic

    for (int j = I; j <= S- 1; j++)
    {
        if (q[j] <= piv)
        {
            i++;    //index elm mai mic
            swap(&q[i], &q[j]);
        }
    }
    swap(&q[i+1], &q[S]);
    return (i+1);
}

void quickSort(int q[], int I, int S)
{
    if (I < S)
    {
        int pi = partition(q, I, S);
        quickSort(q, I, pi - 1);
        quickSort(q, pi + 1, S);
    }
}


int main()
{
   cout<<"T= ";
   cin>>T; //numar de teste
    cout <<"\n";
    int N, Max;
    for(int i=0; i<T; i++)
        {
            cout<<"N = ";
            cin>>N;
             if(N>100000)
                {
                    cout<<"nu ";
                    break;
                }
    cout<<"Max = ";cin>>Max;

    int q[N],q2[N];

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> d(0, Max); d(gen);

    for(int j=0;j<N;j++)
    {
        q[j] = d(gen);
        q2[j] = q[j];
    }

        auto start = high_resolution_clock::now();
        sort(q2, q2+N);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken normal sort:"<< duration.count() << " microseconds" << endl;
    cout <<"\n";

        auto start2 = high_resolution_clock::now();
        quickSort(q, 0, N-1);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop - start);


        cout << "Time taken quicksort:"<< duration2.count() << " microseconds" << endl;}


    return 0;}
