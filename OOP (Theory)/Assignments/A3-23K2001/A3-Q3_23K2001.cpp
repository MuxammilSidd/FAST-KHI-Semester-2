//23K2001 Muzammil Q3
#include<iostream>
using namespace std;
template<class T> class matrix{
    protected:
    int rows,cols;
    // T mat[][];
    T** mat;

    public:
    matrix(int r,int c):rows(r),cols(c){
        mat[rows][cols];
    }
    void setV(int r,int c, T value){
        mat[r][c] = value;
    }
    T getV(int r,int c){
        return mat[r][c];
    }
    

};
int main(){
    cout<<"23K2001 - Muzammil\n\n"<<endl;
    return 0;
}