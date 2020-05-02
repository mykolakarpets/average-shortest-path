//
// Created by mkarpetsp on 19.04.20.
//
// Requirements for Graph class:
//      * create from a list of vertices, from matrix, from file (GraphML)?
//      * get a number of vertices/edges
//      * check whether edges are adjacent
//      * list all the edges of a vertice
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

#include "Vertice.h"
#include "Edge.h"

#include "Canvas.h"

template<typename VValue, typename EValue>
class Graph {
public:
//    typedef UnsignedCanvas::VerticesPtrList VPtrList;
    typedef std::shared_ptr<Vertice<VValue>> VPtr;
    typedef std::list<VPtr> VPtrList;
//    typedef UnsignedCanvas::EdgesPtrList EPtrList;
    typedef std::shared_ptr<Edge<Vertice<VValue>, EValue>> EPtr;
    typedef std::list<EPtr> EPtrList;

    Graph(const VPtrList& vertices, const EPtrList& edges, std::shared_ptr<Canvas<VValue, EValue>> canvas);

    // Returns false if given edge is already a part of the graph
    bool add_edge(EPtr edge);

    // Returns false if an edge is not a part of the graph
    bool remove_edge(EPtr edge);

    size_t num_vervices();
//    void num_edges();

    bool adjacent(VPtr v1, VPtr v2);
    Graph<VValue, EValue>::EPtrList edges(VPtr v);

private:
    std::map<std::shared_ptr<Vertice<VValue>>, EPtrList> _vertices;
    std::shared_ptr<Canvas<VValue, EValue>> _canvas;
};

// Explicit instantiation should be generated in each translation unit
// More here: https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
template class Graph<unsigned, unsigned>;

#endif //AVERAGE_SHORTEST_PATH_GRAPH_H
