#include <fstream>
#include <sstream>
#include "NodeMap.h"


NodeMap::NodeMap(basic_ifstream<char>& f) {
    string line, node_id, line_name;
    while (getline(f,line)) {
        istringstream _(line);
        while (getline(_, node_id, ' ')) {
            line_name = line.substr(0, line.find(' '));
            if (node_id != line_name)
                add_line(node_id, line_name);
        }
    }
}

Node NodeMap::operator[](const string& id) const {
    for (auto & node : nodes)
        if (node.get_id() == id) return node;
    return {};
}

NodeMap NodeMap::operator+(const Node& node) {
    nodes.push_back(node);
    return *this;
}

ostream &operator<<(ostream &out, const NodeMap& map) {
    for (const auto& node : map.nodes)
        out << node;
    return out;
}

void NodeMap::add_node(const string& id) {
    for (auto & node : nodes)
        if (node.get_id() == id) return;
    Node blank_node(id);
    nodes.push_back(blank_node);
}

void NodeMap::add_line(const string& id, const string& line) {
    this->add_node(id);
    for (auto & node : nodes)
        if (node.get_id() == id)
            node = node + line;
}

Matrix NodeMap::convert_to_matrix() {
    int conn;
    Matrix mx(nodes.size());
    for (int i = 0; i < nodes.size(); ++i) {
        mx[i][i] = 1;
        for (int j = i+1; j < nodes.size(); ++j) {
            conn = nodes[i] % nodes[j];
            mx[i][j] = conn;
            mx[j][i] = conn;
        }
    }
    return mx;
}

int NodeMap::node_position(const Node& node) const {
    for (int i = 0; i < nodes.size(); ++i)
        if (nodes[i] == node) return i;
    return -1;
}

vector<Node> NodeMap::get_nodes() const {
    return nodes;
}
