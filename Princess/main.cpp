#include <iostream>
#include <cstdio> 

using namespace std;

int TEST_CASE		= 10;
const int MAX_SIZE	= 200;
const int PATH		= 1;
const int TRAP		= 0;
const int PRICESS	= 2;

#define SIZE 10000

#define QUEUE_SIZE 10

template <typename T>
class Queue {
public:
	Queue(int size = QUEUE_SIZE);
	~Queue();

	T dequeue();
	void enqueue(T item);
	T peek();
	int size();
	bool isEmpty();
	bool isFull();

private:
	T* main;
	int capacity;
	int front, rear, count;
};

struct Point{
	Point();
	Point(int _row, int _col);

	bool operator!=(const Point& rhs) const ;
	bool operator==(const Point& rhs) const ;

	int row,col;
};

bool solveMaze(Point start_point, Point end_point, int maze[MAX_SIZE][MAX_SIZE], int size);

// MAIN
int main(){
	FILE *input;
	freopen_s(&input, "input.txt", "r", stdin);
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
	fclose(input);
	return 0;
}
//END MAIN

bool solveMaze(Point start_point, Point end_point, int maze[MAX_SIZE][MAX_SIZE], int size){
	Queue<Point> queue;
	queue.enqueue(start_point);

	int distance[MAX_SIZE][MAX_SIZE];

	for(int m = 0;m<size;m++) {
		for(int n =0;n<size;n++) {
			distance[m][n] = -1;
		}
	}

	while(!queue.isEmpty()){
		Point current_point = queue.dequeue();
		distance[current_point.row][current_point.col] = 0;
		for (int p = -1; p < 2; p++){
			for (int q = -1; q < 2; q++){
				if(p == q)
					continue;
				int i = current_point.row + p;
				int j = current_point.col + q;
				
				if(i<0)
					i=0;
				if(j<0)
					j=0;
				if(i>size-1)
					i=size-1;
				if(j>size-1)
					j=size-1;

				if(i == current_point.row && j == current_point.col)
					continue;

				if(distance[i][j] == -1){
					if(maze[i][j] != TRAP){
						distance[i][j] = distance[current_point.row][current_point.col] + 1;
						Point new_point(i,j);
						queue.enqueue(new_point);
					}
				}
			}
		}
	}

	return true;
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

template <typename T>
Queue<T>::Queue(int size){
	main = new T[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

template <typename T>
Queue<T>::~Queue(){
	delete[] main;
}

template <typename T>
T Queue<T>::dequeue(){
	if(isEmpty()){
		exit(EXIT_FAILURE);
	}

	T item = main[front];
	front = (front +1)%capacity;
	count--;

	return item;
}

template <typename T>
void Queue<T>::enqueue(T item){
    if (isFull()){
        exit(EXIT_FAILURE);
    }
 
    rear = (rear + 1) % capacity;
    main[rear] = item;
    count++;
}

template <typename T>
T Queue<T>::peek(){
    if (isEmpty()) {
        exit(EXIT_FAILURE);
    }
    return main[front];
}
 
template <typename T>
int Queue<T>::size() {
    return count;
}
 
template <typename T>
bool Queue<T>::isEmpty() {
    return (size() == 0);
}
 
template <typename T>
bool Queue<T>::isFull() {
	return (size() == capacity);
}
