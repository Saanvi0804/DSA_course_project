#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <queue>
using namespace std;

struct WheatProduction {
    int area_id;
    char area_name[30];
    int production;
};

class wheat_production_data {
private:
    queue<WheatProduction> data_queue;
    int global_count;

public:
    wheat_production_data();
    void welcome();
    void load_from_file();
    void display_data();
    void process_data();
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

    while (file >> global_count) {
        WheatProduction wp;
        file.ignore(); // Ignore the comma
        file.getline(wp.area_name, 30, ',');
        file >> wp.production;

        wp.area_id = global_count;
        data_queue.push(wp);

        if (global_count >= 150) {
            cout << "Maximum data limit reached.\n";
            break;
        }
    }

    file.close();
}

void wheat_production_data::display_data() {
    cout << setw(10) << "Area ID" << setw(20) << "Area Name" << setw(15) << "Production" << endl;

    queue<WheatProduction> temp_queue = data_queue;
    while (!temp_queue.empty()) {
        WheatProduction wp = temp_queue.front();
        temp_queue.pop();
        cout << setw(10) << wp.area_id
             << setw(20) << wp.area_name
             << setw(15) << wp.production << endl;
    }
}

void wheat_production_data::process_data() {
    cout << "Processing data in entry order:" << endl;
    cout << setw(10) << "Area ID" << setw(20) << "Area Name" << setw(15) << "Production" << endl;

    while (!data_queue.empty()) {
        WheatProduction wp = data_queue.front();
        data_queue.pop();
        cout << setw(10) << wp.area_id
             << setw(20) << wp.area_name
             << setw(15) << wp.production << endl;
    }
}

int main() {
    wheat_production_data engine;
    engine.welcome();

    engine.load_from_file();
    engine.display_data();
    engine.process_data();

    return 0;
}
