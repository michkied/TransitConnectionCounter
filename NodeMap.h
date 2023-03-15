#ifndef TRANSITCONNECTIONCOUNTER_NODEMAP_H
#define TRANSITCONNECTIONCOUNTER_NODEMAP_H

#include <iostream>
#include "Node.h"
#include "Matrix.h"

class NodeMap {
    vector<Node> nodes;
public:
    explicit NodeMap(basic_ifstream<char>& f);
    Node operator[](const string& id) const;
    NodeMap operator+(const Node& node);
    vector<Node> get_nodes() const;
    int node_position(const Node& node_to_find) const;
    void add_node(const string& id);
    void add_line(const string& node_id, const string& line);
    Matrix convert_to_matrix();
    friend ostream& operator<<(ostream& out, const NodeMap& map);
};

#endif //TRANSITCONNECTIONCOUNTER_NODEMAP_H
