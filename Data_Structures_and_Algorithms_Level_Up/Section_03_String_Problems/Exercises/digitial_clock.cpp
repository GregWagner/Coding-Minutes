#include <iostream>

std::string convert_to_digital_time(int minutes) {
    int hours = minutes / 60;
    minutes %= 60;

    std::string m_str = std::to_string(minutes);
    if (minutes == 0) {
        m_str = "00";
    } else if (minutes < 10) {
        m_str = "0" + m_str;
    }

    return std::to_string(hours) + ":" + m_str;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << (convert_to_digital_time(125) == "2:05") << '\n';
    std::cout << (convert_to_digital_time(1180) == "19:40") << '\n';
    std::cout << (convert_to_digital_time(60) == "1:00") << '\n';
}
