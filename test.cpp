#include<iostream>
#include<fstream>
#include<string.h>
#include<Windows.h>
using namespace std;

class Book
{
    char name[25];
    char author[25];
    int Id;
    int price;

    public:
    Book()
    {
       /* name="No Title";
        author="Anonymous";
        Id=0;
        price=0;*/
    }
    void showData();
    void getData();
    bool storeData();
    void viewAllBook();
    void searchBook(char[]);
};


bool Book::storeData()
{
    ofstream fout;
    if(fout)
     {
        fout.open("Mybook.txt",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        return true;
     }
     else
     {
         return false;
     }

}

void Book::getData()
{
    cout<<"Enter Book Name"<<endl;
    gets(name);
    cout<<"Enter Book's author name"<<endl;
    gets(author);
    cout<<"Enter Book Id"<<endl;
    cin>>Id;
    cout<<"Enter Book price"<<endl;
    cin.ignore();
    cin>>price;
}

void Book::showData()
{
    cout<<"Book Name     : "<<name<<endl;
    cout<<"book Author   : "<<author<<endl;
    cout<<"Book ID       : "<<Id<<endl;
    cout<<"Book price    : "<<price<<endl<<endl<<endl;
}

void Book::viewAllBook()
{
    ifstream fin;
    system("CLS");
    fin.open("Mybook.txt",ios::in|ios::binary);

    if(!fin)
    cout<<"File Error"<<endl;
    else
      {
          fin.read((char *)this,sizeof(*this));
          while(!fin.eof())
            {
                showData();
                
                fin.read((char*)this,sizeof(*this));
            }
          fin.close();
      }
}
 
void Book::searchBook(char value[25])
{
    ifstream fin;
    int flag=0;
    fin.open("Mybook.txt",ios::in|ios::binary);
    if(fin)
      {
          fin.read((char*)this,sizeof(*this));
          while(!fin.eof())
            {
                if(strcmpi(value,name)==0)
                  {
                      showData();
                      flag++;
                  }
              fin.read((char*)this,sizeof(*this));    
            }

            if(flag==0)
            {
                cout<<"No.txta found..."<<endl;
            }
      }
}

int main()
{
    bool flag;
    Book b1,b2;
    /*b1.getData();
    flag=b1.storeData();
    if(flag==true)
    cout<<endl<<"Data uploaded..."<<endl<<endl;
    else
    cout<<"Upload failed..."<<endl;
   // b1.showData();
    /*cout<<endl<<endl;
    b2.showData();*/
    //b1.viewAllBook();
    b1.searchBook("Objective Physics");
    return 0;
}