#include <iostream>
#include <limits>
using namespace std;

const int max_size = 10;

void clearInputStream() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void inputArray(int arr[], int &size, string name){
	cout<<"\nEnter number of elements for "<<name<<" : ";
	cin>>size;
	
	while (size<=0 || size>max_size) {
		clearInputStream();
        cout<<"Invalid input. Please enter a number between 1 and 10: \n";
        cin>>size;
    }
	
	cout<<"\nEnter "<<size<<" elements: \n";
	for(int i=0; i<size; i++){
		cin>> arr[i];
		
		while(cin.fail()){
            clearInputStream();
            cout<<"Invalid input. Please enter a valid number: \n";
            cin>>arr[i];
        }
	}
}

void mergeArray(int arr1[], int size1, int arr2[], int size2, int merge[], int &mergesize){
	mergesize = size1 + size2;
	for(int i=0; i<size1; i++){
		merge[i] = arr1[i];
	}
	for(int i=0; i<size2   ; i++){
		merge[size1+i] = arr2[i];
	}
}

void sortDescending(int arr[], int size){
	for (int k = 0; k < size - 1; k++) {
        for (int j = k + 1; j < size; j++) {
            if (arr[k] < arr[j]) {
                swap(arr[k], arr[j]);
            }
        }
    }
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";  
    }
    cout << endl;
}

int main(){
    cout<<"Hello\n";
    int arr1[max_size], arr2[max_size], merge[max_size * 2];
	int size1, size2, mergesize;
	
	cout<<"Max elements is 10";	
	
	inputArray(arr1, size1, "Array 1");
	inputArray(arr2, size2, "Array 2");
	mergeArray(arr1, size1, arr2, size2, merge, mergesize);
	sortDescending(merge, mergesize);
	
	cout<<"\nMerged and Sorted Array in descending order: ";
	
	display(merge, mergesize);

    return 0;
}