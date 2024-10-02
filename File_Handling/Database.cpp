#include <iostream>
//#include<cstring>                                         //Omitted
#include <string>                                           //Modified
using namespace std;

//void intro();                                               //Omitted
void intro()
{
    cout<<endl<<endl;
    cout<<"\t\tThis is a STRSTR program in C++\n";                  //Modified
    cout<<"\t\t------------------------------------\n";
    cout<<endl;
}

int main()
{
    intro();
    const int SIZE = 50;              
    //const int PRODS_NUM = 5;                          //Omitted
   // char *strptr;
    
    string lookup;                                  //Modified
    int index;

    string database[SIZE] = {"Cars", "iPhone Pro Max", "Iron", "Refrigerators", "Laptop"};

    cout<<"\t\tEnter the name of the Item to search: ";
    getline(cin,lookup);
    cout<<endl;

    int result=2;                                 //Added
    bool flag=true;                                   //Added
    for(index = 0; index < SIZE; index++)            //Modified
    {
       // strptr = strstr(database[index], lookup);    //Omitted
        if(lookup==database[index])                                 //Modified
       //if(strcasecmp(lookup.c_str(),database[index].c_str())==0)      //You can use this condition for CASE INSENSITIVITY. To use this remove the comment from header file cstring.
            {
               cout<<"\t\t"<<database[index]<<endl;         //Modified
               flag=false;                                     //Modified
               break;                                       //Mpdified
                                                  
            }
/*if(strptr != nullptr)                                  
            break;                                        //Omitted
    }*/
    }

    //if(strptr!=nullptr)                                       //Omitted
      //  cout<<"\t\t"<<database[index]<<endl;
    if(flag)                                                    //Modified
        cout<<"\t\tNo Matching results was found\n";
    return 0;
}


