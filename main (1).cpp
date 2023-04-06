#include <iostream>
#include<string.h>
using namespace std;

int count1 = 0;
int count2 = 0;

class blood_bank
{
  public:
  static int bloodgroup[8];  
};

int blood_bank::bloodgroup[]={0,0,0,0,0,0,0,0};

class patient
{
  char name[50];
  //char blood_group1[20];
  //char blood_group2[20];
  int b1;
  int b2;
  int quantity;
  public:
  int save();
  int show(int, int);
  int displayp(); 
};

int patient::displayp()
{
  int x;
  bool flag = false;
  cout << endl<<  "Name: " << name << endl;
  cout<<"Blood group of patient: ";  
  x = b1;
  bloodagain:
  switch(x)
  {
    case 0:
      cout<<"A positive"<<endl;
      break;
    case 1:
      cout<<"O positive"<<endl;
      break;
    case 2:
      cout<<"B positive"<<endl;
      break;
    case 3:
      cout<<"AB positive"<<endl;
      break;
    case 4:
      cout<<"A negative"<<endl;
      break;
    case 5:
      cout<<"O negative"<<endl;
      break;
    case 6:
      cout<<"B negative"<<endl;
      break;
    case 7:
      cout<<"AB negative"<<endl;
    case 8:
      cout<<"NONE"<<endl;
  }
  flag = (!flag);
  if(flag == true)
  {
    x = b2;
    cout<<"Blood group provided: ";
    goto bloodagain;
  }
  cout<<"Packets of blood provided: " << quantity << endl;
  return 0; 
}

int patient::save()
{
  int c,n,q;
  char nm[50];
  cout << "Enter your name: ";
  cin >> name;
  //cin >> nm;
  count2 = count2 +1;
  tryagain:
  cout <<endl<< "Enter the required blood type: " << endl;
  cout << "0 = A positive" << endl << "1 = O positive" << endl << "2 = B positive" << endl << "3 = AB positive" << endl << "4 = A negative" << endl << "5 = O negative" << endl << "6 = B negative" << endl << "7 = AB negative"<<endl << "8 = exit" <<endl;
  cin >> c; 
  if(c== 8)
  {
    return 1;
  }
  cout << "Enter amount required(bags): ";
  cin >> q;
  int x = show(c, q);
  if(x == 10)
  {
    b1 = 8;
    b2 = 8;
    goto tryagain;
  }
  //strcpy(name, nm);
  quantity = q;
  b1 = c;
  b2 = x;
  //count2 = count2 +1;
  return 0;
}

int patient::show(int c, int q)
{
  if(c==0) //A+
  {
    if(blood_bank::bloodgroup[0]>=q){
      blood_bank::bloodgroup[0]= blood_bank::bloodgroup[0]-q;
      cout << q <<" packet of A +ve Blood Available." << endl;
      return 0;}
    else if(blood_bank::bloodgroup[4]>=q){
      blood_bank::bloodgroup[4]=blood_bank::bloodgroup[4]-q;
      cout << q<<" packet of A -ve Blood Available." << endl;
      return 4;}
    else if(blood_bank::bloodgroup[1]>=q){
      blood_bank::bloodgroup[1]= blood_bank::bloodgroup[1]-q;
      cout << q<<" packet of O +ve Blood Available." << endl;
      return 1;}
    else if(blood_bank::bloodgroup[5]>=q){
      blood_bank::bloodgroup[5]= blood_bank::bloodgroup[5]-q;
      cout << q<<" packet of O -ve Blood Available." << endl;
      return 5;}
    else
    {
      cout<<"Compatible Blood Groups/ Quantity required not available."<<endl << endl << "Currently available: "<<endl;  
      cout << "A +ve: " << blood_bank::bloodgroup[0] << endl;
      cout << "A -ve: " << blood_bank::bloodgroup[4] << endl;
      cout << "O +ve: " << blood_bank::bloodgroup[1] << endl;
      cout << "O -ve: " << blood_bank::bloodgroup[5] << endl;
      return 10;
    } 
  }

  else if(c==1) //O+ 
  {
    if(blood_bank::bloodgroup[1]>=q){
      blood_bank::bloodgroup[1]= blood_bank::bloodgroup[1]-q;
      cout << q<<" packet of O +ve Blood Available." << endl;
      return 1;}
    else if(blood_bank::bloodgroup[5]>=q){
      blood_bank::bloodgroup[5]= blood_bank::bloodgroup[5]-q;
      cout << q<<" packet of O -ve Blood Available." << endl;
      return 5;}
    else
    {
      cout<<"Compatible Blood Groups/ Quantity required not available."<<endl << endl << "Currently available: "<<endl ;
      cout << "O +ve: " << blood_bank::bloodgroup[1] << endl;
      cout << "O -ve: " << blood_bank::bloodgroup[5] << endl;
      return 10;
    }  
  }

  else if (c==2) //B+
  {
    if(blood_bank::bloodgroup[2]>=q){
      blood_bank::bloodgroup[2]= blood_bank::bloodgroup[2]-q;
      cout << q<<" packet of B +ve Blood Available." << endl;
      return 2;}
    else if(blood_bank::bloodgroup[6]>=q){
      blood_bank::bloodgroup[6]= blood_bank::bloodgroup[6]-q;
      cout << q<<" packet of B -ve Blood Available." << endl;
      return 6;}
    else if(blood_bank::bloodgroup[1]>=q){
      blood_bank::bloodgroup[1]= blood_bank::bloodgroup[1]-q;
      cout << q<<" packet of O +ve Blood Available." << endl;
      return 1;}
    else if(blood_bank::bloodgroup[5]>=q){
      blood_bank::bloodgroup[5]= blood_bank::bloodgroup[5]-q;
      cout << q<<" packet of O -ve Blood Available." << endl;
      return 5;}
    else
    {
      cout<<"Compatible Blood Groups/ Quantity required not available."<<endl << endl << "Currently available: "<<endl;  
      cout << "B +ve: "<< blood_bank::bloodgroup[2] << endl;
      cout << "B -ve: "<< blood_bank::bloodgroup[6] << endl;
      cout << "O +ve: "<< blood_bank::bloodgroup[1] << endl;
      cout << "O -ve: "<< blood_bank::bloodgroup[5] << endl;
      return 10;
    }
  } 
  else if (c==3) //AB+
  {
    if(blood_bank::bloodgroup[3]>=q){
      blood_bank::bloodgroup[3]= blood_bank::bloodgroup[3]-q;
      cout << q<<" packet of AB +ve Blood Available." << endl;
      return 3;}
    else if(blood_bank::bloodgroup[4]>=q){
      blood_bank::bloodgroup[4]= blood_bank::bloodgroup[4]-q;
      cout << q<<" packet of A -ve Blood Available." << endl;}
    else if(blood_bank::bloodgroup[2]>=q){
      blood_bank::bloodgroup[2]= blood_bank::bloodgroup[2]-q;
      cout << q<<" packet of B +ve Blood Available." << endl;
      return 2;}
    else if(blood_bank::bloodgroup[6]>=q){
      blood_bank::bloodgroup[6]= blood_bank::bloodgroup[6]-q;
      cout << q<<" packet of B -ve Blood Available." << endl;
      return 6;}
    else if(blood_bank::bloodgroup[0]>=q){
      blood_bank::bloodgroup[0]= blood_bank::bloodgroup[0]-q;
      cout << q<<" packet of A +ve Blood Available." << endl;
      return 0;}
    else if(blood_bank::bloodgroup[7]>=q){
      blood_bank::bloodgroup[7]= blood_bank::bloodgroup[7]-q;
      cout << q<<" packet of AB -ve Blood Available." << endl;
      return 7;}
    else if(blood_bank::bloodgroup[1]>=q){
      blood_bank::bloodgroup[1]= blood_bank::bloodgroup[1]-q;
      cout << q<<" packet of O +ve Blood Available." << endl;
      return 1;}
    else if(blood_bank::bloodgroup[5]>=q){
      blood_bank::bloodgroup[5]= blood_bank::bloodgroup[5]-q;
      cout << q<<" packet of O -ve Blood Available." << endl;
      return 5;}
    else
    {
      cout<<"Compatible Blood Groups/ Quantity required not available."<<endl << endl << "Currently available: "<<endl ;  
      cout << "A +ve: " << blood_bank::bloodgroup[0]<<endl;
      cout << "A -ve: " << blood_bank::bloodgroup[4]<<endl;
      cout << "B +ve: " << blood_bank::bloodgroup[2]<<endl;
      cout << "B -ve: " << blood_bank::bloodgroup[6]<<endl;
      cout << "AB +ve: " << blood_bank::bloodgroup[3]<<endl;
      cout << "AB -ve: " << blood_bank::bloodgroup[7]<<endl;
      cout << "O +ve: " << blood_bank::bloodgroup[1]<<endl;
      cout << "O -ve: " << blood_bank::bloodgroup[5]<<endl;
      return 10;
    }
  }
  else if (c==4) //A-
  {
    if(blood_bank::bloodgroup[4]>=q){
      blood_bank::bloodgroup[4]= blood_bank::bloodgroup[4]-q;
      cout << q<<" packet of A -ve Blood Available." << endl;
      return 4;}
    else if(blood_bank::bloodgroup[5]>=q){
      blood_bank::bloodgroup[5]= blood_bank::bloodgroup[5]-q;
      cout << q<<" packet of O -ve Blood Available." << endl;
      return 5;}
    else
    {
      cout<<"Compatible Blood Groups/ Quantity required not available."<<endl << endl << "Currently available: "<<endl ; 
      cout << "A -ve: "<<blood_bank::bloodgroup[4] << endl;
      cout << "O -ve: "<<blood_bank::bloodgroup[5] << endl;
      return 10;
    }    
  }
  else if (c==6) //B-
  {
    if(blood_bank::bloodgroup[6]>=q){
      blood_bank::bloodgroup[6]= blood_bank::bloodgroup[6]-q;
      cout << q<<" packet of B -ve Blood Available." << endl;
      return 6;}
    else if(blood_bank::bloodgroup[5]>=q){
      blood_bank::bloodgroup[5]= blood_bank::bloodgroup[5]-q;
      cout << q<<" packet of O -ve Blood Available." << endl;
      return 5;}
    else
    {
      cout<<"Compatible Blood Groups/ Quantity required not available."<<endl << endl << "Currently available: "<<endl; 
      cout << "B -ve: "<<blood_bank::bloodgroup[6] << endl;
      cout << "O -ve: "<<blood_bank::bloodgroup[5] << endl;
      return 10;
    }
  }
  else if (c==5) //o-
  {
    if(blood_bank::bloodgroup[5]>=q){
      blood_bank::bloodgroup[5]= blood_bank::bloodgroup[5]-q;
      cout << q<<" packet of O -ve Blood Available." << endl;
      return 5;}
    else
    {
      cout<<"Compatible Blood Groups/ Quantity required not available."<<endl << endl << "Currently available: "<<endl;
      cout<<"O -ve: "<<blood_bank::bloodgroup[5]<<endl; 
      return 10;
    }
  } 
  else if(c==7) //AB-
  {
    if(blood_bank::bloodgroup[7]>=q){
      blood_bank::bloodgroup[7]= blood_bank::bloodgroup[7]-q;
      cout << q<<" packet of AB -ve Blood Available." << endl;
      return 7;}
    else if(blood_bank::bloodgroup[6]>=q){
      blood_bank::bloodgroup[6]= blood_bank::bloodgroup[6]-q;
      cout << q<<" packet of B -ve Blood Available." << endl;
      return 6;}
    else if(blood_bank::bloodgroup[5]>=q){
      blood_bank::bloodgroup[5]= blood_bank::bloodgroup[5]-q;
      cout << q<<" packet of O -ve Blood Available." << endl;
      return 5;}
    else if(blood_bank::bloodgroup[4]>=q){
      blood_bank::bloodgroup[4]= blood_bank::bloodgroup[4]-q;
      cout << q<<" packet of A -ve Blood Available." << endl;
      return 4;}
    else
    {
      cout<<"Compatible Blood Groups/ Quantity required not available."<<endl << endl << "Currently available: "<<endl; 
      cout << "A -ve: "<<blood_bank::bloodgroup[4] << endl;
      cout << "B -ve: "<<blood_bank::bloodgroup[6] << endl;
      cout << "O -ve: "<<blood_bank::bloodgroup[5] << endl;
      cout << "AB -ve: "<<blood_bank::bloodgroup[7] << endl;
      return 10;
    }  
  } 
  return 0; 
}

class donor
{
  char name[50];
  char sex[15];
  int age;
  struct date
  {
    int day;
    int month;
    int year;
  }date;
  char blood_group[20];
  //int phone_no[15];
public: 
  int save();
  int display();
  int x,c;
};

int donor::save()
{
  char n[50];
  char s[15];
  int a;
  cout << "Enter name: ";
  cin >> n;
  cout << "Enter sex: ";
  cin >> s;
  cout << "Enter age: ";
  cin >> a;
  if(a > 60 || a < 18)
  {
    cout << endl << "Blood donation is not allowed for the entered age group."<<endl;
    return 0;
  }
  strcpy(name, n);
  strcpy(sex, s);
  age = a;
  cout << "Enter donation date(DD MM YYYY): ";
  cin >> date.day;
  cin >> date.month;
  cin >> date.year;
  cout << "Enter type of blood group you are donating: "<< endl;
  cout << "0 = A positive"<<endl<<"1 = O positive"<< endl << "2 = B positive"<<endl << "3 = AB positive" << endl <<"4 = A negative"<< endl <<"5 = O negative"<< endl << "6 = B negative" << endl << "7 = AB negative"<< endl;
  cin >> c;
  cout << "Enter number of packets that can be donated: ";
  cin >> x;
  blood_bank::bloodgroup[c]+=x;
  char ch;
  count1 = count1 + 1;
  cout << endl <<"Do you want your information to be displayed?(y/n) : ";
  cin>>ch;
  if(ch=='Y'||ch=='y'){
    cout << endl << "Donor Details: "<<endl;
    donor::display();}
  return 0; 
}

int donor::display()
{
  cout << endl<<  "Name: " << name << endl;
  cout << "Age: " << age << endl;
  cout << "Sex: " << sex << endl;
  cout<<"Donation date: ";
  cout<<date.day<<" / ";
  cout<<date.month<<" / ";
  cout<<date.year<<endl;
  cout<<"Blood group: ";  
  switch(c)
  {
    case 0:
      cout<<"A positive"<<endl;
      break;
    case 1:
      cout<<"O positive"<<endl;
      break;
    case 2:
      cout<<"B positive"<<endl;
      break;
    case 3:
      cout<<"AB positive"<<endl;
      break;
    case 4:
      cout<<"A negative"<<endl;
      break;
    case 5:
      cout<<"O negative"<<endl;
      break;
    case 6:
      cout<<"B negative"<<endl;
      break;
    case 7:
      cout<<"AB negative"<<endl;
  }
  cout<<"Packets of blood donated: " << x << endl;
  return 0; 
}

class admin
{   
  char s[20]="SystemPass";
  public:
    void displayb();
    int passcheck()
    {
      char str[20];
      int a;
      cout <<  endl << "Enter password: ";
      cin>>str;
      if(strcmp(s,str)==0)
        return 1;
      else
        return 2;
    }
};

void admin::displayb()
{
  cout << endl << "Blood Curently Available: " << endl;
  cout << "A +ve:  " << blood_bank::bloodgroup[0] << endl;
  cout << "O +ve:  " << blood_bank::bloodgroup[1] << endl;
  cout << "B +ve:  " << blood_bank::bloodgroup[2] << endl;
  cout << "AB +ve: " << blood_bank::bloodgroup[3] <<endl;
  cout << "A -ve:  " << blood_bank::bloodgroup[4] << endl;
  cout << "O -ve:  " << blood_bank::bloodgroup[5] << endl;
  cout << "B -ve:  " << blood_bank::bloodgroup[6] << endl;
  cout << "AB -ve: " << blood_bank::bloodgroup[7] <<endl << endl;
}

int main()
{
  int i=0,j=0;
  donor a[100];
  patient b[50];
  int choice =0;
  cout<< endl << "Welcome to Blood Donation System!" <<endl; 
  while(choice!=4)
  {  
    cout << endl << "Enter: " << endl << "1: Admin Access\n2: For Donor\n3: For Patient\n4: Exit" << endl;
    cin >> choice;
    switch(choice)
    {         
      case 1:
      {
        int u;
        admin t;
        if(t.passcheck() == 1)
        {
          cout << endl << "Welcome!" << endl;
          u = 0;
          while(u != 4)
          {
            cout << endl << "Enter: " << endl << "1: Blood Inventory" <<endl << "2: Donor List" << endl << "3: Patient List" << endl << "4: Exit Admin Access" << endl; 
            cin >> u; 
            switch(u)
            {
              case 1:
              {
                t.displayb();
                break;
              }
              case 2:
              {
                int i =0;
                cout << endl << "Donor Details: "<<endl;
                for(i=0; i < count1; i++)
                {
                  a[i].display();
                }
                cout <<endl;
                break;
              }
              case 3:
              {
                int i =0;
                cout << endl << "Patient Details: "<<endl;
                for(i=0; i < count2; i++)
                {
                  b[i].displayp();
                }
                cout <<endl;
                break;
              }
              case 4:
              break;
            }
          //u=0;
          }
         }
        else
        {
          cout<<"Please contact helpdesk to become an Admin"<<endl;
        }
        char c;
        break;
      }     
      case 2:
      {
        int k;
        static int i=0;
        cout << endl << "Welcome Donor!" << endl;
        cout <<endl<< "Please enter the required details: " << endl;
        a[i++].save();  
        break;
      }  
      case 3:
      {
        static int i=0;
        cout << endl << "Welcome Patient!"<<endl;
        if(b[i++].save()==1)
        {
          cout << endl << "Back to main menu"<<endl;
        }
        break;
      }
      case 4:
      break;
      default:
      {
        cout << endl << "Invalid Choice"<< endl;
        break;
      }
    }
  }
  return 0;
}