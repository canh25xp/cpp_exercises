#include<iostream>

using namespace std;

#define MAX_GROUP 1000

int size(int*, const int&);
void bubbleSort(int*, const int&);

int main(int argc, char** argv){
	int test_case;
	int T;

	ios::sync_with_stdio(false);
	freopen("test.txt", "r", stdin);
	cin >> T;

	for(test_case = 1; test_case <= T; ++test_case){
		int number_of_group=0;
		cin >> number_of_group;
		int ans = 0;

		int groups[MAX_GROUP];

		for(int i=0 ; i<number_of_group ; i++){
			cin >> groups[i];
		}

		while(number_of_group>1){
			bubbleSort(groups, number_of_group);
			int cost = groups[0]+groups[1];
			ans += cost;
			groups[0]=cost;
			for(int i=1; i<number_of_group-1; i++){
				groups[i]=groups[i+1];
			}
			groups[number_of_group-1]=0;
			number_of_group--;
		}

		cout << "Case #" << test_case << endl << ans << endl;
	}
	return 0;
}

int size(int* arr, const int& length){
	int size=0;
	for(int i=0; i<length ; i++){
		size+=arr[i];
	}
	return size;
}

void bubbleSort(int* arr,const int& length){
	int i, j;
	bool swapped;
	for (i = 0; i < length - 1; i++) {
		swapped = false;
		for (j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}
