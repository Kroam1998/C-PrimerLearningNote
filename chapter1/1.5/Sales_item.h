#pragma once
#include <iostream>
#include <string>

class Sales_item {
public:
    Sales_item(const std::string &book) : isbn(book), units_sold(0), revenue(0.0) {}
    Sales_item(std::istream &is) { is >> *this; }
    friend std::istream &operator>>(std::istream &, Sales_item &);
    friend std::ostream &operator<<(std::ostream &, const Sales_item &);

public:
    Sales_item &operator+=(const Sales_item &);

public:
    double avg_price() const;
    bool same_isbn(const Sales_item &rhs) const { return isbn == rhs.isbn; }
    Sales_item() : units_sold(0), revenue(0.0) {}

public:
    std::string isbn;
    unsigned units_sold;
    double revenue;
};

using std::istream;
using std::ostream;
Sales_item operator+(const Sales_item &, const Sales_item &);

inline bool operator==(const Sales_item &lhs, const Sales_item &rhs) {
    return lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue && lhs.same_isbn(rhs);
}

inline bool operator!=(const Sales_item &lhs, const Sales_item &rhs) { // 已经重载了等于，直接返回取反即可
    return !(lhs == rhs);
}

inline Sales_item &
Sales_item::operator+=(const Sales_item &rhs) { // 重载了+=操作， Sales_item & 返回当前对象引用， Sales_item::operator+=
                                                // 重载 += (const Sales_item &rhs) 接受一个右操作数
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs) { // 两个Sales_item 相加返回结果
    Sales_item ret(lhs);
    ret += rhs;
    return ret;
}

inline istream &operator>>(istream &in, Sales_item &s) {
    double price;
    in >> s.isbn >> s.units_sold >> price;
    if (in) {
        s.revenue = s.units_sold * price;
    } else {
        s = Sales_item();
    }
    return in;
}

inline ostream &operator<<(ostream &out, const Sales_item &s) {
    out << s.isbn << "\t" << s.units_sold << "\t" << s.revenue << "\t" << s.avg_price();
    return out;
}

inline double Sales_item::avg_price() const {
    if (units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}
