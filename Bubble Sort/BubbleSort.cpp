#include <iostream>
#include <vector>

using namespace std;
int bubbleSort(int arr[], int n) {
    int c = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            c++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
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

        int nofcmp = bubbleSort(arr, size);

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



