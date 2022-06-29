#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;

class Term
{
public:
    Term(float coefficient, int pow = 0);

    Term operator + (Term obj) const;
    Term operator - (Term obj) const;
    Term operator * (Term obj) const;
    Term operator / (Term obj) const;
    Term operator ~ () const;


    void operator += (Term obj);
    void operator -= (Term obj);
    void operator *= (Term obj);
    void operator /= (Term obj);
    void operator = (Term obj);
    void operator ++ ();
    void operator -- ();

    bool operator > (Term obj) const;
    bool operator >= (Term obj) const;
    bool operator < (Term obj) const;
    bool operator <= (Term obj) const;
    bool operator == (Term obj) const;
    bool operator != (Term obj) const;

    float operator () (float xValue) const;


    float getCoef(){
        return coef;
    }
    int getPower(){
        return power;
    }
    void setCoef(float newCoef){
        coef = newCoef;
    }
    void setPower(int newPower){
        power = newPower;
    }
private:
    float coef; // coefficient of x
    int power; // power of x
};

#endif // TERM_H
