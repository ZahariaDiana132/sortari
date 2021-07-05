//Merge sort
//Algoritm de merging
//Creem un vector temporar
//Iterăm cele două jumătăți sortate de la stânga la dreapta
//Copiem în vectorul temporar elementul mai mic dintre cele două
#include <iostream>
#include<bits/stdc++.h>
#include <chrono>
#include <functional>
#include <random>
using namespace std;
using namespace std::chrono;
int T;
int cnt,I1,S1,I2,S2;
void intercls(vector<int> &v, int Idx, int I1, int S1, int I2, int S2)
{
    vector<int> m(S2-I1+1);
    cnt=0;
    while (I1<=S1 && I2<=S2)
        {
        if (v[I1]<=v[I2])
        {
            m[cnt]=v[I1];
            I1++;
        }
        else
        {
            m[cnt] = v[I2];
            I2++;
        }
        cnt++;
    }
    while (I1<=S1)
    {
        m[cnt]=v[I1];
        cnt++;
        I1++;
    }
    while(I2<=S2)
    {
        m[cnt]=v[I2];
        cnt++;
        I2++;
    }
    for (int j=0;j<cnt;j++)
    {
        v[Idx+j]=m[j];
    }
}

void mergesort(int n,vector<int> &v)
{
    int sv=1;
    while (sv<n)
    {
        int i=0;
        while (i<n)
        {
            I1=i, S1=i+sv-1, I2=i+sv, S2=i+2*sv-1;
            if (I2<n)
            {
                if (S2>=n)
                {
                    S2=n-1;
                }
                intercls(v, i, I1, S1, I2, S2);
            }
            i=i+2*sv;
        }
        sv=sv*2;
    }
}

int main()
{

    cout<<"T= "; cin>>T; //numar de teste
    cout <<"\n";
int ok=0;
    for (int i=0;i<T;i++)
        {

        int N,MAX;// cate numere trebuie sortate si cel mai mare numar
        cout<<"N= ";cin>>N;
         cout <<"\n";
        vector<int>nr(N);    vector<int>nr2(N);
        cout << "MAX=";
        cin>>MAX;
     if(MAX>1000000)
     {ok=1; cout<<"nu merge countsort";}
     if(ok!=1)
       {
        //generare input random
        random_device random;
        mt19937 G(random());
        uniform_int_distribution<int>range(0,MAX);
        auto g=bind(range,G);
        generate_n(nr.begin(),N,g);

   int k=0;
   while(k<nr.size())
    {nr2[k]=nr[k];
    k++;}

    //    mergesort(N,nr);
    //   cout<<"\n";
    //   k=0;
    //   while(k<nr.size())
     // {cout<<nr[k]<<" ";
   //k++;}


    auto start = high_resolution_clock::now();
    sort(nr2.begin(), nr2.end());
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken normal sort:"<< duration.count() << " microseconds" << endl;
    cout <<"\n";
//aflarea timpului de executare
    auto start2 = high_resolution_clock::now();
    mergesort(N, nr);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2- start2);

    cout << "Time taken mergesort:"<< duration2.count() << " microseconds" << endl;
    }}
    return 0;}
