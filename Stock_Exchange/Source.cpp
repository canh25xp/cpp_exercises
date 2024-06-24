#include <iostream>

using namespace std;

int find_max(int arr[], int start, int end);
int main(){
	freopen("input1.txt", "r", stdin);
	int TEST_CASE;
	cin >> TEST_CASE;
	for(int index = 0; index < TEST_CASE; index++){
		int ans = 0;
		int known_days=0;
		int stock_price[30];

		int money=0, stock=0;

		cin >> known_days;
		for(int i=0 ; i<known_days ; i++){
			cin >> stock_price[i];
		}

		for(int date=0 ; date<known_days ; date++){
			int highest_stock_day = find_max(stock_price,date,known_days);
			while(date<highest_stock_day){
				money -= stock_price[date];
				stock++;
				date++;
			}
			money += stock*stock_price[date];
			stock = 0;
		}

		cout<< "#" << index+1 << " " << money << endl;
	}

	return 0;
}

int find_max(int arr[], int start, int end){
	int max=0, max_index=0;
	for(int i=start;i<end;i++){
		if(arr[i]>max){
			max=arr[i];
			max_index=i;
		}
	}
	return max_index;
}
