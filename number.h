#ifndef NUMBER_H
#define NUMBER_H


#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <string_view>
#include <functional>
using namespace std::literals::string_view_literals;
//class to handle big numbers that cant be handled by the standard types
class Number {
public:
    class InvalidValue : public std::exception {
    private:
        std::string value;
        std::string errorMessage;
    public:
        InvalidValue(std::string val) : value(std::move(val)) {
            errorMessage = "ERROR: " + value + " is not a valid integer.\n";
        }
        const char* what() const noexcept override {
            return errorMessage.c_str();
        }
    };
    Number();
    Number(const char*);
    Number(std::string const&);
    Number(std::wstring const&);
    Number(Number const &);
    std::string GetValue() const;
    //overloading the math operators
    Number operator+ (Number const&);
    Number operator- (Number const&);
    Number operator* (Number const&);
    Number operator/ (Number const&);
    Number operator^ (Number const&);
    Number operator| (Number const&);
    Number operator& (Number const&);
    Number operator!();
    //overloading the stream operators to represent right and left shift operations
    Number operator<< (Number const&);
    Number operator>> (Number const&);
    //.............................................................................
    bool operator== (const Number&);
    const Number operator= (const Number&);

private:
    std::string number{ "" };
    std::string numString{ "0123456789" };
    std::string add(std::string_view, std::string_view);
    std::string subtract(std::string_view, std::string_view);
    std::string multiply(std::string_view, std::string_view);
    std::string divide(std::string const&);
    std::string stripResult(std::string const&);
    void makeEqualLength(std::string&, std::string&, bool);
};


#endif // NUMBER_H
