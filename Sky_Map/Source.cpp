#include <iostream>
using namespace std;

#define DEFAULT_TEST_CASE 10

template <typename T, unsigned int MAX>
class Stack{
public:
	Stack();
	~Stack();

private:
	int top;
	T st[MAX];
};

int main(){
	FILE *input;
	errno_t error = freopen_s(&input, "input.txt", "r", stdin);

	int TEST_CASE = DEFAULT_TEST_CASE;
	//cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		int ans = 0;

		Stack<int ,10> s;

		cout<< "#" << case_index+1 << " " << ans << endl;
	}

	fclose(input);

	return 0;
}

template <typename T, unsigned int MAX>
Stack<T,MAX>::Stack(){
	top = -1;
	st;
}

template <typename T, unsigned int MAX>
Stack<T,MAX>::~Stack(){
}