//23k2001  Q3
#include<iostream>
using namespace std;

template<class T> T** matrixMultiplier(T **mat1,T **mat2,int mat1rows,int mat1cols,int mat2rows,int mat2cols,int &resR,int &resC){
        if(mat1cols==mat2rows){
			resR = mat1rows;
			resC = mat2cols;
            T **prod = new T*[resR];
			for(int i=0;i<resR;i++){
				prod[i] = new T[resC];
				for(int j=0;j<resC;j++)
				prod[i][j] = 0;
			}

            for(int i=0;i<mat1rows;i++){
                for(int j=0;j<mat2cols;j++){
                    for(int x=0;x<mat1cols;x++)
						prod[i][j] += mat1[i][x]*mat2[x][j];
                }     
            }
			return prod;
        } else{
			cout<<"Sorry cannot multiply! (Orders not compatible)"<<endl;
			return nullptr;
		}
}

template<class T> void display(T **matrix,int rows,int cols){
	if(matrix==nullptr || rows==0 || cols==0)
	cout<<"Error displaying matrix!"<<endl;
	else{
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++)
				cout<<matrix[i][j]<<"\t";
		
			cout<<endl;
		}
	}
}
template<class T> T **genMatrix(int r,int c){
	T **gen = new T*[r];
		for(int i=0;i<r;i++){
			gen[i] = new T[c];
			for(int j=0;j<c;j++)
			gen[i][j] = 0;
		}
	return gen;
}
int main()
{
	int **A = genMatrix<int>(2,1);
	int **B = genMatrix<int>(1,2);

	A[0][0] = 10;
	A[1][0] = 15;

	B[0][0] = 2;
	B[0][1] = 6;
	
	cout<<"Matrix A:"<<endl;
	display(A,2,1);
	cout<<"Matrix B:"<<endl;
	display(B,1,2);

	int r=0,c=0;
	cout<<endl<<"Matrix C (A*B):"<<endl;
	int **C = matrixMultiplier(A,B,2,1,1,2,r,c);
	display(C,r,c);

	int r1=0,c1=0;
	cout<<endl<<"Matrix D (A*A):"<<endl;
	int **D = matrixMultiplier(A,A,2,1,2,1,r1,c1);
	display(D,r1,c1);

	double **E = genMatrix<double>(2,1);
	double **F = genMatrix<double>(1,2);

	E[0][0] = 10.5;
	E[1][0] = 15.2;

	F[0][0] = 2.3;
	F[0][1] = 6.4;
	
	cout<<endl<<"Matrix E:"<<endl;
	display(E,2,1);
	cout<<"Matrix F:"<<endl;
	display(F,1,2);

	int r2=0,c2=0;
	cout<<endl<<"Matrix G (E*F):"<<endl;
	double **G = matrixMultiplier(E,F,2,1,1,2,r2,c2);
	display(G,r2,c2);
	return 0;
}