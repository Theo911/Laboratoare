#pragma once

class Number
{
    char valoare[101];
    int baza;

public:
    Number() : valoare(""), baza(1) {}

    Number(const char* value, int base); 
    ~Number();


    Number(const Number& n);
    Number(Number&& n);
    Number(const int);

    char operator[] (int i);
    friend Number operator+ (const Number& x, const Number& y);
    friend Number operator- (const Number& x, const Number& y);
    bool operator> (Number& n);

    void operator= (const char*);
    void operator= (const Number& n);
    void operator= (int n);

    Number operator| (Number n2);

    void operator+= (Number& n);

    void operator-- ();
    void operator-- (int);


    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base

private:
    long valoareaInBazaZece(char* sir, int bazaNum);
    char* convertToBase(long n, int base);
    int getDigit(char c);
    char getChar(int n);
};
