#include "operations.h"

int changes(const Matrix& mx) {
    Matrix mx2 = mx;
    int i = 0;
    while (mx2.has_zero()){
        mx2 = mx2 * mx;
        ++i;
    }
    return i;
}

vector<Node> ask42nodes(const NodeMap& map) {
    string nodeA, nodeB;
    while (true) {
        cout << "  Name of the first node:";
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

int ask4changes() {
    int num;
    while (true) {
        cout << "  N (number of changes):";
        cin >> num;
        if (!cin.fail()) break;
        cin.clear();
        cin.ignore(256,'\n');
        cout << "    Not a valid number." << endl;
    }
    return num;
}

int min_changes(const Matrix& mx, const NodeMap& map) {
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

int connections(const Matrix& mx, const NodeMap& map) {
    vector<Node> v = ask42nodes(map);
    int a = map.node_position(v[0]);
    int b = map.node_position(v[1]);
    return mx.pwr(ask4changes())[a][b];
}
