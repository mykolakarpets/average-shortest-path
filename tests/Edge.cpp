//
// Created by mkarpetsp on 20.04.20.
//

#include <gtest/gtest.h>

#include "../src/Vertice.h" // TODO: fix
#include "../src/Edge.h" // TODO: fix

class EdgeTest: public ::testing::Test {
protected:
    typedef int VerticeValueType;
    typedef Vertice<VerticeValueType> VerticeType;

    typedef int EdgeValueType;
    typedef Edge<VerticeType, EdgeValueType> EdgeType;

    VerticeValueType vertice_id[2] = {10, 11};
    std::shared_ptr<VerticeType> v0 = std::make_shared<VerticeType>(vertice_id[0]);
    std::shared_ptr<VerticeType> v1 = std::make_shared<VerticeType>(vertice_id[1]);
    EdgeValueType edge_value = 20;
};

TEST_F(EdgeTest, create) {
    EdgeType e(EdgeType::VerticePtrPair(v0, v1), edge_value);

    ASSERT_EQ(e.get_vertices(), std::make_pair(std::shared_ptr<VerticeType>(v0), std::shared_ptr<VerticeType>(v1)));
    ASSERT_EQ(e.get_value(), edge_value);
}

TEST_F(EdgeTest, int_value_get_set) {
    EdgeType e(std::make_pair(v0, v1), edge_value);
    EdgeValueType new_value = 21;

    e.set_value(new_value);

    ASSERT_EQ(e.get_value(), new_value);
}
