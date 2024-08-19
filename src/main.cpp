#include <src/Matrix.h>
#include <iostream>
int main ()
{
    math::Matrix m(3, 3);
    m(0, 0)=1.;
    m(1, 1)=1.;

    math::Matrix m1(3, 3);
    m1(0, 0)=5.;
    m1(1, 1)=5.;

    std::cout<<"Matrix m is:"<<std::endl;
    m.print();

    std::cout<<std::endl<<"Matrix m1 is:"<<std::endl;
    m1.print();

    std::cout<<std::endl<<"Sum of matrices m and m1 is:"<<std::endl;
    math::Matrix m2=m1+m;
    m2.print();

    std::cout<<std::endl<<"Subtract of matrices m and m1 is:"<<std::endl;
    math::Matrix m3=m-m1;
    m3.print();

    std::cout<<std::endl<<"Multiplication of matrices m and m1 is:"<<std::endl;
    math::Matrix m4=m*m1;
    m4.print();

    std::cout<<std::endl<<"Matrix after +=:"<<std::endl;
    m+=m1;
    m.print();

    std::cout<<std::endl<<"Matrix after -=:"<<std::endl;
    m-=m3;
    m.print();

    std::cout<<std::endl<<"Matrix after *=:"<<std::endl;
    m*=5;
    m.print();

    std::cout <<"Matrix m="<<m;

    math::Matrix m6(1000, 1000);

    std::cout<<"Enter matrix cols, rows and all matrix elements"<<std::endl;
    std::cin>>m6;

    std::cout<<"Your Matrix: "<<std::endl;
    std::cout <<m6;

    m6(0, 0)=4; //Переприсвоим значение первого элемента матрицы

    m6*=2;

    std::cout<<"Your Matrix: "<<std::endl;
    std::cout <<m6;

    

    return 0;
}