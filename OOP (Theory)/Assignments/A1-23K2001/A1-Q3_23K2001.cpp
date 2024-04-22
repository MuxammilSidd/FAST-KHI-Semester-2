//23K2001 Q3
#include<iostream>
using namespace std;
class chessPiece{
    private:
    string name,clr;
    char symbol;

    public:
    chessPiece()
    {
        name = "pawn";
        clr = "white";
        symbol = 'p';
    }
    chessPiece(string name, string clr, char symbol)
    {
        this->name = name;
        this->clr = clr;
        this->symbol = symbol;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setColor(string clr)
    {
        this->clr = clr;
    }
    void setSymbol(char symbol)
    {
        this->symbol = symbol;
    }
    string getName()
    {
        return name;
    }
    string getColor()
    {
        return clr;
    }
    char getSymbol()
    {
        return symbol;
    }

};

class chesBoard{
    private:
    chessPiece *chess[8][8];

    public:

    chesBoard()
    {
        int i,j;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            chess[i][j]=nullptr;
        }
        chess[0][0]= new chessPiece("rook","black",'R');
        chess[0][1]= new chessPiece("knight","black",'N');
        chess[0][2]= new chessPiece("bishop","black",'B');
        chess[0][3]= new chessPiece("queen","black",'Q');
        chess[0][4]= new chessPiece("king","black",'K');
        chess[0][5]= new chessPiece("bishop","black",'B');
        chess[0][6]= new chessPiece("knight","black",'N');
        chess[0][7]= new chessPiece("rook","black",'R');

        chess[7][0]=new chessPiece("rook","white",'r');
        chess[7][1]=new chessPiece("knight","white",'n');
        chess[7][2]=new chessPiece("bishop","white",'b');
        chess[7][3]=new chessPiece("queen","white",'q');
        chess[7][4]=new chessPiece("king","white",'k');
        chess[7][5]=new chessPiece("bishop","white",'b');
        chess[7][6]=new chessPiece("knight","white",'n');
        chess[7][7]=new chessPiece("rook","white",'r');

        for(i=0;i<8;i++)
        chess[6][i] = new chessPiece();

        for(i=0;i<8;i++)
        chess[1][i] = new chessPiece("pawn","black",'P');
    }
    ~chesBoard() 
    {
        int i,j;
        for(i=0;i<8;i++)
        {
        for(j=0; j<8;j++) 
        {
            delete chess[i][j];
            }
        }
    }
    void display()
    {
        int i,j;
        cout<<"\ta\tb\tc\td\te\tf\tg\th\t"<<endl;
        for(i=0;i<8;i++)
        {
            cout<<8-i<<"\t";
            for(j=0;j<8;j++)
            {
                if(chess[i][j]==nullptr)
                {
                    cout<<".\t";
                }
                else
                cout<<chess[i][j]->getSymbol()<<"\t";
            }
            cout<<8-i<<endl;
        }
        cout<<"\ta\tb\tc\td\te\tf\tg\th\t"<<endl;
    }
    bool movePiece(string src,string dn)
    {
        int orgR = 8-(src[1]-'0');
        int orgC = ((src[0])-('a'));
        int newR = 8-(dn[1]-'0');
        int newC = ((dn[0])-('a'));

        if (chess[orgR][orgC] == nullptr) 
        {
            cout<<"No piece to move!"<<endl;
            return false;
        }
        if(orgR<0 || orgC<0 || orgR>7 || orgC>7)
        {
            cout<<"Invalid start!"<<endl;
            return false;
        }
        if(newR<0 || newC<0 || newR>7 || newC>7)
        {
            cout<<"Invalid stop!"<<endl;
            return false;
        }

        char sym;
        sym = chess[orgR][orgC]->getSymbol();

        //only first moves can be applied according to the requiement in our assignment
        if(sym=='N')
        {
            if((newC==orgC-1 && newR==orgR+2)||(newC==orgC+2 && newR==orgR+1)||(newC==orgC+1 && newR==orgR+2))
            //cannot go 2left 1down or 2right 1down by the way bcz of 1st move 
            {
                if(chess[newR][newC]==nullptr)
                {
                cout<<"\nMove valid! Black Knight moves from "<<src<<" to "<<dn<<endl;
                chess[newR][newC] = chess[orgR][orgC];
                chess[orgR][orgC] = nullptr;
                return true;
                }
                else
                {
                    cout<<"\nSpot occupied! Move failed"<<endl;
                    return false;
                }
            }
            else
            return false;
        }
        else if(sym=='n')
        {
            if((newC==orgC-1 && newR==orgR-2)||(newC==orgC+2 && newR==orgR-1)||(newC==orgC+1 && newR==orgR-2))
            //cannot go 2left 1up or 2right 1up by the way bcz of 1st move
            {
                if(chess[newR][newC]==nullptr)
                {
                cout<<"\nMove valid! White Knight moves from "<<src<<" to "<<dn<<endl;
                chess[newR][newC] = chess[orgR][orgC];
                chess[orgR][orgC] = nullptr;
                return true;
                }
                else
                {
                    cout<<"\nSpot occupied! Move failed"<<endl;
                    return false;
                }
            }
            else
            return false;
        }
        else if(sym=='P')
        {
            if((newC==orgC && newR==orgR+1)||(newC==orgC && newR==orgR+2))
            {
                if(chess[newR][newC]==nullptr)
                {
                cout<<"\nMove valid! Black Pawn moves from "<<src<<" to "<<dn<<endl;
                chess[newR][newC] = chess[orgR][orgC];
                chess[orgR][orgC] = nullptr;
                return true;
                }
                else
                {
                    cout<<"\nSpot occupied! Move failed"<<endl;
                    return false;
                }
            }
            else
            return false;
        }
        else if(sym=='p')
        {
            if((newC==orgC && newR==orgR-1)||(newC==orgC && newR==orgR-2))
            {
                if(chess[newR][newC]==nullptr)
                {
                cout<<"\nMove valid! White Pawn moves from "<<src<<" to "<<dn<<endl;
                chess[newR][newC] = chess[orgR][orgC];
                chess[orgR][orgC] = nullptr;
                return true;
                }
                else
                {
                    cout<<"\nSpot occupied! Move failed"<<endl;
                    return false;
                }
            }
            else
            return false;
        }
        else
        return false;

    }
};
int main()
{
    cout<<"23K2001 - Muzammil\n"<<endl;
    chesBoard sample;
    sample.display();

    int ch;
    cout<<"\n1. Move knight\n2. Move pawn"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            string before,after;
            cout<<"From: ";
            cin>>before;
            cout<<"To: ";
            cin>>after;
            cout<<"\nChoosed to move a Knight"<<endl;
            if(sample.movePiece(before,after)==true)
            {
            sample.display();
            }
            else
            cout<<"Unsuccessfull!"<<endl;

            break;
        }
        case 2:
        {
            string before,after;
            cout<<"From: ";
            cin>>before;
            cout<<"To: ";
            cin>>after;
            cout<<"\nChoosed to move Pawn"<<endl;
            if(sample.movePiece(before,after)==true)
            {
            sample.display();
            }
            else
            cout<<"Unsuccessfull!"<<endl;

            break;
        }
        default:
        cout<<"\nInvalid input"<<endl;
    }
    return 0;
}