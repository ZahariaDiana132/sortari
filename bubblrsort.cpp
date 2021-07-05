//Bubble sort
//Avantaje: Este metoda simplă de sortare.Nu este necesară nicio structură de date suplimentară.
//Este metoda de sortare pe loc. Este o metodă stabilă de sortare.
//Dezavantajele: Este o metodă foarte ineficientă-O(n^2).
//Chiar dacă elementele sunt în ordinea sortată, toate trecerile n-1 se vor face.
#include <iostream>
#include<bits/stdc++.h>
#include <chrono>
#include <functional>
#include <random>
using namespace std;
using namespace std::chrono;
int T,aux;

void bubblesort(int n, vector<int> &b)
{
   for(int i=0; i<(n-1); i++)
	{
		for(int j=0; j<(n-i-1); j++)
		{
			if(b[j]>b[j+1])
			{
				aux=b[j];
				b[j]=b[j+1];
				b[j+1]=aux;
			}
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
      // int k=0;
   // while(k<nr.size())
     // {cout<<nr[k]<<" ";
      //  k++;
     // }
     //  cout<<"\n";
     //  bubblesort(N,nr);


     //  k=0;
    //  while(k<nr.size())
    //  {cout<<nr[k]<<" ";
    //   k++;}

    //aflarea timpului de executare
    auto start = high_resolution_clock::now();
    sort(nr2.begin(), nr2.end());
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken normal sort:"<< duration.count() << " microseconds" << endl;
    cout <<"\n";

    auto start2 = high_resolution_clock::now();
    bubblesort(N,nr);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2- start2);

    cout << "Time taken bubblesort:"<< duration2.count() << " microseconds" << endl;
    }}
    return 0;}
