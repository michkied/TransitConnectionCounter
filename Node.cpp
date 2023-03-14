#include "Node.h"
#include <utility>

Node::Node() : id("NULL") {}
Node::Node(string  id) : id(std::move(id)) {}

Node Node::operator+(const string& new_line) {
    for (auto & line : lines)
        if (line == new_line) return *this;
    lines.push_back(new_line);
    return *this;
}

int operator%(const Node& a, const Node& b) {
    int num = 0;
    for (const string& i : a.lines) {
        for (const string& j : b.lines) {
            if (i == j) ++num;
        }
    }
    return num;
}

string Node::get_id() const {
    return id;
}

ostream &operator<<(ostream &out, const Node &node) {
    out << node.id << "  :  ";
    for (const auto& line : node.lines) {
        out << line << " | ";
    }
    out << endl;
    return out;
}

bool Node::is_empty() const {
    return lines.empty();
}

bool operator==(const Node &a, const Node &b) {
    return a.id == b.id;
}

