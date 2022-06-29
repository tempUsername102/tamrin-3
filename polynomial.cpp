#include "polynomial.h"

#include <iostream>

using namespace std;


Polynomial::Polynomial(vector<Term> t) {
    terms = t;
}

Polynomial Polynomial::operator + (const Polynomial& obj) const {
    vector<Term> sumTerms = terms;
    for (int i = 0; i < int(obj.terms.size()); i++) {
        sumTerms.push_back(obj.terms[i]);
    }
    return Polynomial(sumTerms);
}

Polynomial Polynomial::operator - (const Polynomial& obj) const {
    vector<Term> subTerms = terms;
    for (int i = 0; i < int(obj.terms.size()); i++) {
        subTerms.push_back(Term(-obj.terms[i].getCoef(), obj.terms[i].getPower()));
    }
    return subTerms;
}

//vector<Term> Polynomial::operator * (Polynomial obj) {
//    vector<Term> multTerms;
//    for (int i = 0; i < int(terms.size()); i++) {
//        for (int j = 0; j < int(obj.getTerms().size()); j++) {
//            multTerms.push_back(terms[i] * obj.getTerms()[j]);
//        }
//    }
//    return multTerms;
//}

vector<Term> Polynomial::operator ~ () const{
    vector<Term> derivTerms;
    for (int i = 0; i < int(terms.size()); i++) {
        derivTerms.push_back(~terms[i]);
    }
    return derivTerms;
}


void Polynomial::operator += (Polynomial obj) {
    terms = this* + obj;
}

//void Polynomial::operator -= (Polynomial obj) {
//    terms = terms - obj.getTerms();
//}


//void Polynomial::operator *= (Polynomial obj) {
//    terms = terms * obj.getTerms();
//}

void Polynomial::operator = (Polynomial obj) {
    terms = obj.getTerms();
}

//void operator ++ ();
//void operator -- ();

//bool operator > (Polynomial obj)
//bool operator >= (Polynomial obj) const;
//bool operator < (Polynomial obj) const;
//bool operator <= (Polynomial obj) const;
//bool operator == (Polynomial obj) const;
//bool operator != (Polynomial obj) const;

//float operator () (float xValue) const;

//Term operator [] (int index) const;
