//Countsort
//Creem un vector de frecvență v
//Numărăm aparițiile fiecărui element din nr
//Modificăm vectorul v a.î.
//v[i] = numărul de elemente cu valoare = i
//La final iteram prin vectorul v[i] și afisam i de v[i] pentru toate numerele de la 1 la MAX

#include <iostream>
#include<bits/stdc++.h>
#include <chrono>
#include <functional>
#include <random>
using namespace std;
using namespace std::chrono;

vector<int>v(100000);
int T;



void countsort(int n,vector<int> &nr)
{
    int maxi=-1;
    for (int i = 0; i < n; i++)
        {
        v[nr[i]]++;
        if (nr[i] > maxi)
        {
            maxi=nr[i];
        }
    }
    int ct=0;
    for (int i=0;i<=maxi;i++)
    {
        while (v[i]){
            nr[ct] =i;
            ct++;
            v[i]--;
        }
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
        vector<int>nr(N);vector<int>nr2(N);
        cout << "MAX=";
        cin>>MAX;
     if(MAX>1000000)
     {ok=1; cout<<"nu";}
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
       //int k=0;
  //  while(k<nr.size())
      //     {cout<<nr[k]<<" ";
   //   k++;}

       // countsort(N,nr);
       //cout<<"\n";
       // k=0;
      //  while(k<nr.size())
      //{cout<<nr[k]<<" ";
 //  k++;}

    //aflarea timpului de executare pt countsort
    auto start = high_resolution_clock::now();
    sort(nr2.begin(), nr2.end());
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken normal sort:"<< duration.count() << " microseconds" << endl;
    cout <<"\n";

    auto start2 = high_resolution_clock::now();
    countsort(N, nr);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2- start2);

    cout << "Time taken countsort:"<< duration2.count() << " microseconds" << endl;
    }}
    return 0;
}
