const int DIR_LEFT = -1,
          DIR_STRAIGHT = 0,
          DIR_RIGHT = 1,
          LINES_INTERSECT = -1,
          LINES_PARALLEL = 0,
          LINES_COINCIDE = 1;

struct Point {
  double x, y;

  Point() {}

  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }
};

struct Line {
  Point A, B;

  Line() {}

  Line(Point _A, Point _B) {
    A = _A;
    B = _B;
  }
};

Point operator + (Point A, Point B) {
  return Point(A.x + B.x, A.y + B.y);
}

Point operator - (Point A, Point B) {
  return Point(A.x - B.x, A.y - B.y);
}

Point operator * (int k, Point A) {
  return Point(k * A.x, k * A.y);
}

Point operator * (double k, Point A) {
  return Point(k * A.x, k * A.y);
}

double operator * (Point A, Point B) {
  return A.x * B.y - A.y * B.x;
}

int get_dir(Point A, Point B, Point C) {
  double dir = (B - A) * (C - B);

  if (abs(dir + 0.0) <= 1e-9)
    return DIR_STRAIGHT;

  if (dir > 0)
    return DIR_LEFT;
  
  return DIR_RIGHT;
}

double get_dist(Point A, Point B) {
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

void get_line_equation(Line l, double &a, double &b, double &c) {
  Point A = l.A,
        B = l.B;

  a = B.y - A.y;
  b = A.x - B.x;
  c = -A.x * (B.y - A.y) + A.y * (B.x - A.x);
}

int get_intersection(Line l1, Line l2, Point &res) {
  double a1, b1, c1, a2, b2, c2, D, Dx, Dy;

  get_line_equation(l1, a1, b1, c1);
  get_line_equation(l2, a2, b2, c2);

  D = a1 * b2 - a2 * b1; 
  Dx = b1 * c2 - b2 * c1; 
  Dy = c1 * a2 - c2 * a1;

  if (D != 0) {
    res.x = Dx / D; 
    res.y = Dy / D;

    return LINES_INTERSECT;
  }

  if (c1 == c2)
    return LINES_COINCIDE;

  return LINES_PARALLEL;
}

double get_dist(Line l, Point A) {
  double a, b, c;
  get_line_equation(l, a, b, c);

  return abs(a * A.x + b * A.y + c) / sqrt(a * a + b * b);
}

double get_area(Point A, Point B, Point C) {
  return abs((B - A) * (C - A)) / 2.0;
}

bool is_in_line(Line l, Point A) {
  if (get_dir(l.A, l.B, A) != DIR_STRAIGHT)
    return false;

  if (A.x < min(l.A.x, l.B.x) || max(l.A.x, l.B.x) < A.x)
    return false;
  
  if (A.y < min(l.A.y, l.B.y) || max(l.A.y, l.B.y) < A.y)
    return false;

  return true;
}
