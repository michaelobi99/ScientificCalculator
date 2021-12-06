#include "numbersystem.h"

using namespace stl;

void NumberSystem::setValue(std::string const& num) {
    bool isParseable{ true };
    for (const auto& elem : num) {
        if ((!isdigit(elem)) && (elem != '.') && (elem != '-')) {
            isParseable = false;
            break;
        }
    }
    if (isParseable)
        decimalNumber = num;
    else
        decimalNumber = "0";
    binaryNumber = decToBinary();
    octalNumber = decToOct();
    hexNumber = decToHex();
}

std::string NumberSystem::binaryNotation() {
    return binaryNumber;
}
std::string NumberSystem::octalNotation() {
    return octalNumber;
}
std::string NumberSystem::hexNotation() {
    return hexNumber;
}

std::string NumberSystem::decToBinary() {
    auto m_decimalNumber = decimalNumber;
    auto isNegative = (m_decimalNumber.front() == '-');
    std::optional<std::string> decPart{};
    std::string integerPart;
    if (isNegative)
        m_decimalNumber.erase(std::begin(m_decimalNumber));

    if (auto radixPosition = m_decimalNumber.find('.'); radixPosition != std::string::npos) {
        integerPart = std::string{ std::begin(m_decimalNumber), std::begin(m_decimalNumber) + radixPosition };
        decPart = "0." + std::string{std::begin(m_decimalNumber) + radixPosition + 1, std::end(m_decimalNumber)};
    }
    else {
        integerPart = m_decimalNumber;
        decPart = std::nullopt;
    }

    std::string integerPartAsBinary{ "" }, decimalPartAsBinary{ "" };
    if (decPart.has_value()) {
        double result{ 0.0 };
        //std::from_chars_result res = std::from_chars(decPart.value().data(), decPart.value().data() + decPart.value().size(), result);
        result = std::stold(decPart.value());
        decimalPartAsBinary = fractionalPartToBinary(result);
    }

    ullType quotient{std::stoull(integerPart) }, remainder;

    if (quotient == 0)
        integerPartAsBinary = "0";

    while (quotient > 0) {
        remainder = quotient % 2;
        quotient /= 2;
        integerPartAsBinary += std::to_string(remainder);
    }
    std::reverse(std::begin(integerPartAsBinary), std::end(integerPartAsBinary));
    std::string prefix1((4 - (std::size(integerPartAsBinary) % 4)), '0');//for hex form

    if (std::size(prefix1) < 4)
        integerPartAsBinary = prefix1 + integerPartAsBinary;

    std::string answer{ "" };
    for (std::size_t i{ 0 }; i < std::size(integerPartAsBinary); ++i) {
        if (i % 4 == 0 && i != 0)
            answer += ' ';
        answer += integerPartAsBinary[i];
    }
    if (decPart.has_value())
        answer = answer + '.' + decimalPartAsBinary;
    if (isNegative)
        answer = "-" + answer;

    return answer;
}

std::string NumberSystem::fractionalPartToBinary(double const& decimalPart) {
    std::uint32_t remainder{ 0 };
    double quotient{ decimalPart };
    std::string answer{ "" };
    std::string answerAsOct{ "" };
    unsigned counter1{ 0 };

    while (std::size(answer) < 14) {
        if (counter1 == 4) {
            answer += ' ';
            counter1 = 0;
        }
        remainder = std::uint32_t(quotient * 2);
        auto t = std::to_string(quotient * 2);
        t.at(0) = '0';
        quotient = std::stof(t);
        answer += std::to_string(remainder);
        answerAsOct += std::to_string(remainder);
        ++counter1;
    }
    return answer;
}

std::string NumberSystem::decToOct() {
    auto isNegative{ false };
    std::string m_binaryNumber = binaryNumber;
    for (std::string::iterator iter = m_binaryNumber.begin(); iter != m_binaryNumber.end(); ++iter) {
        if (*iter == ' ')
            m_binaryNumber.replace(std::distance(std::begin(m_binaryNumber), iter), 1, "");
    }
    if (*m_binaryNumber.begin() == '-') {
        isNegative = true;
        m_binaryNumber.erase(std::begin(m_binaryNumber));
    }
    std::unordered_map<std::string, std::string> binaryOctEquivalent{
    {"000", "0"}, {"001", "1"}, {"010", "2"}, {"011", "3"},
    {"100", "4"}, {"101", "5"}, {"110", "6"}, {"111", "7"}
    };
    size_t radixPosition = m_binaryNumber.find('.'), length;
    if (radixPosition != std::string::npos)
        length = std::distance(std::begin(m_binaryNumber), std::begin(m_binaryNumber) + radixPosition);
    else
        length = std::size(m_binaryNumber);

    std::string prefix((3 - (std::size(m_binaryNumber) % 3)), '0');//for oct form
    if (std::size(prefix) > 0)
        m_binaryNumber = prefix + m_binaryNumber;

    std::string answer{ "" };
    std::string tempAnswer{ "" };
    for (auto const& elem : m_binaryNumber) {
        if (elem == '.') {
            answer += elem;
            tempAnswer.clear();
            continue;
        }
        tempAnswer += elem;
        if (std::size(tempAnswer) == 3) {
            answer += binaryOctEquivalent[tempAnswer];
            tempAnswer.clear();
        }
    }
    if (isNegative)
        answer = "-" + answer;
    return answer;
}

std::string NumberSystem::decToHex() {
    std::string m_binaryNumber = binaryNumber;
    auto isNegative{ false };
    if (*m_binaryNumber.begin() == '-') {
        isNegative = true;
        m_binaryNumber.erase(std::begin(m_binaryNumber));
    }
    std::unordered_map<std::string, std::string> binaryHexEquivalent{
     {"0000", "0"}, {"0001", "1"}, {"0010", "2"}, {"0011", "3"}, {"0100", "4"}, {"0101", "5"},
     {"0110", "6"}, {"0111", "7"}, {"1000", "8"}, {"1001", "9"}, {"1010", "A"},
     {"1011", "B"}, {"1100", "C"}, {"1101", "D"}, {"1110", "E"}, {"1111", "F"}
    };
    std::string integerPart{ "" };
    std::optional<std::string> decimalPart{ std::nullopt };
    auto radixPosition = m_binaryNumber.find('.');
    if (radixPosition != std::string::npos) {
        decimalPart = { m_binaryNumber, radixPosition + 1, m_binaryNumber.size() - radixPosition };
        integerPart = { m_binaryNumber, 0, radixPosition };
    }
    else
        integerPart = m_binaryNumber;

    std::string answer{ "" };
    auto split = [](std::string_view number) {
        std::vector<std::string> ans;
        std::string tempStr;
        for (auto elem : number) {
            if (elem == ' ') {
                ans.push_back(tempStr);
                tempStr.clear();
            }
            else tempStr += elem;
        }
        ans.push_back(tempStr);
        return ans;
    };
    for (auto& elem : split(integerPart)) {
        answer += binaryHexEquivalent[elem];
    }
    if (decimalPart.has_value()) {
        answer += '.';
        for (auto& elem : split(decimalPart.value())) {
            answer += binaryHexEquivalent[elem];
        }
    }
    if (isNegative)
        answer = "-" + answer;
    return answer;
}
