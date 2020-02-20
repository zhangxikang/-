#include <iostream>
#include <fstream>
#include <string>
#include<Windows.h>
using namespace std;
#define N 64
bool isPeak(const double grid[][N], int r, int c);
int main(){
	int nrows, ncols;
	double map[N][N];
	string filename;
	ifstream file;
	cout <<"请输入文件名.\n";
	cin >> filename;
	file.open(filename.c_str());
	if(file.fail()){
		cerr<<"打开输入文件出错.\n";
		exit(1);
	}
	file>>nrows>>ncols;
	if(nrows > N || ncols > N){
		cerr<<"网格太大，调整程序.\n";
		exit(1);
	}
	//从数据文件读数据到数组
	for(int i=0; i<nrows; ++i){
		for(int j=0; j<ncols; ++j){
			file>>map[i][j];
		}
	}
	//判断并打印峰值位置
	for(int i=1;i<nrows-1; ++i){
		for(int j=1;j<ncols-1; ++j){
			if(isPeak(map, i, j)){
				cout<<"峰值出现在行: "<<i<<" 列:"<<j<<endl;
			}
		}
	}
	system("pause");
	//关闭文件
	file.close();
	//结束程序
	return 0;
}
bool isPeak(const double grid[][N], int i, int j) {
	if((grid[i-1][j]<grid[i][j]) &&
	(grid[i+1][j]<grid[i][j]) &&
	(grid[i][j-1]<grid[i][j]) &&
	(grid[i][j+1]<grid[i][j]))
		return true;
	else {
		return false;
	}
}