/// @see [https://pione.hatenablog.com/entry/2021/01/31/020037]
template <typename T>
class BIT {
private:
  int n;
  vector<T> d;

public:
  BIT(int n = 0) : n(n), d(n + 1) {}

  void add(int i, T x = 1) {
    for (; i <= n; i += i & -i) {
      d[i] += x;
    }
  }

  T sum(int i) {
    T x = 0;
    for (; i; i -= i & -i) {
      x += d[i];
    }
    return x;
  }

  T sum(int l, int r) { return sum(r) - sum(l - 1); }
};