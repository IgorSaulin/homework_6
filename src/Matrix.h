#pragma once
#include <vector>
//Данный файл является заголовочным
namespace math //Задается пространство имен, в котором указываются сведения касательно данного класса
{
    //Пользовательский тип данных, необходим для работы с данными типа float
    typedef double real; //real выступает в качестве некоторого типа данных-псевдонима

    class Matrix
    {
        
        private:
            int cols_; //Переменные отвечающие за колонку и за строку
            int rows_;
            std::vector<real> mvec_;
        public:
            Matrix() {};
            //Конструтор с параметрами по умолчанию
            Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows*cols)) {};

            real& operator()(int row, int col);

            void print();
    };
}