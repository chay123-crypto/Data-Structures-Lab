/*Calculating area of square or rectangle or cube or cuboid uisng classes*/
#include <iostream>
using namespace std;

class square 
{
    public:
    /*Data member*/
    int len;

    /*Member Function*/
    int area()
    {
        int area=len*len;
        return area;
    }

    void displayinfo()
    {
      cout<<"Area of the given square is "<<area()<<endl;
    }

};
class rectangle
{
    public:
    /*Data member*/
    int len;
    int br;

    /*Member Function*/
    int area()
    {
        int area=len*br;
        return area;
    }
     void displayinfo()
    {
      cout<<"Area of the given rectangle is:"<<area()<<endl;
    }
};
class cuboid
{
    public:
  /*Data member*/
    int len;
    int br;
    int hei;
/*Member Function*/
    int area()
    {
        int area=2*(len*br)+2*(br*hei)+2*(hei*len);
        return area;
    }
     void displayinfo()
    {
      cout<<"Area of the given cuboid is:"<<area()<<endl;
    }
};
class cube
{
    public:
    /*Data member*/
    int len;

   /*Member Function*/
    int area()
    {
        int area=(len*len)*6;
        return area;
    }

    void displayinfo()
    {
      cout<<"Area of the given cube "<<area()<<endl;
    }

};
int main()
{
   int choice;
   square sq;
   rectangle rect;
   cuboid cubo;
   cube cub;
   
    do
    {
    cout << "\n//MENU//\n";
    cout << "1.Find area of square\n";
    cout << "2.Find area of a rectangle\n";
    cout << "3. Find area of a cuboid\n";
     cout <<"4. Find area of a cube\n";
    cout << "5. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    if(choice==1)/*calling the class of square*/
    {
       cout<<"Enter the length of the square:";
       cin >> sq.len;
      
       sq.displayinfo();
    }
    if(choice==2)/*calling the class of rectangle*/
    {
       cout<<"Enter the length of the rectangle:";
       cin >> rect.len;
       cout<<"Enter the breadth of the rectangle:";
        cin >> rect.br;
       
       rect.displayinfo();
    }
    if(choice==3)/*calling the class of cuboid*/
    {
       cout<<"Enter the length of the cuboid:";
       cin >> cubo.len;
       cout<<"Enter the breadth of the cuboid:";
       cin >> cubo.br;
       cout<<"Enter the height of the cuboid:";
       cin >> cubo.hei;
  
       cubo.displayinfo();
    }
    if(choice==4)/*calling the class of cube*/
    {
       cout<<"Enter the length of the cube:";
       cin >> cub.len;
    
       cub.displayinfo();
    }
    if(choice==5)/*exiting the program*/
    {
        cout<<"Exiting the program.....";
    }
    } while (choice!=5);
    if(choice>5)
    {
        cout<<"Invalid choice!";
    }

   return 0;
}
