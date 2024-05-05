//23K2001 Muzammil Q3
#include<iostream>
using namespace std;
template<class T> class matrix{
    protected:
    int rows,cols;
    T **mat=nullptr;

    public:
    matrix(int r,int c):rows(r),cols(c){
        mat = new T*[rows];
        for(int i=0;i<rows;i++){
            mat[i] = new T[cols];
            for(int j=0;j<cols;j++)
            mat[i][j] = 0;
        }
    }
    matrix(const matrix &m){
        rows = m.getRows();
        cols = m.getCols();
        mat = new T*[rows];
        for(int i=0;i<rows;i++){
            mat[i] = new T[cols];
            for(int j=0;j<cols;j++)
            mat[i][j] = m.getV(i,j);
        }
    }

    void setV(int r,int c, T value){ mat[r][c] = value; }
    T getV(int r,int c) const { return mat[r][c]; }
    int getRows() const { return rows; }
    int getCols() const { return cols; }

    matrix operator +(matrix &m1) const {
        if(this->rows==m1.getRows() && this->cols==m1.getCols()){
            matrix sum(this->getRows(),this->getCols());
            for(int i=0;i<this->getRows();i++){
                for(int j=0;j<this->getCols();j++){
                    sum.setV(i,j,this->getV(i,j)+m1.getV(i,j));
                }
            }
            return sum;
        }
        else{
        cout<<"\nSorry cannot add! (Different orders)"<<endl;
        return matrix(0,0);
        }
    }
    matrix operator -(matrix &m1) const {
        if(this->rows==m1.getRows() && this->cols==m1.getCols()){
            matrix sub(this->getRows(),this->getCols());
            for(int i=0;i<this->rows;i++){
                for(int j=0;j<this->cols;j++)
                    sub.setV(i,j,this->getV(i,j)-m1.getV(i,j));
            }
            return sub;
        }
        else{
        cout<<"\nSorry cannot subtract! (Different orders)"<<endl;   
        return matrix(0,0);
        }
    }
    matrix operator *(matrix& m1) const {
        if(this->cols==m1.getRows()){
            matrix prod(this->rows,m1.getCols());
            for(int i=0;i<this->rows;i++){
                for(int j=0;j<prod.getCols();j++){
                    for(int x=0;x<this->cols;x++)
                        prod.setV(i,j,prod.getV(i,j)+(this->getV(i,x)*m1.getV(x,j)));
                }     
            }
            return prod;
        }
        else{
        cout<<"\nSorry cannot multiply! (Orders not compatible)"<<endl;
        return matrix(0,0);
        }
    }
    
    virtual void show(){ // cannot make pure virtual as operator overloadings won't work
            if(getRows()==0 && getCols()==0)
        cout<<"error displaying matrix"<<endl;
        else{
                for(int i=0;i<rows;i++){
                    for(int j=0;j<cols;j++)
                        cout<<mat[i][j]<<" ";
                    cout<<endl;
                }
            }
        }   

    ~matrix(){
        for(int i=0;i<rows;i++)
        delete[] mat[i];

        delete[] mat;
    }
};

class matrixInt : public matrix<int>{
public:
matrixInt(int r,int c):matrix(r,c){}
matrixInt(const matrix &m): matrix(m){
        rows = m.getRows();
        cols = m.getCols();
        mat = new int*[rows];
        for(int i=0;i<rows;i++){
            mat[i] = new int[cols];
            for(int j=0;j<cols;j++)
            mat[i][j] = m.getV(i,j);
        }
    }
void show(){
    if(getRows()==0 && getCols()==0)
    cout<<"error displaying matrix"<<endl;
    else{
        cout<<"----------INT Matrix----------"<<endl;
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++)
                    cout<<mat[i][j]<<" ";
                cout<<endl;
            }
        }
    }
};

class matrixDouble : public matrix<double>{
public: 
matrixDouble(int r,int c):matrix(r,c){}
matrixDouble(const matrix &m): matrix(m){
        rows = m.getRows();
        cols = m.getCols();
        mat = new double*[rows];
        for(int i=0;i<rows;i++){
            mat[i] = new double[cols];
            for(int j=0;j<cols;j++)
            mat[i][j] = m.getV(i,j);
        }
    }
void show(){
    if(getRows()==0 && getCols()==0)
    cout<<"error displaying matrix"<<endl;
    else{
        cout<<"----------DOUBLE Matrix----------"<<endl;
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++)
                    cout<<mat[i][j]<<" ";
                cout<<endl;
            }
        }
    }
};

int main(){
    cout<<"23K2001 - Muzammil\n\n"<<endl;
    matrixInt A(1,2);
    matrixInt B(1,2);
    
    A.setV(0,0,16);
    A.setV(0,1,22);
    B.setV(0,0,14);
    B.setV(0,1,42); 

    cout<<"Matrice A: "<<endl;
    A.show();
    cout<<endl<<"Matrice B: "<<endl;
    B.show();

    matrixInt C = A+B;
    cout<<endl<<"Matrice C (A+B): "<<endl;
    C.show();

    matrixInt D = C-A;
    cout<<endl<<"Matrice D (C-A): "<<endl;
    D.show();

    matrixInt E(2,1);
    matrixInt F(1,2);
    E.setV(0,0,10);
    E.setV(1,0,15);
    F.setV(0,0,2);
    F.setV(0,1,6);

    matrixInt G = E*F;
    cout<<endl<<"Matrice E: "<<endl;
    E.show();
    cout<<endl<<"Matrice F: "<<endl;
    F.show();
    cout<<endl<<"Matrice G (E*F): "<<endl;
    G.show();

    matrixDouble M(2,2);
    matrixDouble N(2,2);
    M.setV(0,0,1.5);
    M.setV(0,1,3.9);
    M.setV(1,0,4.25);
    M.setV(1,1,10.8);

    N.setV(0,0,2.5);
    N.setV(0,1,0.3);
    N.setV(1,0,4.5);
    N.setV(1,1,9.11);

    cout<<endl<<"Matrice M: "<<endl;
    M.show();
    cout<<endl<<"Matrice N: "<<endl;
    N.show();

    matrixDouble X = M+N;
    cout<<endl<<"Matrice X (M+N): "<<endl;
    X.show();

    matrixDouble Y = X-M;
    cout<<endl<<"Matrice Y (X-M): "<<endl;
    Y.show();

    matrixDouble Z = M*N;
    cout<<endl<<"Matrice X (M*N): "<<endl;
    Z.show();

    matrixInt o1(1,2);
    matrixInt o2(1,2);
    o1.setV(0,0,1);
    o1.setV(0,1,2);
    o2.setV(0,0,3);
    o2.setV(0,1,4);

    cout<<endl<<"Matrice o1: "<<endl;
    o1.show();
    cout<<endl<<"Matrice o2: "<<endl;
    o2.show();
    
    cout<<endl<<"Matrix ANS (o1*o2):"<<endl;
    matrixInt ans = o1*o2;
    ans.show();
    return 0;
}