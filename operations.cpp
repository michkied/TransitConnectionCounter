#include <fstream>
#include "operations.h"

vector<Node> ask42nodes(const NodeMap& map) {
    string nodeA, nodeB;
    while (true) {
        cout << "  Name of the first node: ";
        cin >> nodeA;
        if (!map[nodeA].is_empty()) break;
        cout << "    Node with this name does not exist." << endl;
    }

    while (true) {
        cout << "  Name of the second node:";
        cin >> nodeB;
        if (!map[nodeB].is_empty()) break;
        cout << "    Node with this name does not exist." << endl;
    }

    vector<Node> v;
    v.push_back(map[nodeA]);
    v.push_back(map[nodeB]);
    return v;
}

int ask4transfers() {
    int num;
    while (true) {
        cout << "  Number of transfers: ";
        cin >> num;
        if (!cin.fail()) break;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "    Not a valid number." << endl;
    }
    return num;
}

string ask4separator() {
    string separator;
    cout << "  CSV field separator (default ;) : ";
    cin >> separator;
    if (separator.empty()) {
        separator = ";";
    }
    return separator;
}

int any_nodes(const Matrix& mx) {
    Matrix mx2 = mx;
    int i = 0;
    while (mx2.has_zero()){
        mx2 = mx2 * mx;
        ++i;
    }
    return i;
}

int selected_nodes(const Matrix& mx, const NodeMap& map) {
    vector<Node> v = ask42nodes(map);
    int a = map.node_position(v[0]);
    int b = map.node_position(v[1]);
    Matrix mx2 = mx;
    int i = 0;

    while (mx2[a][b] == 0) {
        mx2 = mx2 * mx;
        ++i;
    }

    return i;
}

int routes(const Matrix& mx, const NodeMap& map) {
    vector<Node> v = ask42nodes(map);
    int a = map.node_position(v[0]);
    int b = map.node_position(v[1]);
    return mx.pwr(ask4transfers()+1)[a][b];
}

void export_matrix(const Matrix& mx, const NodeMap& map) {
    int num = ask4transfers()+1;
    string separator = ask4separator();
    Matrix matrix = mx.pwr(num);

    ofstream file("output.csv");
    for (auto & node : map.get_nodes()) {
        file << separator << node.get_id();
    }
    file << endl;

    for (auto & node : map.get_nodes()) {
        file << node.get_id();
        for (auto & connections: matrix[map.node_position(node)]) {
            file << separator << connections;
        }
        file << endl;
    }
    file.close();
}