#include "term.h"
#include <cmath>
#include <iostream>

using namespace std;

Term::Term(float coefficient, int pow) {
    coef = coefficient;
    power = pow;
}

Term Term::operator + (Term obj) const {
    return Term(coef + obj.getCoef(), power);
}

Term Term::operator - (Term obj) const {
    return Term(coef - obj.getCoef(), power);
}

Term Term::operator * (Term obj) const {
    return Term(coef * obj.getCoef(), power + obj.getPower());
}

Term Term::operator / (Term obj) const {
    return Term(coef / obj.getCoef(), power - obj.getPower());
}

Term Term::operator ~ () const {
    return Term(coef * power, power - 1);
}

void Term::operator += (Term obj) {
    coef += obj.getCoef();
}

void Term::operator -= (Term obj) {
    coef -= obj.getCoef();
}

void Term::operator *= (Term obj) {
    coef *= obj.getCoef();
    power += obj.getPower();
}

void Term::operator /= (Term obj) {
    coef /= obj.getCoef();
    power -= obj.getPower();
}

void Term::operator = (Term obj) {
    coef = obj.getCoef();
    power = obj.getPower();
}

void Term::operator ++ () {
    coef++;
}

void Term::operator -- () {
    coef--;
}

bool Term::operator > (Term obj) const {
    if (power > obj.getPower()) {
        return true;
    }
    else if (power == obj.getPower() && coef > obj.getCoef()) {
        return true;
    }
    return false;
}

bool Term::operator >= (Term obj) const {
    if (power > obj.getPower()) {
        return true;
    }
    else if (power == obj.getPower() && coef >= obj.getCoef()) {
        return true;
    }
    return false;
}

bool Term::operator < (Term obj) const {
    if (power < obj.getPower()) {
        return true;
    }
    else if (power == obj.getPower() && coef < obj.getCoef()) {
        return true;
    }
    return false;
}

bool Term::operator <= (Term obj) const {
    if (power < obj.getPower()) {
        return true;
    }
    else if (power == obj.getPower() && coef <= obj.getCoef()) {
        return true;
    }
    return false;
}

bool Term::operator == (Term obj) const {
    if (power == obj.getPower() && coef == obj.getCoef()) {
        return true;
    }
    return false;
}
bool Term::operator != (Term obj) const {
    if (power == obj.getPower() && coef == obj.getCoef()) {
        return false;
    }
    return true;
}

float Term::operator () (float xValue) const {
    return coef * (pow(xValue, power));
}

ostream& operator << (ostream& out, Term term) {
    if (term.getCoef() != 0) {
        if (term.getCoef() != 1) {
            out << term.getCoef();
        }
        if (term.getPower() != 0) {
            out << 'x';
            if (term.getPower() != 1) {
                out << '^' << term.getPower();
            }
        }
    }
    return out;
}

istream& operator >> (istream& inp, Term& term) {
    string temp;
    inp >> temp;
    bool xExists = false;
    int xIndex;

    for (int i = 0; i < int(temp.length()); i++) {
        if (temp[i] == 'x') {
            xExists = true;
            xIndex = i;
        }
    }

    if (xExists) {
        if (temp[0] == 'x') {
            term.setCoef(1);
        }
        else {
            string strCoef = "";
            for (int i = 0; temp[i] != 'x'; i++) {
                strCoef += temp[i];
            }
            term.setCoef(stof(strCoef));
        }
        if (int(temp.length()) > xIndex + 1) {
            string strPower = "";
            for (int i = xIndex + 2; i < int(temp.length()); i++) {
                strPower += temp[i];
            }
            term.setPower(stoi(strPower));
        }
    }
    else {
        string strCoef = "";
        for (int i = 0; i < int(temp.length()); i++) {
            strCoef += temp[i];
        }
        term.setCoef(stof(strCoef));
    }
    return inp;
}
