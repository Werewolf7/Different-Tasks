//Написать Программу по поиску названия издательств, выпускающих самые дешевые книги массиве.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
class Publishing {
private:
    std::string name;
    int price;
public:
    std::string get_name() const;
    int get_price() const;
    void set_name(std::string name);
    void set_price(int price);
    friend std::istream& operator >> (std::istream& in, Publishing& pbl);
    friend std::ostream& operator << (std::ostream& out, const Publishing& pbl);
};

std::string Publishing::get_name() const { return this->name; }
int Publishing::get_price() const { return this->price; }
void Publishing::set_name(std::string name) { this->name = name; }
void Publishing::set_price(int price) { this->price = price; }

std::istream& operator >> (std::istream& in, Publishing& pbl) {
    in >> pbl.name >> pbl.price;
    return in;
}

std::ostream& operator << (std::ostream& out, const Publishing& pbl) {
    out << pbl.name << std::endl << pbl.price << std::endl;
    return out;
}

int main() {
    std::vector<Publishing> arr(2);
    std::cin >> arr[0] >> arr[1];
    std::cout << arr[0] << arr[1];
    auto res = std::min_element(arr.begin(), arr.end(), [](const Publishing& el, const Publishing& el_) { return el.get_price() < el_.get_price(); });
    std::cout << std::endl << res->get_name();
}
