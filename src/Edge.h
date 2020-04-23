//
// Created by mkarpetsp on 20.04.20.
//

#ifndef AVERAGE_SHORTEST_PATH_EDGE_H
#define AVERAGE_SHORTEST_PATH_EDGE_H


#include <utility>
#include <memory>

template<typename Vertice, typename Value>
class Edge {
public:
    typedef std::pair<std::shared_ptr<Vertice>, std::shared_ptr<Vertice>> VerticePtrPair;

    Edge() = delete;
    Edge(VerticePtrPair vertices, Value value = {}): _vertices(std::move(vertices)), _value(value) {};

    Value get_value() { return _value; }
    void set_value(Value value) { this->_value = value; }

    VerticePtrPair get_vertices() { return _vertices; };

private:
    VerticePtrPair _vertices;
    Value _value;
};


#endif //AVERAGE_SHORTEST_PATH_EDGE_H
