#include<iostream>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<istream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int id,lo=0,TDB=0;

void firstpage();
void end_fare_bet_sta();
void end_station_status();
void end_seat_ava();
void end_book_ticket();


class train
{
    long int train_no,stat[4],ho[4],mi[4],dist[3],seat[3];
public:
    long int ret_train_no()
    {
        return train_no;
    }
    long int ret_sta(int i=0)
    {
        return stat[i];
    }
    long int ret_ho(int i=0)
    {
        return ho[i];
    }
    long int ret_mi(int i=0)
    {
        return mi[i];
    }
    long int ret_dist(int i=0)
    {
        return dist[i];
    }
    long int ret_seat(int i=0)
    {
        return seat[i];
    }
    void input_train_no(long int a)
    {
        train_no=a;
    }
    void input_stat(long int a,int i)
    {
        stat[i]=a;
    }
      void input_ho(long int a,int i)
    {
        ho[i]=a;
    }
      void input_mi(long int a,int i)
    {
        mi[i]=a;
    }
      void input_dist(long int a,int i)
    {
        dist[i]=a;
    }
       void input_seat(long int a,int i)
    {
        seat[i]=a;
    }
    friend string train_id_to_name(int i);
    friend string station_id_to_name(int i);
   friend long int station_name_to_id(string s);
  /* void input()
   {
       system("cls");
       train T;
       int i;
       cout<<"train no";
       cin>>T.train_no;
       cout<<"station";
       for(i=0;i<4;i++)
       {
           cin>>T.stat[i];
       }
       cout<<"hours";
       for(i=0;i<4;i++)
       {
           cin>>T.ho[i];
       }
       cout<<"mi";
       for(i=0;i<4;i++)
       {
           cin>>T.mi[i];
       }
       cout<<"dist";
       for(i=0;i<3;i++)
       {
           cin>>T.dist[i];
       }
       cout<<"seat";
       for(i=0;i<3;i++)
       {
           cin>>T.seat[i];
       }
       ofstream tick;
                tick.open("train_db.txt",ios::app);
                tick.write((char*)&T, sizeof(T));
                tick.close();
   }*/
};
/*void station_status()
{
    train t;
    t.input();
    system("pause");
    system("cls");
    firstpage();
}*/

long int station_name_to_id(string s)
{
    if(s=="jabalpur" || s=="Jabalpur" || s=="JABALPUR")
        return 1;
    else if(s=="kota" || s=="Kota" || s=="KOTA")
        return 2;
    else if(s=="kolkata" || s=="Kolkata" || s=="KOLKATA")
        return 3;
    else if(s=="kanpur" || s=="Kanpur" || s=="KANPUR")
    return 4;
    else if(s=="delhi" || s=="Delhi" || s=="DELHI")
        return 5;
    else
        return -1;
}
string train_id_to_name(int i)
{
    string s;
    if(i==1)
    {
        s="abc";
        return s;
    }
    else if(i==2)
    {
        s="def";
        return s;
    }
    else if(i==3)
    {
        s="ghi";
        return s;
    }
    else if(i==4)
    {
        s="jkl";
        return s;
    }
    else if(i==5)
    {
        s="mno";
        return s;
    }
}
string station_id_to_name(int i)
{
    string s;
    if(i==1)
    {
        s="jabalpur";
        return s;
    }
     if(i==2)
    {
        s="kota";
        return s;
    }
     if(i==3)
    {
        s="kolkata";
        return s;
    }
     if(i==4)
    {
        s="kanpur";
        return s;
    }
     if(i==5)
    {
        s="delhi";
        return s;
    }
}
class ticket
{
    string name[6],age[6],phno;
    int Y,s[2],tr_no;
public:
    void input(int n)
    {
        int i,a;
        string d;
        system("cls");
        for(i=0;i<n;i++)
        {
            cout<<"name:";
            cin>>d;
            name[i]=d;
            cout<<"age:";
            cin>>d;
            age[i]=d;
        }
        for(i=n;i<6;i++)
        {
            name[i]="99";
            age[i]="99";

        }
        cout<<"phone number:";
        cin>>d;
        phno=d;
        system("cls");
        Y=id;
    }
    int ret_tick_id()
    {
        return Y;
    }
    string ret_name(int a)
    {
        return name[a];
    }
    string ret_age(int a)
    {
        return age[a];
    }
    string ret_phno()
    {
        return phno;
    }
     void input_train_no(int a)
     {
         tr_no=a;
     }
    void input_station(int a,int b)
         {
             s[0]=a;
             s[1]=b;
         }
    int ret_tr_no()
    {
        return tr_no;
    }
    int ret_from()
    {
        return s[0];
    }
    int ret_to()
    {
        return s[1];
    }
     friend string train_id_to_name(int i);
    friend string station_id_to_name(int i);
    friend long int station_name_to_id(string s);
};

void book_ticket()
{
    system("cls");
    cout<<"BOOK TICKETS:-"<<endl<<endl;
    int a,from,to,fr,tt,n,j;
    char z;
    string name[6],age[6],phno;
    char fname1[13],fname2[14];
    train t;
    if(1)
    {
        system("cls");
        cout<<"Enter Train No:";
        cin>>a;
        system("cls");
        ifstream train_obj;
        FILE* fp= fopen("train2_db.txt","r");
        long fsize = 0;
        if(fp)
        {
            fseek (fp, 0, SEEK_END);
            fsize = ftell(fp);
        }
        if(fsize==0)
        {
            train_obj.open("train_db.txt",ios::in);
            TDB=0;

        }

        else{
        train_obj.open("train2_db.txt",ios::in);
        TDB=1;

        }
         fclose(fp);
        train t;
        train_obj.read((char*)&t, sizeof(t));

        while (!train_obj.eof())
        {
            if (t.ret_train_no()==a)
            {
                int i;
               cout<<"TRAIN NO:"<<t.ret_train_no()<<" "<<"TRAIN NAME: "<<train_id_to_name(t.ret_train_no())<<endl;
               for(i=0;i<4;i++)
                {
                    cout<<i+1<<". "<<station_id_to_name(t.ret_sta(i))<<" "<<"time:"<<t.ret_ho(i)<<":"<<t.ret_mi(i)<<endl;
                    if(i<3)
                    {
                        cout<<"|"<<endl;
                        cout<<t.ret_dist(i)<<"km"<<endl;
                        cout<<"|"<<endl;
                    }
                }
                cout<<endl<<endl<<"FROM: ";
                cin>>from;
                cout<<"TO: ";
                cin>>to;
                if(from>0 && to<6 && from <to)
                {

                    train_obj.close();
                    do{
                    system("cls");
                    cout<<"no of people(less than 6):";
                    cin>>n;
                    }while(n>6 || n<1);
                    int fg=0,tic=0;
                    for(i=from-1;i<to-1;i++)
                    {
                        tic=t.ret_dist(i);
                        if(n<=tic)
                            fg=1;
                        else
                            fg=0;
                    }
                    if(fg==1)
                    {
                        ticket TT;
                        TT.input(n);
                        TT.input_train_no(t.ret_train_no());
                        TT.input_station(t.ret_sta(from-1),t.ret_sta(to-1));
O:                        cout<<"are sure you want to book the tickets.(y/n)"<<endl;
                        cin>>z;
                        if(z=='y' || z=='Y')
                        {
                             ofstream tick;
                             tick.open("ticket_db.txt",ios::binary|ios::app);
                             tick.write((char*)&TT, sizeof(TT));
                             tick.close();
                            system("cls");
                            if(TDB==0)
                            {
                                ifstream f1;
                                f1.open("train_db.txt",ios::in);
                                train t;
                                 f1.read((char*)&t, sizeof(t));
                                  ofstream f2;
                                f2.open("train2_db.txt",ios::app);
                                train tt;

                                while (!f1.eof())
                                {
                                    if (t.ret_train_no()!=a)
                                    {
                                      tt=t;
                                      f2.write((char*)&tt, sizeof(tt));
                                    }
                                    else
                                    {
                                        tt.input_train_no(t.ret_train_no());
                                        for(i=0;i<4;i++)
                                        {
                                            tt.input_stat(t.ret_sta(i),i);
                                            tt.input_ho(t.ret_ho(i),i);
                                            tt.input_mi(t.ret_mi(i),i);
                                            tt.input_dist(t.ret_dist(i),i);
                                        }
                                        for(i=0;i<from-1;i++)
                                        {
                                            tt.input_seat(t.ret_seat(i),i);
                                        }
                                        for(i=from-1;i<to-1;i++)
                                        {
                                            tt.input_seat(t.ret_seat(i)-n,i);
                                        }
                                        for(i=to-1;i<6;i++)
                                        {
                                            tt.input_seat(t.ret_seat(i),i);
                                        }
                                        f2.write((char*)&tt, sizeof(tt));
                                    }
                                    f1.read((char*)&t, sizeof(t));
                                }


                                f1.close();
                                f2.close();
                            ofstream ofs;
                            ofs.open("train_db.txt",ios::out| ios::trunc);
                            ofs.close();

                            }
                            else
                            {
                                 ofstream f1;
                                f1.open("train_db.txt",ios::app);
                                train t;
                                  ifstream f2;
                                f2.open("train2_db.txt",ios::in);
                                train tt;
                                f2.read((char*)&tt, sizeof(tt));
                                while (!f2.eof())
                                {
                                    if (tt.ret_train_no()!=a)
                                    {
                                      t=tt;
                                      f1.write((char*)&t, sizeof(t));
                                    }
                                    else
                                    {
                                        t.input_train_no(tt.ret_train_no());
                                        for(i=0;i<4;i++)
                                        {
                                            t.input_stat(tt.ret_sta(i),i);
                                            t.input_ho(tt.ret_ho(i),i);
                                            t.input_mi(tt.ret_mi(i),i);
                                            t.input_dist(tt.ret_dist(i),i);
                                        }
                                        for(i=0;i<from-1;i++)
                                        {
                                            t.input_seat(tt.ret_seat(i),i);
                                        }
                                        for(i=from-1;i<to-1;i++)
                                        {
                                            t.input_seat(tt.ret_seat(i)-n,i);
                                        }
                                        for(i=to-1;i<6;i++)
                                        {
                                            t.input_seat(tt.ret_seat(i),i);
                                        }
                                        f1.write((char*)&t, sizeof(t));
                                    }
                                    f2.read((char*)&tt, sizeof(tt));
                                }

                                f2.close();
                                f1.close();
                                 ofstream ofs;
                            ofs.open("train2_db.txt",ios::out| ios::trunc);
                            ofs.close();

                            }
                            cout<<"your ticket is booked"<<endl;
                            end_book_ticket();
                        }
                        else if(z=='n' || z=='N')
                        {
                            cout<<"your ticket is not booked";
                            end_book_ticket();
                        }
                        else
                        {
                            cout<<"invlaid input";
                            system("cls");
                            goto O;
                        }
                    }
                    else
                    {
                        cout<<"seats not available";
                        end_book_ticket();
                    }
                }
                else
                {
                    cout<<"invalid input";
                    end_book_ticket();
                }
                 break;
            }
            train_obj.read((char*)&t, sizeof(t));
        }
        train_obj.close();
        end_book_ticket();
    }

}
void end_book_ticket()
{
       char w;
                system("pause");
            system("cls");
V:          cout<<"1. HOME PAGE"<<endl<<"2. BOOK TICKET"<<endl;
            cin>>w;
            if(w=='1')
            {
                system("cls");
                firstpage();
            }
            else if(w=='2')
            {
                system("cls");
                 book_ticket();
            }
           else
           {
              system("cls");
              cout<<"Invalid Input ."<<endl;
              system("pause");
              fflush(stdin);
               system("cls");
              goto V;
           }
}
void station_status()
{
   long int a;
    char w;
     ifstream f1;
     FILE* fp= fopen("train2_db.txt","r");
        long fsize = 0;
        if(fp)
        {
            fseek (fp, 0, SEEK_END);
            fsize = ftell(fp);
        }
        if(fsize==0)
        {
            f1.open("train_db.txt",ios::in);
        }
        else
        {
            f1.open("train2_db.txt",ios::in);
        }
         fclose(fp);
        train d;
        f1.read((char*)&d, sizeof(d));
        string s;
        system("cls");
        cout<<"Enter station name: ";
        fflush(stdin);
        cin>>s;
        a=station_name_to_id(s);
        if(a==-1)
        {
            cout<<"Station not found."<<endl;
            end_station_status();
        }
        else
        {
            int j=0,i=0,fl=0;
            while (!f1.eof())
            {

                for(i=0;i<4;i++)
                {
                    if (d.ret_sta(i)==a)
                    {
                        j++;
                        if(fl==0)
                        {
                            cout<<"STATION NAME:"<<station_id_to_name(a)<<endl;
                            fl=1;
                        }
                            cout<<j<<". "<<"TRAIN NO:"<<d.ret_train_no()<<" "<<"TRAIN NAME:"<<train_id_to_name(d.ret_train_no())<<" "<<"TIME: "<<d.ret_ho(i)<<":"<<d.ret_mi(i)<<endl<<endl;
                            break;
                    }
                }
             f1.read((char*)&d, sizeof(d));
            }
            f1.close();
            end_station_status();
}
}
void end_station_status()
{
    char w;
                system("pause");
            system("cls");
V:          cout<<"1. HOME PAGE"<<endl<<"2. STATION STATUS"<<endl;
            cin>>w;
            if(w=='1')
            {
                system("cls");
                firstpage();
            }
            else if(w=='2')
            {
                system("cls");
                 station_status();
            }
           else
           {
              system("cls");
              cout<<"Invalid Input ."<<endl;
              system("pause");
              fflush(stdin);
               system("cls");
              goto V;
           }
}
void fare_bet_sta()
{
    int a,flag=0,i,p,q,tt=0,f=0,j,k,s=0;
    string from,to;
    system("cls");
    cout<<"enter train no:";
    cin>>a;
    fflush(stdin);
    system("cls");
    ifstream train_obj;
    FILE* fp= fopen("train2_db.txt","r");
        long fsize = 0;
        if(fp)
        {
            fseek (fp, 0, SEEK_END);
            fsize = ftell(fp);
        }
        if(fsize==0)
        {
            train_obj.open("train_db.txt",ios::in);
        }

        else{
        train_obj.open("train2_db.txt",ios::in);
        }
         fclose(fp);
    train t;
    train_obj.read((char*)&t, sizeof(t));
      while (!train_obj.eof())
        {
            if (t.ret_train_no()==a)
            {
                flag=1;
                cout<<"FROM: ";
                cin>>from;
                cout<<"TO: ";
                cin>>to;
                 p=station_name_to_id(from);
                  q=station_name_to_id(to);
                for(i=0;i<4;i++)
                {
                       if (t.ret_sta(i)==p)
                       {
                           f=1;
                           j=i;
                       }
                       if(t.ret_sta(i)==q)
                       {
                           tt=1;
                           k=i;
                       }
                }
                if(f==1 && tt==1)
                {
                    if(j<k)
                    {
                        for(i=j;i<k;i++)
                        {
                            s+=t.ret_dist(i);
                        }
                        cout<<"Rs "<<s*25<<endl;
                        end_fare_bet_sta();
                    }
                    else
                    {
                        cout<<"train does not go that way."<<endl;
                        end_fare_bet_sta();

                    }
                }
                else
                {
                   cout<<"train does not go that way."<<endl;
                   end_fare_bet_sta();
                }
            }
              train_obj.read((char*)&t, sizeof(t));
        }
        if(flag==0)
        {
            cout<<"train not found."<<endl;
            train_obj.close();
            end_fare_bet_sta();
        }
}
void end_fare_bet_sta()
{
               system("pause");
                        system("cls");
B:                      cout<<"1. HOME PAGE"<<endl<<"2. FARE BETWEEN STATION"<<endl;
                        char a;
                        cin>>a;
                        if(a=='1')
                        {
                            system("cls");
                            firstpage();
                        }
                        else if(a=='2')
                        {
                            system("cls");
                            fare_bet_sta();
                        }
                        else
                        {
                            system("cls");
                            cout<<"INVALID INPUT."<<endl;
                            system("pause");
                            fflush(stdin);
                             system("cls");
                             goto B;
                        }
}
void seat_ava()
{
    int a,i,flag=0;
    system("cls");
    cout<<"enter train no: ";
    cin>>a;
    ifstream train_obj;
  FILE* fp= fopen("train2_db.txt","r");
        long fsize = 0;
        if(fp)
        {
            fseek (fp, 0, SEEK_END);
            fsize = ftell(fp);
        }
        if(fsize==0)
        {
            train_obj.open("train_db.txt",ios::in);
        }

        else{
        train_obj.open("train2_db.txt",ios::in);
        }
         fclose(fp);
    train t;
    train_obj.read((char*)&t, sizeof(t));
    while (!train_obj.eof())
    {
        if(a==t.ret_train_no())
        {
            cout<<"TRAIN NO: "<<t.ret_train_no()<<"   TRAIN NAME: "<<train_id_to_name(t.ret_train_no())<<endl;
            for(i=0;i<3;i++)
            {
                cout<<"FROM: "<<station_id_to_name(t.ret_sta(i))<<"  TO: "<<station_id_to_name(t.ret_sta(i+1))<<"   Seat available:"<<t.ret_seat(i)<<endl<<endl;
            }
            flag=1;
            break;
        }
        train_obj.read((char*)&t, sizeof(t));
    }
    if(flag==0)
    {
        system("cls");
        cout<<"Train not found"<<endl;
    }
    end_seat_ava();
}
void end_seat_ava()
{
                        system("pause");
                        system("cls");
D:                      cout<<"1. HOME PAGE"<<endl<<"2. SEAT AVAILABILITY"<<endl;
                        char a;
                        cin>>a;
                        if(a=='1')
                        {
                            system("cls");
                            firstpage();
                        }
                        else if(a=='2')
                        {
                            system("cls");
                            seat_ava();
                        }
                        else
                        {
                            system("cls");
                            cout<<"INVALID INPUT."<<endl;
                            system("pause");
                            fflush(stdin);
                             system("cls");
                             goto D;
                        }
}

void my_tickets()
{
    int flag=0;
    ifstream tik;
     FILE* fp= fopen("ticket_db.txt","r");
        long fsize = 0;
        if(fp)
        {
            fseek (fp, 0, SEEK_END);
            fsize = ftell(fp);
        }
        if(fsize==0)
        {
            cout<<"NO TICKET"<<endl;
        }

        else{
        tik.open("ticket_db.txt",ios::binary|ios::in);
         fclose(fp);
     ticket TT;
     int j=0;
        tik.read((char*)&TT, sizeof(TT));
        while(!tik.eof())
        {
            if(id==TT.ret_tick_id())
            {
                    cout<<"Train no: "<<TT.ret_tr_no()<<" Train name: "<<train_id_to_name(TT.ret_tr_no())<<" FROM: "<<station_id_to_name(TT.ret_from())<<" TO: "<<station_id_to_name(TT.ret_to())<<endl;
                    cout<<"name of passenger\t"<<"age\t"<<"status"<<endl;

                for(j=0;j<6;j++)
                {
                    if(TT.ret_name(j)!="99")
                    {
                        cout<<TT.ret_name(j)<<"\t"<<TT.ret_age(j)<<"\t"<<TT.ret_phno()<<endl;
                    }
                    else
                        break;
                }
                cout<<endl<<endl;
                flag=1;
            }
             tik.read((char*)&TT, sizeof(TT));
        }
        }
        tik.close();

        system("pause");
        system("cls");
        firstpage();
}

void regist()
{
    string username,password,u,p;
    int d,P;
      system("cls");
    cout<<"REGISTER :-"<<endl<<endl;
    cout<<"Select a Username:"; cin>>username;
     ifstream input("logi_db.dat",ios::binary);
     while(input>>u>>p>>d)
    {
        if(u== username)
        {
            cout<<"username exist"<<endl;
            system("pause");
            system("cls");
 L:           cout<<"1. HOME PAGE"<<endl<<"2. REGISTER"<<endl;
            cin>>d;
            if(d==1)
            {
                system("cls");
                firstpage();
            }
            else if(d==2)
            {
                 system("cls");
                regist();
            }
            else
            {
                cout<<"invalid input";
                system("pause");
                system("cls");
                goto L;
            }
        }
     }
     cout<<"Select a Password:"; cin>>password;
      P=rand();
    ofstream file("logi_db.dat",ios::binary|ios::app);
    file<<username<<" "<<password<<" "<<P<<" ";
    file.close();
    cout<<"You have been registered";
    cout<<endl<<endl;
    system("pause");
    system("cls");
    firstpage();
}
void login()
{
    string username ,password,u,p;
    int d;
    system("cls");
    cout<<"LOGIN :-"<<endl<<endl;
    cout<<"Enter a Username:"; cin>>username;
    cout<<"Enter Password:"; cin>>password;
int flag=0;
    ifstream input("logi_db.dat",ios::binary);
    while(input>>u>>p>>d){
     if(p == password && u== username)
     {
         id=d;
         lo=1;
         flag=1;
     }
    }
    input.close();
    if(flag == 1)
    {
        cout<<"Successfully Logged In"<<endl;
        system("pause");
        system("cls");
          firstpage();
    }
    else
    {
         cout<<"False Login!"<<endl;
              system("pause");
         system("cls");
           firstpage();
    }
}
void logout()
{
    id=0;
    lo=0;
    system("cls");
    cout<<"LOGGED OUT"<<endl;
    system("pause");
    system("cls");
    firstpage();
}

void firstpage()
{
    cout<<"                                                      ________ WELECOME TO PIPED PIPERS E-TICKET RESERVATION _______              "<<endl;
		cout<<"                                      _________________________                                              ______________________________";
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
    cout<<"Enter your choice below:"<<endl<<endl;
   if(lo==0)
    {
        for(int j=0;j<150;j++)
        cout<<" ";
        cout<<"8. REGISTER"<<endl;
    }
    if(lo==0)
    {
        for(int j=0;j<150;j++)
        cout<<" ";
        cout<<"9. LOGIN"<<endl<<endl;
    }
    else
    {
         for(int j=0;j<150;j++)
         cout<<" ";
         cout<<"9. LOGOUT"<<endl<<endl;
    }
    cout<<"1. Book Ticket"<<endl;
    cout<<"2. Seat Availability"<<endl;
    cout<<"3. Fare Between Stations"<<endl;
    cout<<"4. Station Status"<<endl;

    if(lo==1)
        cout<<"5. My Tickets"<<endl;
     char i;
      cin>>i;

    if(i=='8' && lo==0)
    {
        regist();
    }
    else if(i=='1' && lo==1)
    {
       book_ticket();
    }
    else if(i=='1' && lo==0)
    {
        cout<<"login first"<<endl;
        system("pause");
        system("cls");
        firstpage();
    }
    else if(i=='2')
    {
        seat_ava();
    }
    else if(i=='3')
    {
        fare_bet_sta();
    }
    else if(i=='4')
    {
       station_status();
    }
    else if(i=='9' && lo==0)
    {
        login();
    }
    else if(i=='9' && lo==1)
    {
        char a;
        cout<<endl<<"Are you sure you want to logout"<<endl;
        cout<<"If 'YES' enter Y  else enter N"<<endl;
        cin>>a;
        if(a=='Y' || a=='y')
        logout();
        else
        {
            system("cls");
            firstpage();
        }
    }
    else if(lo==1 && i=='5')
    {
        my_tickets();
    }
    else
    {
        system("cls");
        cout<<"Invalid Input"<<endl;
        system("pause");
        system("cls");
     firstpage();
    }
}


int main()
{
    srand(time(NULL));
   firstpage();
}

