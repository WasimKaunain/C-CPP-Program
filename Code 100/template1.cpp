#include<iostream>
using namespace std;

template <class X> class ArrayList
{
    private:
    struct ControlBlock
        {
            int capacity;
            X *arr_ptr;
        };
    ControlBlock *s;

    public:
    ArrayList(int capacity)
        {
            s=new ControlBlock;
            s->capacity=capacity;
            s->arr_ptr=new X[s->capacity];
        }

    void addElement(int index,X data)
        {
            if(index>=0 && index<=s->capacity-1)
                s->arr_ptr[index]=data;
            else
             cout<<"\nArray index is not valid";    
        }

    void viewElement(int index,X &data)
        {
            if(index>=0 && index<=s->capacity-1)
                data=s->arr_ptr[index];
            else
             cout<<"\nArray index is not valid";
        }

    void viewList()
        {
            for(int i=0;i<s->capacity;i++)
                cout<<" "<<s->arr_ptr[i];
        }

};

int main()
    {
        int data;
        ArrayList <float>list1(4);
        list1.addElement(0,3.3);
        list1.addElement(1,3.4);
        list1.addElement(2,3.5);
        list1.addElement(3,3.6);
        list1.viewList();
        //cout<<"Value in the array : "<<data<<endl;
    }