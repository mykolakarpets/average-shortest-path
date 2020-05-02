//
// Created by mkarpets on 19.04.20.
//

#include <algorithm>

#include "Graph.h"

template<typename VValue, typename EValue>
Graph<VValue, EValue>::Graph(const VPtrList& vertices, const EPtrList& edges, std::shared_ptr<Canvas<VValue, EValue>> canvas) {
    _canvas = canvas;

    for (auto& edge_ptr : edges) {
        auto _v = edge_ptr->get_vertices();

        _vertices[_v.first].push_back(edge_ptr);
        _vertices[_v.second].push_back(edge_ptr);
    }

    for (auto& vertice_ptr : vertices) {
        if (_vertices.find(vertice_ptr) == _vertices.end()) {
            _vertices.insert({vertice_ptr, {}});
        }
    }

    //TODO: matrix
}

template<typename VValue, typename EValue>
bool Graph<VValue, EValue>::add_edge(EPtr edge) {
    auto [v1, v2] = edge->get_vertices();

    EPtrList& v1_edges_list = _vertices[v1];
    EPtrList& v2_edges_list = _vertices[v2];

    if (std::find(v1_edges_list.begin(), v1_edges_list.end(), edge) != v1_edges_list.end()
            and std::find(v2_edges_list.begin(), v2_edges_list.end(), edge) != v2_edges_list.end()) {
        return false;
    }

    v1_edges_list.push_back(edge);
    v2_edges_list.push_back(edge);

    //TODO: matrix

    return true;
}

template<typename VValue, typename EValue>
bool Graph<VValue, EValue>::remove_edge(Graph::EPtr edge) {
    auto [v1, v2] = edge->get_vertices();

    EPtrList& v1_edges_list = _vertices[v1];
    EPtrList& v2_edges_list = _vertices[v2];

    if (std::find(v1_edges_list.begin(), v1_edges_list.end(), edge) == v1_edges_list.end()
            or std::find(v2_edges_list.begin(), v2_edges_list.end(), edge) == v2_edges_list.end()) {
        return false;
    }

    v1_edges_list.remove(edge);
    v2_edges_list.remove(edge);

    return true;
}

template<typename VValue, typename EValue>
size_t Graph<VValue, EValue>::num_vervices() {
    return _vertices.size();
}

template<typename VValue, typename EValue>
bool Graph<VValue, EValue>::adjacent(VPtr v1, VPtr v2) {
    for (auto& edge : _vertices[v1]) {
        if (edge->get_another_vertice(v1) == v2) {
            return true;
        }
    }
}

template<typename VValue, typename EValue>
typename Graph<VValue, EValue>::EPtrList Graph<VValue, EValue>::edges(VPtr v) {
    return _vertices[v];
}

