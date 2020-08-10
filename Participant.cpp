#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
class Participant {
private:
    std::string surname;
    std::string name;
    int class_;
    int points;
public:
    friend std::istream& operator >>(std::istream& in, Participant& prtp);
    int get_points() const;
    std::string get_surname() const;
    std::string get_name() const;
    Participant();
    ~Participant();
};
std::istream& operator >>(std::istream& in, Participant& prtp) {
    in >> prtp.surname >> prtp.name >> prtp.class_ >> prtp.points;
    return in;
}

int Participant::get_points() const { return this->points; }

std::string Participant::get_surname() const { return this->surname; }

std::string Participant::get_name() const { return this->name; }

Participant::Participant() : surname{ "" }, name{ "" }, class_{ 0 }, points{ 0 }{}
Participant::~Participant() {}

void input_data(const int& N, std::vector<Participant>& arr_participant) {
    Participant tmp;
    for (int i = 0; i < N; i++) {
        std::cin >> tmp;
        arr_participant.push_back(tmp);
    }
}

void determine_winner(std::vector<Participant>& arr_participant) {

    std::vector<Participant>::iterator max_points_greater_200 = std::max_element(
        arr_participant.begin(), 
        arr_participant.end(),
        [](const Participant& el1, const Participant& el2) 
        { return el1.get_points() < el2.get_points() && el2.get_points() > 200; }
    );
    int quantity_greater_200 = std::accumulate(
        arr_participant.begin(), 
        arr_participant.end(),
        0,
        [max_points_greater_200](int counter, const Participant& el) 
        { return (el.get_points() > 200 && el.get_points() == max_points_greater_200->get_points() ? counter += 1 : counter += 0); }
    );
    std::vector<Participant>::iterator max_points_less_200 = std::max_element(
        arr_participant.begin(),
        arr_participant.end(),
        [](const Participant& el1, const Participant& el2) 
        { return el1.get_points() < el2.get_points() && el2.get_points() < 200; }
    );
    int quantity_less_200 = std::accumulate(
        arr_participant.begin(), 
        arr_participant.end(),
        0,
        [max_points_less_200](int counter, const Participant& el) { return (el.get_points() < 200 && el.get_points() == max_points_less_200->get_points() ? counter += 1 : counter += 0); }
    );
    if (quantity_less_200 == 1) { std::cout << max_points_less_200->get_surname() << " " << max_points_less_200->get_name() << std::endl; }

    else { std::cout << quantity_less_200 << std::endl; }
}

int main() {
    int N{ 0 };
    std::cout << "¬ведите N" << std::endl;
    std::cin >> N;
    std::vector<Participant> arr_participant(N);
    input_data(N, arr_participant);
    determine_winner(arr_participant);
}