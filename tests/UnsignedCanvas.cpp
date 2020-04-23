//
// Created by mkarpetsp on 22.04.20.
//

#include <gtest/gtest.h>

#include "../src/UnsignedCanvas.h" //TODO: fix

class UnsignedCanvasTest: public ::testing::Test {
protected:
    typedef unsigned VerticeValueType;
    typedef Vertice<VerticeValueType> VerticeType;

    typedef unsigned EdgeValueType;
    typedef Edge<VerticeType, EdgeValueType> EdgeType;

    VerticeValueType vertice_id[2] {10, 11};
    UnsignedCanvas canvas;
};

TEST_F(UnsignedCanvasTest, add_vertice) {
    ASSERT_EQ(canvas.get_vertices().size(), 0);

    canvas.add_vertice(VerticeType {vertice_id[0]});
    UnsignedCanvas::VerticesPtrList vertices_list = canvas.get_vertices();

    ASSERT_EQ(vertices_list.size(), 1);
    ASSERT_EQ((*vertices_list.begin())->get_id(), vertice_id[0]);
}

TEST_F(UnsignedCanvasTest, add_edge) {
    canvas.add_vertice(VerticeType {vertice_id[1]});

    auto vertices_list = canvas.get_vertices();

    EdgeValueType edge_value = 20;
    EdgeType edge(std::make_pair(*vertices_list.begin(), *vertices_list.begin()++), edge_value);

    ASSERT_EQ(canvas.get_edges().size(), 0);

    canvas.add_edge(edge);
    auto edges_list = canvas.get_edges();

    ASSERT_EQ(edges_list.size(), 1);
    ASSERT_EQ((*edges_list.begin())->get_value(), edge_value);
}
