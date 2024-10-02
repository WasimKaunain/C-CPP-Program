#include"wtypes.h"
#include<iostream>
using namespace std;

void GetDesktopResolution(int& horizontal, int& vertical)
{
    RECT desktop;
    const HWND hDesktop =GetDesktopWindow();
    GetWindowRect(hDesktop,&desktop);
    horizontal=desktop.right;
    vertical=desktop.bottom;
    cout<<"Horizontal : "<<horizontal<<endl;
    cout<<"Vertical : "<<vertical<<endl;

}

int main()
{
    int horizontal=0;
    int vertical=0;
    GetDesktopResolution(horizontal,vertical);

    return 0;
}