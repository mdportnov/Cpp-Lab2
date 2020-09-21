#include <iostream>
#include "lab2.20.h"
#include <cmath>
#include <cstring>
#include <sstream>

namespace lab1_2 {

    Point::Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    Deltoid::Deltoid() {
        this->r = 0;
        this->R = 0;
        this->t = 0;
    }

    Deltoid::Deltoid(double r) {
        if (r < 0)
//            std::cerr << "Invalid radius";
            throw std::invalid_argument("Invalid radius");
        this->r = r;
        this->R = 3 * r;
        this->t = 0;
    }


    double Deltoid::getR() const {
        return r;
    }

    void Deltoid::setR(double const r) {
        if(r<0){
            throw std::invalid_argument("Invalid radius");
        }
        this->r = r;
        this->R = 3 * r;
    }

    double Deltoid::getX(double T) const {
        return 2 * r * cos(T) + r * cos(2 * r * T / r);
    }

    double Deltoid::getY(double T) const {
        return 2 * r * sin(T) - r * sin(2 * r * T / r);
    }

    double Deltoid::getIntersectionLength() const {
        return 4 * R / 3;
    }

    double Deltoid::getLength() const {
        return 16 * R / 3;
    }

    double Deltoid::getArea() const {
        return 2 * M_PI * R * R / 9;
    }

    std::string Deltoid::getEquationString() const {
        std::stringstream ss;
        ss<<std::endl;
        ss.str("X=2*r*cos(t)+r*cos(2t)  Y=2*r*sin(t)-r*sin(t)");
        ss<<std::endl;

        std::string s = ss.str();

        return s;
    }

    Point Deltoid::getXY() const {
        return {getX(t), getY(t)};
    }

    int dialog(const char *msgs[], int N) {
        std::string errmsg;
        int rc, n;
        do {
            std::cout << errmsg;
            errmsg = "You are wrong. Repeat, please\n";
            for (int j = 0; j < N; ++j)
                puts(msgs[j]);
            puts("Make your choice: --> ");

            n = getNaturalInt(&rc);
            if (n == 0)
                rc = 0;
        } while (rc < 0 || rc >= N);
        return rc;
    }

    int getNaturalInt(int *a) {
        int n;
        do {
            n = scanf("%d", a);
            if (n < 0)
                return 0;
            if (n == 0 || *a < 0) {
                printf("%s\n", "Error! Please, repeat your input: ");
                scanf("%*[^\n]");
            }
        } while (n == 0 || *a < 0);
        return 1;
    }

    int getDouble(double *a) {
        int n;
        do {
            n = scanf("%lf", a);
            if (n < 0)
                return 0;
            if (n == 0 || *a < 0) {
                printf("%s\n", "Error! Please, repeat your input: ");
                scanf("%*[^\n]");
            }
        } while (n == 0 || *a < 0);
        return 1;
    }

    int dialog_input(Deltoid &deltoid) {
        double r;
        std::cout << "\nInput \"r\" parameter for deltoid:\n";
        getDouble(&r);
        deltoid.setR(r);

        return 1;
    }

    int dialog_getIntersectionLength(Deltoid &deltoid) {
        try {
            checkZeroR(deltoid);
            printf("\nIntersection length is: %.2lf\n\n", deltoid.getIntersectionLength());
            return 1;
        }
        catch (double r) {
            errmsg(r);
            std::cerr << "Radius of inner circle equals " << r << "\n";
            return 1;
        }
    }

    int dialog_getCurveLength(Deltoid &deltoid) {
        try {
            checkZeroR(deltoid);
            printf("\nCurve length is: %.2lf\n\n", deltoid.getLength());
            return 1;
        }
        catch (double r) {
            errmsg(r);
            std::cerr << "Radius of inner circle equals " << r << "\n";
            return 1;
        }
    }

    int dialog_getCurvedArea(Deltoid &deltoid) {
        try {
            checkZeroR(deltoid);
            printf("\nCurved area is: %.2lf\n\n", deltoid.getArea());
            return 1;
        }
        catch (double r) {
            errmsg(r);
            return 1;
        }
    }

    int dialog_getXY(Deltoid &deltoid) {
        try {
            checkZeroR(deltoid);
            std::cout << "\nInput \"t\" parameter for deltoid:\n";
            double t;
            getDouble(&t);
            deltoid.setT(t);
            Point point = deltoid.getXY();
            std::cout << point;
            return 1;
        }
        catch (double r) {
            errmsg(r);
            return 1;
        }
    }

    std::ostream &operator<<(std::ostream &out, Point &point) {
        out << "Point(" << point.x << ";" << point.y << ")\n\n";
        return out;
    }

    double Deltoid::getT() const {
        return t;
    }

    void Deltoid::setT(double t) {
        this->t = t;
    }

    int dialog_getEquation(Deltoid &deltoid) {
        std::cout<<std::endl<<deltoid.getEquationString()<<std::endl;
        return 1;
    }

    void checkZeroR(Deltoid &deltoid) {
        if (deltoid.getR() == 0) {
            throw deltoid.getR();
        }
    }

    void errmsg(double &r) {
        std::cerr << "Radius of inner circle equals " << r << "\n";
    }


}
