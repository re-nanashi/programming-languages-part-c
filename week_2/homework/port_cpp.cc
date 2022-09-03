#include <cmath>
#include <iostream>
#include <string>

template <typename T1> struct Environment
{
    std::string var;
    T1 exp;
};

class GeometryValue;
class VerticalLine;

class GeometryExpression
{
  public:
    static constexpr double epsilon{0.00001};
    virtual GeometryValue eval_prog(const Environment<GeometryValue> *const arr[]);
    virtual GeometryExpression *preprocess_prog();
};

class GeometryValue
{
  public:
    GeometryValue *eval_prog(const Environment<GeometryValue> *const arr[]);
    GeometryValue *preprocess_prog();
    GeometryValue &intersect_no_points(GeometryValue &);
    GeometryValue intersect_line_segment(GeometryValue);
    virtual GeometryValue shift(double, double);
    virtual GeometryValue intersect(GeometryValue);
    virtual GeometryValue intersect_point(GeometryValue);
    virtual GeometryValue intersect_line(GeometryValue);
    virtual GeometryValue intersect_vertical_line(GeometryValue);
    virtual GeometryValue intersect_with_segment_as_line_result(GeometryValue);

  private:
    bool real_close(double, double);
    bool real_close_point(double, double, double, double);
    GeometryValue *two_points_to_line(double, double, double, double);

  protected:
    static bool inbetween(double, double, double);
};
