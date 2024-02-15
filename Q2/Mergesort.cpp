// 2) Write a program to sort the elements of an array using Merge Sort (The program
// should report the number of comparisons).




#include <iostream>
#include <vector>

using namespace std;


int merger(int arr[],int s,int e){
    // Mering 2 sorted array: copy vals from og array and 
    // paste in newly created arrays;
    int cmp=0;
    int mid = (s+e)/2;
    int l1 = mid-s+1;
    int l2 = e-mid;

    int fir[l1];
    int sec[l2];

    int ogindex = s;
    for(int i=0;i<l1;i++){
        fir[i] = arr[ogindex];
        ogindex++;
    }

    ogindex = mid+1;
    for(int i =0; i<l2; i++){
        sec[i] = arr[ogindex];
        ogindex++;
    }

    // Merging two sorted arrays: 
    int i=0;
    int j=0;
    ogindex=s;

    while(i<l1 && j<l2){
        if(fir[i] < sec[j]){
            arr[ogindex] = fir[i];
            i++;
            ogindex++;
            cmp++;
        }
        else{
            arr[ogindex] = sec[j];
            j++;
            ogindex++;
            cmp++;
        }
    }

    while(i<l1){
        arr[ogindex] = fir[i];
        i++;
        ogindex++;
    }
    while(j<l2){
        arr[ogindex] = sec[j];
        j++;
        ogindex++;
    }
    return cmp;
}

int mergesort(int arr[],int s,int e){
    int c=0;
    if( s<e){
        int mid = (s+e)/2;
        mergesort(arr,s,mid);
        mergesort(arr,mid+1,e);
        c = merger(arr,s,e);
    }
    return c;

}

vector <int> v1;
void generatearr(int size, int no_of_arr, int avgcmp) {
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

        int nofcmp = mergesort(arr,0,size-1);

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
};

int main(){

    int sizes[]={30,40,50,60,70,80,90,100};
    for(int i=0;i<=7;i++){
        int avgcmp=0;
        generatearr(sizes[i],10,avgcmp);

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

