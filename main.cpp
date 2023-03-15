#include <iostream>
#include <fstream>
#include <string>

#include "Matrix.h"
#include "NodeMap.h"
#include "operations.h"

using namespace std;

int main(int argc, char **argv) {
    int result;

    if (argc < 2) {
        cout << "Data file name not provided";
        return 1;
    }
    ifstream f(argv[1]);
    if (!f.is_open()) {
        cout << "Unable to open file";
        return 1;
    }

    cout << "Loading data...   ";
    NodeMap map(f);
    f.close();
    Matrix mx = map.convert_to_matrix();
    cout << "Success!";

    while (true) {
        string mode;

        cout << endl << "Actions:" << endl
        << "  a2n  -  Find the minimal number of transfers required to travel between any two nodes" << endl
        << "  s2n  -  Find the minimal number of transfers required to travel between two selected nodes" << endl
        << "  rts  -  Find the number of possible routes between selected nodes using no more than N transfers" << endl
        << "  q  -  Quit" << endl
        << "Choose an action:";

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
        else if (mode == "q") {
            return 0;
        }
    }
}
