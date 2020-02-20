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
	cout <<"�������ļ���.\n";
	cin >> filename;
	file.open(filename.c_str());
	if(file.fail()){
		cerr<<"�������ļ�����.\n";
		exit(1);
	}
	file>>nrows>>ncols;
	if(nrows > N || ncols > N){
		cerr<<"����̫�󣬵�������.\n";
		exit(1);
	}
	//�������ļ������ݵ�����
	for(int i=0; i<nrows; ++i){
		for(int j=0; j<ncols; ++j){
			file>>map[i][j];
		}
	}
	//�жϲ���ӡ��ֵλ��
	for(int i=1;i<nrows-1; ++i){
		for(int j=1;j<ncols-1; ++j){
			if(isPeak(map, i, j)){
				cout<<"��ֵ��������: "<<i<<" ��:"<<j<<endl;
			}
		}
	}
	system("pause");
	//�ر��ļ�
	file.close();
	//��������
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