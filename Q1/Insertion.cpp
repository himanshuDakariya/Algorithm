// 1) Write a program to sort the elements of an array using Insertion Sort (The program
// should report the number of comparisons).

#include <iostream>
#include <vector>

using namespace std;
int instsort(int arr[], int n)
{
    int i, key, j;
    int c = 0;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        c++;
        while (j >= 0 && arr[j]>key){
            c++;
            arr[j + 1] = arr[j];
            j = j - 1;
  
        }
        arr[j + 1] = key;
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

        int nofcmp = instsort(arr, size);

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



