//
// Created by mkarpetsp on 20.04.20.
//

#ifndef AVERAGE_SHORTEST_PATH_UNSIGNEDCANVAS_H
#define AVERAGE_SHORTEST_PATH_UNSIGNEDCANVAS_H

#include <list>
#include <functional>

#include "Canvas.h"
#include "Vertice.h"
#include "Edge.h"

class UnsignedCanvas : public Canvas<unsigned, unsigned> {
public:
    using VerticesPtrList = Canvas<unsigned, unsigned >::VerticesPtrList;
    using EdgesPtrList = Canvas<unsigned, unsigned >::EdgesPtrList;

    using VerticeValue = unsigned;
    using VerticeType = Vertice<VerticeValue>;

    using EdgeValue = unsigned;
    using EdgeType = Edge<VerticeType, EdgeValue>;

    VerticeType& add_vertice(VerticeType v) override;
    EdgeType& add_edge(EdgeType e) override;

    VerticesPtrList get_vertices() override;
    EdgesPtrList get_edges() override;

    void myOwnFuncion() {};

private:
    EdgesPtrList edges;
    VerticesPtrList vertices;
};


#endif //AVERAGE_SHORTEST_PATH_UNSIGNEDCANVAS_H
