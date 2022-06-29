#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "term.h"
#include <iostream>
#include <vector>

class Polynomial
{
public:
    Polynomial(vector<Term> t);

    Polynomial operator + (const Polynomial& obj) const;
    Polynomial operator - (const Polynomial& obj) const;
    vector<Term> operator * (Polynomial obj);
    vector<Term> operator ~ () const;


    void operator += (Polynomial obj);
    void operator -= (Polynomial obj);
    void operator *= (Polynomial obj);
    void operator = (Polynomial obj);
    void operator ++ ();
    void operator -- ();

    bool operator > (Polynomial obj) const;
    bool operator >= (Polynomial obj) const;
    bool operator < (Polynomial obj) const;
    bool operator <= (Polynomial obj) const;
    bool operator == (Polynomial obj) const;
    bool operator != (Polynomial obj) const;

    float operator () (float xValue) const;

    Term operator [] (int index) const;

    vector<Term> getTerms() {
        return terms;
    }
private:
    vector<Term> terms;
};

#endif // POLYNOMIAL_H
