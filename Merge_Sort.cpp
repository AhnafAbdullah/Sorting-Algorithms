#include <iostream>
#include <vector>
using namespace std;

vector<int>* merge(vector<int> &array, int low, int mid, int high) {

}

void mergeSort(vector<int> &array, int low, int high) {
	int mid = (low + high) / 2;

	mergeSort(array, low, mid);
	mergeSort(array, mid+1, high);
	//merge
}

int main() {

}