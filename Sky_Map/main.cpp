#include <iostream>

using namespace std;

#define SIZE 1000
#define MAX_SIZE 25

#define MAX(a, b) ((a) < (b) ? b : a)

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

template <class T> class Stack {
public:
	Stack();
	bool push(T k);
	T pop();
	T topElement();
	bool isFull();
	bool isEmpty();
private:
	int top;
	T st[SIZE];
};

struct Pair{
	Pair();
	Pair(int x, int y);
	int x;
	int y;
};

int main(){
	ios::sync_with_stdio(false);
	freopen("eval_input.txt", "r", stdin);

	int TEST_CASE = 0;
	cin >> TEST_CASE;

	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		int N;
		cin >> N;
		int matrix[MAX_SIZE][MAX_SIZE];

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin >> matrix[i][j];
			}
		}

		int count=0, max=0, end=0;

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				max = 0;
				if(matrix[i][j] == 1){
					Stack<Pair> stack;
					Pair pair(i,j);
					stack.push(pair);
					matrix[i][j] = 0;
					max++;
					count++;
					while(!stack.isEmpty()){
						pair = stack.pop();
						for(int k=0; k<4; k++){
							Pair new_pair(pair.x+dx[k], pair.y+dy[k]);
							if(new_pair.x >= 0 && new_pair.x < N && new_pair.y >= 0 && new_pair.y < N && matrix[new_pair.x][new_pair.y] == 1){
								stack.push(new_pair);
								matrix[new_pair.x][new_pair.y] = 0;
								max++;
							}
						}
					}
				}
				end = MAX(end,max);
			}
		}

		cout<< count << " " << end << endl;
	}

	return 0;
}


template <class T> Stack<T>::Stack() {
	top = -1; 
}

template <class T> bool Stack<T>::push(T k){

	if (isFull()) {
		return 1;
	}

	top = top + 1;

	st[top] = k;

	return 0;
}

template <class T> bool Stack<T>::isEmpty(){
	if (top == -1)
		return 1;
	else
		return 0;
}

template <class T> bool Stack<T>::isFull(){
	if (top == (SIZE - 1))
		return 1;
	else
		return 0;
}

template <class T> T Stack<T>::pop(){
	T popped_element = st[top];
	top--;
	return popped_element;
}

template <class T> T Stack<T>::topElement(){
	T top_element = st[top];
	return top_element;
}

Pair::Pair(){
	x=0;
	y=0;
}

Pair::Pair(int _x, int _y){
	x = _x;
	y= _y;
}