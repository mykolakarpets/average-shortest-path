//
// Created by mkarpetsp on 20.04.20.
//

#include "UnsignedCanvas.h"

UnsignedCanvas::VerticeType& UnsignedCanvas::add_vertice(VerticeType v) {
    vertices.push_back(std::make_shared<VerticeType>(v));
    return *vertices.back();
}

UnsignedCanvas::EdgeType& UnsignedCanvas::add_edge(EdgeType e) {
    edges.push_back(std::make_shared<EdgeType>(e));
    return *edges.back();
}

UnsignedCanvas::VerticesPtrList UnsignedCanvas::get_vertices() {
    return vertices;
}

UnsignedCanvas::EdgesPtrList UnsignedCanvas::get_edges() {
    return edges;
}
