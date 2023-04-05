#include <iostream>
#include <fstream>
#include <string>

#include "Matrix.h"
#include "NodeMap.h"
#include "operations.h"

using namespace std;

int main(int argc, char **argv) {
    int result;
    string mode;
    string filename;

    if (argc == 2) {
        filename = argv[1];
    }
    else {
        cout << "Data file name: ";
        cin >> filename;
    }

    ifstream f(filename);
    while (!f.is_open()) {
        cout << "Unable to open file." << endl;
        cout << "Data file name: ";
        cin >> filename;
        f.open(filename);
    }

    cout << "Loading data...   ";
    NodeMap map(f);
    f.close();
    Matrix mx = map.convert_to_matrix();
    cout << "Success!" << endl;

    while (true) {
        cout << endl << "Actions:" << endl
             << "  a2n  -  Find the minimal number of transfers required to travel between any two nodes" << endl
             << "  s2n  -  Find the minimal number of transfers required to travel between two selected nodes" << endl
             << "  rts  -  Find the number of possible routes between selected nodes using no more than N transfers" << endl
             << "  exp  -  Export the calculated connection table to a CSV file" << endl
             << "  q  -  Quit" << endl
             << "Choose an action: ";
        cin >> mode;


        if (mode == "a2n") {
            cout << "  Answer: " << any_nodes(mx) << endl;
        }
        else if (mode == "s2n") {
            result = selected_nodes(mx, map);
            cout << "  Answer: " << result << endl;
        }
        else if (mode == "rts") {
            result = routes(mx, map);
            cout << "  Answer: " << result << endl;
        }
        else if (mode == "exp") {
            export_matrix(mx, map);
            cout << "  Done! :)" << endl;
        }
        else if (mode == "q") {
            return 0;
        }
        else cout << "Action not found!" << endl;
    }
}
