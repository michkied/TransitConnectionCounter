#ifndef TRANSITCONNECTIONCOUNTER_NODE_H
#define TRANSITCONNECTIONCOUNTER_NODE_H

#include <iostream>
#include <vector>
using namespace std;

class Node {
    string id;
    vector<string> lines;
public:
    Node();
    explicit Node(string id);
    Node operator+(const string& new_line);
    string get_id() const;
    bool is_empty() const;
    friend bool operator==(const Node& a, const Node& b);
    friend int operator%(const Node& a, const Node& b);
    friend ostream& operator<<(ostream& out, const Node& node);
};

#endif //TRANSITCONNECTIONCOUNTER_NODE_H
