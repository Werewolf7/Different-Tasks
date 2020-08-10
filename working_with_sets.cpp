#include <iostream>
#include <set>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;


void output_data(const set<char>& s) {
    copy(s.begin(), s.end(), ostream_iterator<char>(cout, " "));
}


int main() {
    set<char> letters_name;
    set<char> letters_sourname;
    set<char> letters_patronymic;
    vector<string> fio{ istream_iterator<string>(cin), istream_iterator<string>() };



    letters_name.insert(fio[0].begin(), fio[0].end());
    letters_sourname.insert(fio[1].begin(), fio[1].end());
    letters_patronymic.insert(fio[2].begin(), fio[2].end());

    output_data(letters_name);
    cout << endl;
    output_data(letters_sourname);
    cout << endl;
    output_data(letters_patronymic);
    cout << endl;

    set<char> a_b;
    set_difference(letters_name.begin(), letters_name.end(),
        letters_sourname.begin(), letters_sourname.end(),
        inserter(a_b, a_b.begin())
    );

    set<char> R;
    set_difference(a_b.begin(), a_b.end(),
        letters_patronymic.begin(), letters_patronymic.end(),
        inserter(R, R.begin())
    );
    cout << "R = { ";
    output_data(a_b);
    cout << "}";
    return 0;
}