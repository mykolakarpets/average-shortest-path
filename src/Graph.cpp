//
// Created by mkarpets on 19.04.20.
//

#include "Graph.h"

template<typename VValue, typename EValue>
Graph<VValue, EValue>::Graph(Graph::VPtrList vertices, Graph::EPtrList edges, Canvas<VValue, EValue> &canvas) {
    _canvas = std::shared_ptr<Canvas<VValue, EValue>>(&canvas);

    for(auto edge : edges) {
        auto _v = edge->get_vertices();
        _vertices[_v.first()]
    }
}

