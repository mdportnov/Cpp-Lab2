#include "string"

namespace lab1_2 {

    int dialog(const char *[], int);

    int getNaturalInt(int*);

    class Point {
    public:
        double x, y;
        friend std::ostream &operator<<(std::ostream &out, Point &point);

        Point(double, double);
    };

    std::ostream &operator<<(std::ostream &out, Point &point);

    class Deltoid {
        double r, R, t;

        friend std::ostream &operator<<(std::ostream &out, Point &point);

    public:
        double getT() const;

        void setT(double);

    public:
        explicit Deltoid(double); // для устранения возможности объявления объекта через "= value"
        explicit Deltoid();

        double getR() const;

        void setR(double const);

        double getIntersectionLength() const;

        double getLength() const;

        double getArea() const;

        double getX(double) const;

        double getY(double) const;

        Point getXY() const;

        std::string getEquationString() const;
    };

    void checkZeroR(Deltoid &);

    void errmsg(double&);

    int dialog_input(Deltoid &);

    int dialog_getIntersectionLength(Deltoid &);

    int dialog_getCurveLength(Deltoid &);

    int dialog_getCurvedArea(Deltoid &);

    int dialog_getXY(Deltoid &);

    int dialog_getEquation(Deltoid &);
}
