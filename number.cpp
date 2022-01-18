#include "number.h"

Number::Number() = default;

Number::Number(const char* str) {
    number.clear();
    std::string_view str1 = str;
    for (const auto& elem : str1) {
        (!isdigit(elem)) && (elem != '.') && (elem != '-') ? throw Number::InvalidValue(str) : number += elem;
    }
}

Number::Number(std::string const& str) : Number(str.c_str()) {}

Number::Number(const Number & otherObject) : Number(otherObject.number.c_str()) {}

std::string Number::GetValue() const {
    return number;
}

void Number::makeEqualLength(std::string & number1, std::string & number2, bool reverse = false) {
    //reverse flag is used to indicate what part of the radix point we are making equal
    //if its the integer part, reverse is false
    //i.e the zeroes are added at the beginning
    //else it is true
    //i.e the zeroes are added at the end
    unsigned diff = std::labs(std::size(number1) - std::size(number2));
    std::string tempInteger(diff, '0');
    if (std::size(number1) > std::size(number2)) {
        if (reverse)
            number2 += tempInteger;
        else
            number2 = tempInteger + number2;
    }
    else if (std::size(number1) < std::size(number2)) {
        if (reverse)
            number1 += tempInteger;
        else
            number1 = tempInteger + number1;
    }
}

std::string Number::stripResult(std::string const& result) {
    std::string normalizedResult = result;
    if (std::all_of(std::begin(normalizedResult), std::end(normalizedResult), [](char elem) {return elem == '0'; }))
        return "0";
    if (normalizedResult.find('.') != std::string::npos) {
        for (std::string::iterator iter = std::prev(normalizedResult.end()); *iter == '0'; --iter) {
            normalizedResult.erase(iter);
        }
        if (normalizedResult.back() == '.')
            normalizedResult.pop_back();
    }
    return normalizedResult;
}

//addition
Number Number::operator+ (Number const& otherNumber) {
    Number m_number{ *this }, m_otherNumber{ otherNumber };
    if (m_number.number.front() == '-' && m_otherNumber.number.front() != '-') {
        m_number.number.erase(std::begin(m_number.number));
        return Number{(m_otherNumber - m_number).number };
    }
    else if (m_number.number.front() != '-' && m_otherNumber.number.front() == '-') {
        m_otherNumber.number.erase(std::begin(m_otherNumber.number));
        return Number{ m_number - m_otherNumber};
    }
    else if (m_number.number.front() == '-' && m_otherNumber.number.front() == '-') {
        m_number.number.erase(std::begin(m_number.number));
        m_otherNumber.number.erase(std::begin(m_otherNumber.number));
        return Number{ "-" + (m_number + m_otherNumber).number };
    }
    else {
        auto [radixPosition1, radixPosition2] = std::tuple(m_number.number.find('.'), m_otherNumber.number.find('.'));
        if (radixPosition1 == std::string::npos && radixPosition2 == std::string::npos) {
            makeEqualLength(m_number.number, m_otherNumber.number);
            auto result = add(m_number.number, m_otherNumber.number);
            return Number(stripResult(result));
        }
        else {
            std::string integerPart, decimalPart, otherIntegerPart, otherDecimalPart;
            if (m_number.number.find('.') != std::string::npos) {
                integerPart = m_number.number.substr(0, radixPosition1);
                decimalPart = m_number.number.substr(radixPosition1 + 1, std::size(m_number.number) - (radixPosition1 + 1));
            }
            else {
                radixPosition1 = std::size(m_number.number);
                integerPart = m_number.number;
                decimalPart = "0";
            }
            if (m_otherNumber.number.find('.') != std::string::npos) {
                otherIntegerPart = m_otherNumber.number.substr(0, radixPosition2);
                otherDecimalPart = m_otherNumber.number.substr(radixPosition2 + 1, std::size(m_otherNumber.number) - (radixPosition2 + 1));
            }
            else {
                radixPosition2 = std::size(m_otherNumber.number);
                otherIntegerPart = m_otherNumber.number;
                otherDecimalPart = "0";
            }
            makeEqualLength(integerPart, otherIntegerPart);
            makeEqualLength(decimalPart, otherDecimalPart, true);
            size_t newRadixPosition = radixPosition1 > radixPosition2 ? radixPosition1 : radixPosition2;
            Number num1 = integerPart + decimalPart;
            Number num2 = otherIntegerPart + otherDecimalPart;
            std::string result = (num1 + num2).number;
            result.insert(newRadixPosition, ".");
            if (result.front() == '.')
                result = "0" + result;
            return Number{ result };
        }
    }
}

//subtraction
Number Number::operator- (Number const& otherNumber) {
    Number m_number{ *this }, m_otherNumber{ otherNumber };
    if (m_number.number.front() == '-' && m_otherNumber.number.front() != '-') {
        m_number.number.erase(std::begin(m_number.number));
        return Number{ "-" + (m_number + m_otherNumber).number };
    }
    else if (m_number.number.front() != '-' && m_otherNumber.number.front() == '-') {
        m_otherNumber.number.erase(std::begin(m_otherNumber.number));
        return Number{ m_otherNumber + m_number };
    }
    else if (m_number.number.front() == '-' && m_otherNumber.number.front() == '-') {
        m_number.number.erase(std::begin(m_number.number));
        m_otherNumber.number.erase(std::begin(m_otherNumber.number));
        return Number{(m_otherNumber - m_number).number };
    }
    else if (m_number < m_otherNumber) {
        return Number{ "-" + (m_otherNumber - m_number).number };
    }
    else {
        auto [radixPosition1, radixPosition2] = std::tuple(m_number.number.find('.'), m_otherNumber.number.find('.'));
        if (radixPosition1 == std::string::npos && radixPosition2 == std::string::npos) {
            makeEqualLength(m_number.number, m_otherNumber.number);
            auto result = subtract(m_number.number, m_otherNumber.number);
            return Number(stripResult(result));
        }
        else {
            std::string integerPart, decimalPart, otherIntegerPart, otherDecimalPart;
            if (m_number.number.find('.') != std::string::npos) {
                integerPart = m_number.number.substr(0, radixPosition1);
                decimalPart = m_number.number.substr(radixPosition1 + 1, std::size(m_number.number) - (radixPosition1 + 1));
            }
            else {
                radixPosition1 = std::size(m_number.number);
                integerPart = m_number.number;
                decimalPart = "0";
            }
            if (m_otherNumber.number.find('.') != std::string::npos) {
                otherIntegerPart = m_otherNumber.number.substr(0, radixPosition2);
                otherDecimalPart = m_otherNumber.number.substr(radixPosition2 + 1, std::size(m_otherNumber.number) - (radixPosition2 + 1));
            }
            else {
                radixPosition2 = std::size(m_otherNumber.number);
                otherIntegerPart = m_otherNumber.number;
                otherDecimalPart = "0";
            }
            makeEqualLength(integerPart, otherIntegerPart);
            makeEqualLength(decimalPart, otherDecimalPart, true);//true is used to indiate that is a decimal being normalized
            size_t newRadixPosition = radixPosition1 > radixPosition2 ? radixPosition1 : radixPosition2;
            Number num1 = integerPart + decimalPart;
            Number num2 = otherIntegerPart + otherDecimalPart;
            std::string result = (num1 - num2).number;
            newRadixPosition = newRadixPosition - (std::size(num1.number) - std::size(result));
            result.insert(newRadixPosition, ".");
            if (result.front() == '.')
                result = "0" + result;
            return Number{ result };
        }
    }
}

//multitplication
Number Number::operator* (Number const& otherNumber) {
    Number m_number{ *this }, m_otherNumber{ otherNumber };
    std::uint32_t negativeCounter{ 0 };
    if (m_number.number.front() == '-') {
        m_number.number.erase(std::begin(m_number.number));
        ++negativeCounter;
    }
    if (m_otherNumber.number.front() == '-') {
        ++negativeCounter;
        m_otherNumber.number.erase(std::begin(m_otherNumber.number));
    }
    auto [radixPosition1, radixPosition2] = std::tuple(m_number.number.find('.'), m_otherNumber.number.find('.'));
    std::size_t newRadixPosition{ 0 };
    if (radixPosition1 != std::string::npos) {
        m_number.number.replace(radixPosition1, 1, "");
        newRadixPosition += std::distance(std::begin(m_number.number) + radixPosition1, std::end(m_number.number));
    }
    if (radixPosition2 != std::string::npos) {
        m_otherNumber.number.replace(radixPosition2, 1, "");
        newRadixPosition += std::distance(std::begin(m_otherNumber.number) + radixPosition2, std::end(m_otherNumber.number));
    }
    std::string result = multiply(m_number.number, m_otherNumber.number);
    if (newRadixPosition != 0)
        result.insert(std::distance(std::begin(result) + newRadixPosition, std::end(result)), ".");
    if (negativeCounter == 1)
        result = "-" + stripResult(result);
    return Number{ result };
}

Number Number::operator/ (Number const& otherNumber) {
    Number m_number{ *this }, m_otherNumber{ otherNumber };
    std::uint32_t negativeCounter{ 0 };
    if (m_number.number.front() == '-') {
        m_number.number.erase(std::begin(m_number.number));
        ++negativeCounter;
    }
    if (m_otherNumber.number.front() == '-') {
        ++negativeCounter;
        m_otherNumber.number.erase(std::begin(m_otherNumber.number));
    }
    std::string result = divide(m_number.number, m_otherNumber.number);
    if (negativeCounter == 1)
        result = "-" + stripResult(result);
    return Number{ result };
}

std::string Number::add(std::string_view num1, std::string_view num2) {
    std::string tempAns;
    std::uint32_t arguend{ 0 }, addend{ 0 }, sum{ 0 }, remainder{ 0 };
    std::vector<char> num1AsVec(std::size(num1)), num2AsVec(std::size(num2));
    std::copy(std::begin(num1), std::end(num1), std::begin(num1AsVec));
    std::copy(std::begin(num2), std::end(num2), std::begin(num2AsVec));
    auto [iter1, iter2] = std::pair(num1AsVec.crbegin(), num2AsVec.crbegin());
    for (; iter1 != num1AsVec.crend() && iter2 != num2AsVec.crend(); ++iter1, ++iter2) {
        arguend = numString.find(*iter1);
        addend = numString.find(*iter2);
        sum = (arguend + addend + remainder);
        remainder = 0;
        if (sum > 9) {
            remainder = sum / 10;
            sum = sum % 10;
        }
        tempAns += (std::to_string(sum));
    }
    if (remainder != 0)
        tempAns += numString.substr(remainder, 1);
    while (tempAns.back() == '0')
        tempAns.pop_back();
    std::reverse(std::begin(tempAns), std::end(tempAns));
    return tempAns.c_str();
}

std::string Number::subtract(std::string_view num1, std::string_view num2) {
    std::string tempAns;
    std::uint32_t minuend{ 0 }, subtrahend{ 0 }, difference{ 0 };
    std::vector<char> num1AsVec(std::size(num1)), num2AsVec(std::size(num2));
    std::copy(std::begin(num1), std::end(num1), std::begin(num1AsVec));
    std::copy(std::begin(num2), std::end(num2), std::begin(num2AsVec));

    auto [iter1, iter2] = std::pair(num1AsVec.rbegin(), num2AsVec.rbegin());
    for (; iter1 != num1AsVec.rend() && iter2 != num2AsVec.rend(); ++iter1, ++iter2) {
        minuend = numString.find(*iter1);
        subtrahend = numString.find(*iter2);
        if (minuend < subtrahend) {
            char elem;
            minuend += 10;
            ++iter1;
            auto val = numString.find(*iter1);
            if (val == 0) {
                std::vector<char>::reverse_iterator tempIter = iter1;
                while (val == 0) {
                    ++tempIter;
                    val = numString.find(*tempIter);
                }
                --val;
                elem = std::to_string(val)[0];//extracts the string as a character
                *tempIter = elem;
                //change all borrowed from zeroes to nine
                while (tempIter != iter1) {
                    --tempIter;
                    *tempIter = '9';
                }
                --iter1;//return iterator to former position
            }
            else {
                --val;
                char elem = std::to_string(val)[0];//extracts the string as a character
                *iter1 = elem;
                --iter1;
            }
        }
        difference = minuend - subtrahend;
        tempAns += std::to_string(difference);
    }
    while (tempAns.back() == '0')
        tempAns.pop_back();
    std::reverse(std::begin(tempAns), std::end(tempAns));
    return tempAns.c_str();
}

std::string Number::multiply(std::string_view num1, std::string_view num2) {
    std::vector<char> multiplicand(std::size(num1)), multiplier(std::size(num2));
    std::copy(std::begin(num1), std::end(num1), std::begin(multiplicand));
    std::copy(std::begin(num2), std::end(num2), std::begin(multiplier));
    std::vector<std::string> product;
    auto result = 0, remainder = 0;
    std::string eachAns;
    for (auto i = std::crbegin(multiplier); i != std::crend(multiplier); ++i) {
        for (auto j = std::crbegin(multiplicand); j != std::crend(multiplicand); ++j) {
            result = ((numString.find(*i) * numString.find(*j)) + remainder) % 10;
            remainder = ((numString.find(*i) * numString.find(*j)) + remainder) / 10;
            eachAns += std::to_string(result);
        }
        if (remainder != 0)
            eachAns += std::to_string(remainder);
        std::reverse(eachAns.begin(), eachAns.end());
        product.push_back(eachAns);
        eachAns.clear();
        remainder = 0;
    }
    //this fills the numbers with zeroes at the end so that the can be added without problems
    for (size_t i{ 1 }; i < product.size(); ++i)
        for (size_t j = 0; j < i; ++j)
            product.at(i).push_back('0');
    //vector of each row of product
    std::vector<Number> numbersToAdd(std::size(product));
    //creates a vector of Integer objects from each row of products
    for (size_t i{ 0 }; i < std::size(product); ++i)
        numbersToAdd[i] = Number(product[i].c_str());
    auto sumOfProducts = stl::parallel_accumulate(numbersToAdd.begin(), numbersToAdd.end(), Number("0"));//love this line
    return sumOfProducts.number;
}

std::string Number::divide(std::string const& _numerator, std::string const& denominator) {
    std::string tempDenominator{ denominator };
    std::string numerator = _numerator;
    size_t distance{ 0 };
    //normalize numerator and denominator
    auto radixPosition1 = numerator.find('.');
    auto radixPosition2 = tempDenominator.find('.');
    if (radixPosition2 != std::string::npos && radixPosition1 == std::string::npos) {
        distance = std::size(tempDenominator) - (radixPosition2 + 1);
        for (auto i{ 0u }; i < distance; ++i)
            numerator.push_back('0');
        tempDenominator.erase(std::begin(tempDenominator) + radixPosition2);
    }
    else if (radixPosition1 != std::string::npos && radixPosition2 == std::string::npos) {
        distance = std::size(numerator) - (radixPosition1 + 1);
        for (auto i{ 0u }; i < distance; ++i)
            tempDenominator.push_back('0');
        numerator.erase(std::begin(numerator) + radixPosition1);
    }
    else if (radixPosition1 != std::string::npos && radixPosition2 != std::string::npos) {
        radixPosition1 = std::size(numerator) - (radixPosition1 + 1);
        radixPosition2 = std::size(tempDenominator) - (radixPosition2 + 1);
        if (radixPosition1 > radixPosition2) {
            distance = radixPosition1 - radixPosition2;
            for (auto i{ 0u }; i < distance; ++i)
                tempDenominator.push_back('0');
            numerator.erase(std::begin(numerator) + numerator.find('.'));
            tempDenominator.erase(std::begin(tempDenominator) + tempDenominator.find('.'));
        }
        else if (radixPosition1 < radixPosition2) {
            distance = radixPosition2 - radixPosition1;
            for (auto i{ 0u }; i < distance; ++i)
                numerator.push_back('0');
            tempDenominator.erase(std::begin(tempDenominator) + tempDenominator.find('.'));
            numerator.erase(std::begin(numerator) + numerator.find('.'));
        }
        else {
            tempDenominator.erase(std::begin(tempDenominator) + tempDenominator.find('.'));
            numerator.erase(std::begin(numerator) + numerator.find('.'));
        }
    }
    //division algorithm
    std::string answer{ "" };
    if (std::size(tempDenominator) > std::size(numerator)) {
        answer = "0." + answer;
        numerator += '0';
        while (std::size(tempDenominator) > std::size(numerator)) {
            numerator += '0';
            answer += '0';
        }
    }
    auto [numeratorAsInt, denominatorAsInt] = std::tuple(std::stoull(numerator), std::stoull(tempDenominator));
    unsigned long long remainder{ 1 }, dividend{ numeratorAsInt }, divisor{ denominatorAsInt };
    remainder = dividend % divisor;
    auto quotient = std::to_string(dividend / divisor);
    answer += quotient;
    if (remainder < divisor && remainder != 0) answer += '.';
    while (std::size(answer) < 19 && remainder > 0) {
        if (remainder > 0) {
            remainder *= 10;
            while (remainder < divisor) {
                remainder *= 10;
                answer += '0';
            }
            dividend = remainder;
        }
        remainder = dividend % divisor;
        auto quotient = std::to_string(dividend / divisor);
        answer += quotient;
    }
    return answer;
}

Number Number::operator^(Number const& other) {
    try {
        unsigned long long num1 = std::stoull(number);
        unsigned long long num2 = std::stoull(other.number);
        unsigned long long result = num1 ^ num2;
        return Number{ std::to_string(result) };
    }
    catch (std::exception const&) {
        return Number{ "0" };
    }
}
Number Number::operator|(Number const& other) {
    try {
        unsigned long long num1 = std::stoull(number);
        unsigned long long num2 = std::stoull(other.number);
        unsigned long long result = num1 | num2;
        return Number{ std::to_string(result) };
    }
    catch (std::exception const&) {
        return Number{ "0" };
    }
}
Number Number::operator&(Number const& other) {
    try {
        unsigned long long num1 = std::stoull(number);
        unsigned long long num2 = std::stoull(other.number);
        unsigned long long result = num1 & num2;
        return Number{ std::to_string(result) };
    }
    catch (std::exception const&) {
        return Number{ "0" };
    }
}
Number Number::operator<< (Number const& other) {
    try {
        unsigned long long num1 = std::stoull(number);
        unsigned long long num2 = std::stoull(other.number);
        unsigned long long result = num1 << num2;
        return Number{ std::to_string(result) };
    }
    catch (std::exception const&) {
        return Number{ "0" };
    }
}

Number Number::operator>> (Number const& other) {
    try {
        unsigned long long num1 = std::stoull(number);
        unsigned long long num2 = std::stoull(other.number);
        unsigned long long result = num1 >> num2;
        return Number{ std::to_string(result) };
    }
    catch (std::exception const&) {
        return Number{ "0" };
    }
}

Number Number::operator! () {
    std::vector<Number> num;
    auto [result, zero, one, counter] = std::tuple(Number{ "1" }, Number{ "1" }, Number{ "1" }, *this);
    std::function<Number(Number, Number)> multiplies = [](Number a, Number b) {return a * b; };
    for (; counter > zero; counter = counter - one) {
        num.emplace_back(counter);
    }
    result = stl::parallel_accumulate(std::begin(num), std::end(num), Number{ "1" }, multiplies);
    return result;
}

const Number Number::operator= (const Number & otherNumber) {
    if (*this != otherNumber) {
        number.clear();
        number = otherNumber.number;
    }
    return *this;
}

const Number Number::operator= (Number && otherNumber) {
    this->number = std::exchange(otherNumber.number, "0");
    return *this;
}

bool Number::operator> (const Number& otherNumber) {
    Number m_number{ *this }, m_otherNumber{ otherNumber };
    if (m_number.number.front() == '-' && m_otherNumber.number.front() != '-')
        return false;
    else if (m_number.number.front() != '-' && m_otherNumber.number.front() == '-')
        return true;
    else if (m_number.number.front() == '-' && m_otherNumber.number.front() == '-') {
        m_number.number.erase(std::begin(m_number.number));
        m_otherNumber.number.erase(std::begin(m_otherNumber.number));
        return m_number < m_otherNumber;
    }
    else {
        if (std::size(m_number.number) != std::size(m_otherNumber.number))
            makeEqualLength(m_number.number, m_otherNumber.number);
        for (std::size_t i{ 0 }; i < m_number.number.size(); ++i) {
            if (m_number.number[i] != m_otherNumber.number[i])
                return m_number.number[i] > m_otherNumber.number[i];
        }
        return false;
    }
}

bool Number::operator< (const Number& otherNumber) {
    return !(*this > otherNumber);
}

bool Number::operator== (const Number & otherNumber) {
    return number.compare(otherNumber.number) == 0;
}

bool Number::operator!= (const Number & otherNumber) {
    return !(this->number == otherNumber.number);
}
