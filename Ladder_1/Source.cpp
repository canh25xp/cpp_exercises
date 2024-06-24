#include <iostream>

using namespace std;

#define TEST_CASE 10
#define ROW 100
#define COL 100

void move_backward(int arr[ROW][COL], int& row, int& col);

int main(){
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	for(int index = 0 ; index <TEST_CASE ; index++){
		int case_num, ans=0;
		cin >> case_num;

		int ladder[ROW][COL];
		int dest_col=0;
		int dest_row=0;

		for(int row=0;row<ROW;row++){
			for(int col=0;col<COL;col++){
				cin >> ladder[row][col];
				if (ladder[row][col] == 2){
					dest_col = col;
					dest_row = row;
				}
			}
		}

		move_backward(ladder,dest_row,dest_col);

		cout<< "#" << case_num << " " << dest_col << endl;
	}

	return 0;
}
void move_backward(int arr[ROW][COL], int& row, int& col){
	int direction=0;
	while(row>0){
		if(col>0 && arr[row][col-1]==1 && direction != 2){
			col--;
			direction = 1;
		}

		if(col<COL-1 && arr[row][col+1]==1 && direction != 1){
			col++;
			direction = 2;
		}

		if(arr[row-1][col]==1){
			row--;
			direction = 0;
		}
	}
	return ;
}


