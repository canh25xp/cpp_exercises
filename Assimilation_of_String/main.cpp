#include <iostream>
using namespace std;

#define DEFAULT_TEST_CASE 10

int main(){
	FILE *input;
	errno_t error = freopen_s(&input, "input.txt", "r", stdin);

	int TEST_CASE = DEFAULT_TEST_CASE;
	//cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){

		cout<< "Case #" << case_index+1 << endl;
	}

	fclose(input);

	return 0;
}