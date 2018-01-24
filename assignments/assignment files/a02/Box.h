// File: Box.h

#ifndef BOX_H
#define BOX_H

class Box
{
 public:
  Box(double x0, double y0, double w0, double h0)
    : x(x0), y(y0), w(w0), h(h0)
    {}

    double get_x() const
    { return x; }

    double get_y() const
    { return y; }

    double get_w() const
    { return w; }

    double get_h() const
    { return h; }

    Box lefthalf() const
    {
      return Box(get_x(), get_y(), get_w() / 2, get_h());
    }

    Box righthalf() const
    {
      return Box(get_x() + (get_w() / 2), get_y(), get_w() / 2, get_h());
    }

    Box tophalf() const
    {
      return Box(get_x(), get_y() + (get_h() / 2), get_w(), get_h() / 2);
    }

    Box bottomhalf() const
    {
      return Box(get_x(), get_y(), get_w(), get_h() / 2);
    }

    bool onboundary(const int x, const int y) const
    {
      bool isOnBoundary = false;

      if (y == get_y() && x >= get_x() && x <= (get_x() + get_w()))
	isOnBoundary = true;
      if (x == get_x() && y >= get_y() && y <= (get_y() + get_h()))
	isOnBoundary = true;
      if (y == (get_y() + get_h()) && x >= get_x() && x <= (get_x() + get_w()))
	isOnBoundary = true;
      if (x == (get_x() + get_w()) && y >= get_y() && y <= (get_y() + get_h()))
	isOnBoundary = true;

      return isOnBoundary;
    }

    bool inside(const int x, const int y) const
    {
      bool inside_box = false;

      if (x > get_x() && x < (get_x() + get_w()) && y > get_y() && y < (get_y() + get_h()))
	  inside_box = true;

      return inside_box;
    }

    bool outside(const int x, const int y) const
    {
      bool outside_box = false;

      if (x < get_x() || x > (get_x() + get_w()))
	outside_box = true;
      if (y < get_x() || y > (get_y() + get_h()))
	outside_box = true;
    }

 private:
  double x, y, w, h;
};

std::ostream &operator<<(std::ostream &out, Box const & box)
{
  out << "<" << box.get_x() << ", " << box.get_y() << ", " << box.get_w() << ", " << box.get_h() << ">";

  return out;
}

#endif
