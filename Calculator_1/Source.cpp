#include <iostream>

using namespace std;

#define TEST_CASE	10
#define LENGTH		200

int main(){
	ios::sync_with_stdio(false);
	freopen("cal1_test_input.txt", "r", stdin);
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		int length=0, ans = 0;
		cin >> length;

		char string[LENGTH];

		cin >> string;

		
		for(int i=0 ; i<length ; i+=2){
			ans+=string[i] - '0';
		}


		cout<< "#" << case_index+1 << " " << ans << endl;
	}

	return 0;
}