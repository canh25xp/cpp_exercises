#include <iostream>

using namespace std;

int TEST_CASE		= 10;
const int MAX_SIZE	= 200;
const int PATH		= 1;
const int TRAP		= 0;
const int PRICESS	= 2;

#define SIZE 10000
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

struct Point{
	Point();
	Point(int _row, int _col);

	bool operator!=(const Point& rhs) const ;
	bool operator==(const Point& rhs) const ;

	int row,col;
};

bool solveMaze(Point start_point, Point end_point, int maze[MAX_SIZE][MAX_SIZE], int size);

int main(){
	freopen("input.txt", "r", stdin);
	cin >> TEST_CASE;
	for(int case_index = 0 ; case_index <TEST_CASE ; case_index++){
		int maze_size=0;
		cin >> maze_size;
		int maze[MAX_SIZE][MAX_SIZE] = {};

		Point Princess;
		Point Entrance(0,0);
		Point Exit(maze_size-1,maze_size-1);

		for (int i = 0; i < maze_size; i++){
			for (int j = 0; j < maze_size; j++){
				cin >> maze[i][j];
				if(maze[i][j] == PRICESS)
					Princess = Point(i,j);
			}
		}

		bool Found_Princess = solveMaze(Entrance, Princess, maze, maze_size);
		bool Found_Exit = solveMaze(Princess, Exit, maze, maze_size);

		cout<< "#" << case_index+1 << " " << endl;
	}

	return 0;
}

bool solveMaze(Point start_point, Point end_point, int maze[MAX_SIZE][MAX_SIZE], int size){
	//up, right, down, left
	const int dx[] = {0 ,1 ,0 ,-1};
	const int dy[] = {-1,0 ,1 ,0};

	Stack<Point> stack;
	stack.push(start_point);

	bool checked[MAX_SIZE][MAX_SIZE]={};

	while(!stack.isEmpty()){
		Point current_point = stack.pop();

		if(current_point == end_point)
				return true;
		
		int col = current_point.col;
		int row = current_point.row;
		
		checked[row][col] = 1;

		for(int direction=0; direction<4; direction++){
			int new_col = col + dx[direction];
			int new_row = row + dy[direction];

			if( new_row < size	&& new_row >= 0 && new_col < size && new_col >= 0 && maze[new_row][new_col] != TRAP && checked[new_row][new_col] == 0){
				stack.push(Point(new_row,new_col));
			}
		}
	}
	return false;
}

Point::Point(){
	row=0;
	col=0;
}

Point::Point(int _row, int _col){
	row = _row;
	col = _col;
}

bool Point::operator!=(const Point& rhs) const{
	if(row==rhs.row && col == rhs.col)
		return false;
	else
		return true;
}

bool Point::operator==(const Point& rhs) const {
	if(row==rhs.row && col == rhs.col)
		return true;
	else
		return false;
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