#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

struct WheatProduction
{
    int area_id;
    char area_name[30];
    int production;
};

class wheat_production_data {
private:
    WheatProduction data[150];
    int global_count;

public:
    wheat_production_data();
    void welcome();
    void load_from_file();
    void display_data();
};

wheat_production_data::wheat_production_data() {
    global_count = 0;
}

void wheat_production_data::welcome() {
    for (int i = 0; i < 80; i++)
        cout << "*";
    cout << "\n\n\t\t\t\tDELHI WHEAT PRODUCTION DATA\n\n\n";
    for (int i = 0; i < 80; i++)
        cout << "*";
    cout << "\n\n";
}

void wheat_production_data::load_from_file() {
    ifstream file("delhi_wheat_production.txt");

    if (!file) {
        cout << "File Not Found\n";
        return;
    }

    // Read each line of the file
    while (file >> data[global_count].area_id) {
        file.ignore(); // Ignore the comma
        file.getline(data[global_count].area_name, 30, ',');
        file >> data[global_count].production;

        if (global_count < 150)
            global_count++;
        else {
            cout << "Maximum data limit reached.\n";
            break;
        }
    }

    file.close();
}

void wheat_production_data::display_data() {
    cout << setw(10) << "Area ID" << setw(20) << "Area Name" << setw(15) << "Production" << endl;
    for (int i = 0; i < global_count; i++) {
        cout << setw(10) << data[i].area_id
             << setw(20) << data[i].area_name
             << setw(15) << data[i].production << endl;
    }
}

int main() {
    wheat_production_data engine;
    engine.welcome();

    engine.load_from_file();
    engine.display_data();

    return 0;
}
