#pragma once
#include <vector>
#include <iostream>
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
            std::vector<real> mvec_; //Хранит элементы матрицы в виде одномерного массива
        public:
            Matrix() {}; //Конструктор по умолчанию

            //Конструтор с параметрами по умолчанию
            Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows*cols)) {};

            real& operator()(int row, int col); //Доступ к элементам матрицы

            real operator()(int row, int col) const; //Ключевое слово const указанное после функции гарантирует, что функция не изменяет полей данного класса

            void print(); //Функция вывода информации в консоль

            /*Перегрузка оператора сложения для матрицы, реализована через дружественные функции*/

            friend Matrix operator+(const Matrix& A, const Matrix& B);

            friend Matrix operator-(const Matrix& A, const Matrix& B);

            friend Matrix operator*(const Matrix& A, const Matrix& B);

            /*Выполнение ДЗ*/
            friend Matrix operator+=(Matrix& A, const Matrix& B); //Перегрузка оператора +=

            friend Matrix operator-=(Matrix& A, const Matrix& B); //Перегрузка оператора -=

            friend Matrix operator*=(Matrix& A, const int B); //Перегрузка оператора *=

            //Геттеры для всех закрытых членов класса
            std::vector<real> getMvec () {return mvec_;}
            int getCols () const {return cols_;}
            int getRows () const {return rows_;}

            //Сеттеры для всех членов закрытого класса
            void setMvec(std::vector<real> Numbers_in_vector) {mvec_=Numbers_in_vector;}
            void setCols (int COLS) {cols_=COLS;}
            void setRows (int ROWS) {rows_=ROWS;}

            //Перегрузка оператора вывода информации
            friend std::ostream& operator << (std::ostream &os, Matrix &A)
            {
                for (int i=0; i<A.rows_; ++i) 
                {
                     for (int j=0; j<A.cols_; ++j)
                     {
                        os << A(i, j) << " ";
                    }
                    os<< std::endl;
                }
                return os;
            }

            friend std::istream& operator >> (std::istream& in, Matrix& A)
            {
                in >> A.cols_;
                in >> A.rows_;
                
                for (int i=0; i<A.rows_*A.cols_; ++i)
                {
                    in >> A.mvec_[i];
                }

                return in;
            }

    };
}