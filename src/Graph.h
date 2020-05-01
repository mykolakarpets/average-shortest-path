//
// Created by mkarpetsp on 19.04.20.
//
// Requirements for Graph class:
//      * create from a list of vertices, from matrix, from file (GraphML)?
//      * get a number of vertices/edges
//      * check whether edges are adjacent
//      * list all the neighbours of a vertice
//      * add/delete an edge
//      * assign a value to an edge/vertice
//
//      Canvas

#ifndef AVERAGE_SHORTEST_PATH_GRAPH_H
#define AVERAGE_SHORTEST_PATH_GRAPH_H

#include <list>
#include <vector>
#include <map>

#include <functional>

#include "Canvas.h"

#include "Vertice.h"
#include "Edge.h"

template<typename VValue, typename EValue>
class Graph {
    using VPtrList = typename Canvas<VValue, EValue>::VerticesPtrList;
    using EPtrList = typename Canvas<VValue, EValue>::EdgesPtrList;

    Graph(VPtrList vertices, EPtrList edges, Canvas<VValue, EValue>& canvas);

    bool add_edge(Edge<Vertice<VValue>, EValue> edge);

    void num_vervices();
    void num_edges();

    bool adjacent(Vertice<VValue>& v1, Vertice<VValue>& v2);
    VPtrList neighbours(Vertice<VValue>& v);

private:
    std::map<std::shared_ptr<Vertice<VValue>>, EPtrList> _vertices;
    std::shared_ptr<Canvas<VValue, EValue>> _canvas;
};

#endif //AVERAGE_SHORTEST_PATH_GRAPH_H
