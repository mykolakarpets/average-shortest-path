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
    typedef std::shared_ptr<Vertice> VPtr;
    typedef std::pair<VPtr, VPtr> VerticePtrPair;

    Edge() = delete;
    explicit Edge(VPtr v1, VPtr v2, Value value = {}) : _v1(v1), _v2(v2), _value(value) {};

    Value get_value() { return _value; }
    void set_value(Value value) { this->_value = value; }

    VerticePtrPair get_vertices() { return std::make_pair(_v1, _v2); };

private:
    VPtr _v1, _v2;
    Value _value;
};


#endif //AVERAGE_SHORTEST_PATH_EDGE_H
