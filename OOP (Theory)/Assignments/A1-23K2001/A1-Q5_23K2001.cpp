//23K2001 Q5
#include<iostream>
#include<string>
using namespace std;
class user;
class restaurant{
    private:
    string name,location;
    string menu[3];
    int prices[3];
    string validCoupons[5];

    static int redeemedCoupons;

    public:
    void displayMenu()
    {
		cout<<"\nItems of "<<getName()<<" restaurant:"<<endl;
		int i;
		for(i=0;i<3;i++)
		{
			cout<<i+1<<". "<<menu[i]<<" for Rs. "<<prices[i]<<endl;
		}
    }
    void generateBill(user u1,string itemsordered[],int qty[],int totalitems);

    void applyDiscount(string couponCode)
    {
        cout<<"Checking for discount..";
        int i,f=0;
        for(i=0;i<5;i++)
        {
        if(couponCode==validCoupons[i])
        {
            cout<<"\nEnjoy our special BOGO discount! You got one serving free."<<endl;
            redeemedCoupons++;
            break;
        }
        else
        f=1;
        }
        if(f)
        cout<<"\nWe are sorry. Try another coupon code next time"<<endl;
    }

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
    	return name;
	}
    void setLoc(string location)
    {
        this->location = location;
    }
    void setMenu(string menu[3])
    {
        int i;
        for(i=0;i<3;i++)
        {
            this->menu[i] = menu[i];
        }
    }
    void setPrices(int prices[3])
    {
        int i;
        for(i=0;i<3;i++)
        {
            this->prices[i] = prices[i];
        }
    }
    void setvalidCoupon(string validCoupons[5])
    {
        int i;
        for(i=0;i<5;i++)
        {
            this->validCoupons[i] = validCoupons[i];
        }
    }
};

int restaurant::redeemedCoupons = 0;

class BOGOcoupon{
    private:
    string code, start, end;
    string restaurantCode;

    public:
    BOGOcoupon()
    {}
    BOGOcoupon(const char code[14],const char start[9],const char end[9],const char restaurantCode[3])
    {
        this->code = code;
        this->restaurantCode = restaurantCode;
        this->start = start;
        this->end = end;
    }
    void setCoupon(string code,string start,string end,string restaurantCode)
    {
        this->code = code;
        this->restaurantCode = restaurantCode;
        this->start = start;
        this->end = end;
    }
    bool is_valid(string today,string code)
    {
        if(code!=restaurantCode)
        return false;

    	int td = stoi(today.substr(0, 2));
        int tm = stoi(today.substr(2, 2));
        int ty = stoi(today.substr(4, 4));
        int ed = stoi(end.substr(0, 2));
        int em=stoi(end.substr(2, 2));
        int ey= stoi(end.substr(4, 4));

        if (ty > ey) 
        {
            return false; 
        } 
        else if (ty < ey) 
        {
            return true; 
        } 
        else if (tm > em) 
        {
            return false;
        } 
        else if (tm < em) 
        {
            return true;
        } 
        else if (td > ed) 
        {
            return false;
        } 
        else 
        {
            return true;
        }
    }
    string getCouponCode()
    {
        return code;
    }
};
class user{
    private:
    string name,m_num;
    int age;
    BOGOcoupon coupons[5];
    string redeemed_coupons_list[5];
    int counter=0;
    int r_counter=0;
    
    public:
    user(string name, string m_num,int age)
    {
        this->name = name;
        this->m_num = m_num;
        this->age=age;
    }
    void accumulateCoupon()
    {
		if(counter<5)
        {
        string code, start, end;
        string restaurantCode;
		cout<<"Input coupon code: "<<endl;
		cin>>code;
        cout<<"Input validity from (ddmmyy): "<<endl;
		cin>>start;
        cout<<"Input expiry (ddmmyy): "<<endl;
		cin>>end;
        cout<<"Input restaurant code: "<<endl;
		cin>>restaurantCode;
        coupons[counter].setCoupon(code,start,end,restaurantCode);
        counter++;
        cout<<"Coupon has been added successfully. User can accumulate "<<5-counter<<" more coupons."<<endl;
        }
        else
        {
            cout<<"\nUser "<<getUname()<<" cannot accumulate more coupons. (Max 5)"<<endl;
        }			
    }
    void hasValid()
    {
        int i,j,f=0;
        string rcode,date;
        cout<<"Input code of restaurant (FH/PB): ";
        cin>>rcode;
        cout<<"Input today's date: ";
        cin>>date;
        cout<<"\nValid coupons: "<<endl;
        for(i=0;i<5;i++)
        {
            if(coupons[i].is_valid(date,rcode))
            {
                if(r_counter==0)
                {
                    cout<<"..No redeemed coupons to check from."<<endl;
                    break;
                }
                else
                {
                    for(j=0;j<r_counter;j++)
                    {
                        if(coupons[i].getCouponCode()!=redeemed_coupons_list[j])
                        {
                            f=1;
                            cout<<coupons[i].getCouponCode()<<endl;
                            break;
                        }
                    }
                }
            }
        }
        if(f==0 && r_counter!=0)
        cout<<"None"<<endl;
    }
    void redeemCoupon()
    {
        int i,x,f=0;
        cout<<"User "<<getUname()<<"'s coupons: "<<endl;
        for(i=0;i<counter;i++)
        {
            cout<<i+1<<". "<<coupons[i].getCouponCode()<<endl;
        }
        cout<<"\nInput which coupon to redeem: ";
        cin>>x;
        string rcode,date;
        cout<<"Input code of restaurant (FH/PB): ";
        cin>>rcode;
        cout<<"Input today's date: ";
        cin>>date;
        cout<<"Checking if it is valid.."<<endl;
        if(coupons[x-1].is_valid(date,rcode))
        {
            for(i=0;i<r_counter;i++)
            {
                if(coupons[x-1].getCouponCode()==redeemed_coupons_list[i])
                f=1;
            }
            if(f==0)
            {
                cout<<"Coupon is valid & unredeemed!"<<endl;
                cout<<"Redeeming this coupon!"<<endl;
                redeemed_coupons_list[r_counter] = coupons[x-1].getCouponCode();
                r_counter++;
                cout<<"Coupon redeemed!"<<endl;
            }
        }
        else
        cout<<"Invalid coupon!"<<endl;
    }
    string getUname()
    {
    	return name;
	}
};


void restaurant:: generateBill(user u1,string itemsordered[],int qty[],int distinctItems)
    {
		cout<<"\nUser "<<u1.getUname()<<"'s bill receipt:"<<endl;
        int i,j;
        int totalAmount = 0;
        int itemIndex;
        for(i=0;i<distinctItems;i++)
        {
            itemIndex=-1;
            for(j=0;j<3;j++)
            {
                if(itemsordered[i]==menu[j])
            {
                itemIndex = j;
                break;
            }
            }
            if (itemIndex != -1) 
            {
            totalAmount += prices[itemIndex] * qty[i];
            } else {
                cout << "Item not found: " << itemsordered[i] << endl;
            }
        }
        cout << "Total bill amount: Rs. " << totalAmount << endl;
    }
int main()
{
    cout<<"23K2001 - Muzammil\n"<<endl;

    restaurant res1;
    restaurant res2;
    res1.setName("Food Haven");
    res2.setName("Pixel Bites");
    res1.setLoc("City Center");
    res2.setLoc("Cyber Street");
    string m1[3] = {"Sushi","Pad Thai","Mango Tango"};
    int p1[3]={800,600,250};
    string m2[3] = {"Binary Burger", "Quantum Quinoa","Data Donuts"};
    int p2[3]={450,300,150};
    res1.setMenu(m1);
    res2.setMenu(m2);
    res1.setPrices(p1);
    res2.setPrices(p2);
    string validcouponsFH[]={"FH-BOGO-12345","FH-BOGO-67890","FH-BOGO-22345","FH-BOGO-22678","FH-BOGO-32345"};
    res1.setvalidCoupon(validcouponsFH);
    string validcouponsPB[]={"PB-BOGO-12345","PB-BOGO-67890","PB-BOGO-22345","PB-BOGO-22678","PB-BOGO-32345"};
    res2.setvalidCoupon(validcouponsPB);
    user customer("Muzammil","+923062234484",18);
    
    BOGOcoupon coupon1("FH-BOGO-12345","01012024","07032024","FH");

    int ch;
    do
    {
        cout<<"\n1. Display menus of both restaurants\n2. Place order & Generate bill\n3. Apply for discount\n4. Check validity of coupon\n5. Accumulate a coupon\n6. Checks if the user has a valid unredeemed coupon\n7. Redeem coupon\n0. Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                res1.displayMenu();
                res2.displayMenu();
                break;
            }
            case 2:
            {
                string itemsordered[] = {"Sushi","Mango Tango"};
                int qty[] = {2,3};
                int distinctItems = 2;
                res1.generateBill(customer,itemsordered,qty,distinctItems);
                break;
            }
            case 3:
            {
                res1.applyDiscount("FH-BOGO-12345");
                break;
            }
            case 4:
            {
                if(coupon1.is_valid("26022024","FH") == true)
                {
                    cout<<"\nThis code is valid for use!"<<endl;
                }
                else
                cout<<"\nThis code is INVALID!"<<endl;
                break;
            }
            case 5:
            {
                customer.accumulateCoupon();
                break;
            }
            case 6:
            {
                customer.hasValid();
                break;
            }
            case 7:
            {
                customer.redeemCoupon();
                break;
            }
        }
    } while(ch!=0);
    return 0;
}