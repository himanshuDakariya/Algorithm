// #include<iostream>
// using namespace std;

// int min(int arr[],int n,int s,int &c){
//     int min=arr[s];
//     int minindex=0;
//     for(int i=s;i<n;i++){
//         c++;
//         if(arr[i]<min){
//             min=arr[i];
//             minindex=i;
//         }
//     }
//     return minindex;
// }

// int Selectionsort(int arr[],int s,int n){
//     int c=0;
//     while(s<n-1){
//         swap(arr[s],arr[min(arr,n,s,c)]);
//         s++;
//     }
//     return c;
// }



// int main (){

//     int arr[]={4,8,1,9};

   
//     cout<<Selectionsort(arr,0,4);

   
// return 0;

// }



// 1) Write a program to sort the elements of an array using Insertion Sort (The program
// should report the number of comparisons).

#include <iostream>
#include <vector>

using namespace std;

int min(int arr[],int n,int s,int &c){
    int min=arr[s];
    int minindex=0;
    for(int i=s;i<n;i++){
        c++;
        if(arr[i]<min){
            min=arr[i];
            minindex=i;
        }
    }
    return minindex;
}

int Selectionsort(int arr[],int s,int n){
    int c=0;
    while(s<n-1){
        swap(arr[s],arr[min(arr,n,s,c)]);
        s++;
    }
    return c;
}

vector <int> v1;
void generatearr(int size, int no_of_arr, int avgcmp,int s) {
    for (int i = 0; i < no_of_arr; i++) {
        int arr[size];
        for (int j = 0; j < size; j++) {
            arr[j] = rand() % 100;
        }

        cout << "----------------------------------------------------------------" << endl;
        cout << "No. of Elements: " << size << endl;
        cout << "Random Array:" << endl;
        for (int k = 0; k < size; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;

        int nofcmp = Selectionsort(arr,s,size);

        cout << "Sorted Array:" << endl;
        for (int k = 0; k < size; k++) {
            cout << arr[k] << " ";
        }

        avgcmp += nofcmp;
        cout<<endl;
        cout << "Number of Comparisons: " << nofcmp << endl;
        cout << "----------------------------------------------------------------" << endl;
    }
    avgcmp /= no_of_arr;
    cout << "Average comparisons for array size " << size << ": " << avgcmp << endl;
    v1.push_back(avgcmp);
}

int main() {

    int sizes[]={30,40,50,60,70,80,90,100};
    for(int i=0;i<=7;i++){
        int avgcmp=0;
        generatearr(sizes[i],10,avgcmp,0);

    }

    cout<<endl;
    cout<<endl;
    cout<<"Avg. of # of comparisons of 10 random arrays, each of size 30...40...50..60.70...."<<endl;
    cout<<"_____________________________________"<<endl;
    for(int e:v1){
        cout<<e<<" ";
    }


    return 0;
}



