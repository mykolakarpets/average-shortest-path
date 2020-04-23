//
// Created by mkarpetsp on 20.04.20.
//

#ifndef AVERAGE_SHORTEST_PATH_CANVAS_H
#define AVERAGE_SHORTEST_PATH_CANVAS_H

#include <list>
#include <memory>

#include "Vertice.h"
#include "Edge.h"

template<typename VValue, typename EValue>
class Canvas {
public:
    using VerticesPtrList = std::list<std::shared_ptr<Vertice<VValue>>>;
    using EdgesPtrList = std::list<std::shared_ptr<Edge<Vertice<VValue>, EValue>>>;

    virtual Vertice<VValue>& add_vertice(Vertice<VValue> v) = 0;
    virtual Edge<Vertice<VValue>, EValue>& add_edge(Edge<Vertice<VValue>, EValue> e) = 0;

    virtual VerticesPtrList get_vertices() = 0;
    virtual EdgesPtrList get_edges() = 0;

    virtual ~Canvas() {}; // why can't be pure virtual

//    TODO: why not working?
//    virtual ~Canvas() = 0;

    //TODO: removing edge/vertice
    //TOOD: export/import from file
};


#endif //AVERAGE_SHORTEST_PATH_CANVAS_H
