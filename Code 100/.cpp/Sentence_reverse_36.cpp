//Program No.36
//Reverse a sentence using recursion

#include<iostream>
#include<string>

using namespace std;

void ReverseSentence(const string& sentence)
    {
        int noOfChar=sentence.size();
        if(noOfChar==1)
        cout<<sentence;

        else
        {
         cout<<sentence[noOfChar-1];
         ReverseSentence(sentence.substr(0,noOfChar-1));
        }
    }          
         
int main()
{
    string sentence;
    cout<<"Type any sentence"<<endl;
    
    getline(cin,sentence);

    ReverseSentence(sentence);
    return 0;
}