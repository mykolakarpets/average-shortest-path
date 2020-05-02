//
// Created by mkarpetsp on 01.05.20.
//

#include <gtest/gtest.h>

#include "Graph.h"
#include "UnsignedCanvas.h"

class GraphTest : public ::testing::Test {
protected:
    void SetUp() override {
        for (auto id : v_ids) {
            v_arr.push_back(std::make_shared<VType>(id));
        }
        v_list = {v_arr.begin(), v_arr.end()};

        e_arr.push_back(std::make_shared<EType>(v_arr[0], v_arr[1], e_vals[0]));
        e_arr.push_back(std::make_shared<EType>(v_arr[2], v_arr[3], e_vals[1]));
        e_list = {e_arr.begin(), e_arr.end()};

        g = new Graph<VValue, EValue>(v_list, e_list, canvas);
    }

    void TearDown() override {
        delete g;
    }

protected:
    typedef unsigned VValue;
    typedef Vertice<VValue> VType;

    typedef unsigned EValue;
    typedef Edge<VType, EValue> EType;

    typedef std::shared_ptr<VType> VPtr;
    typedef std::shared_ptr<EType> EPtr;

    std::shared_ptr<UnsignedCanvas> canvas = std::make_shared<UnsignedCanvas>();

    VValue v_ids[5] = {0, 1, 2, 3, 4};
    std::vector<VPtr> v_arr;
    std::list<VPtr> v_list;

    EValue e_vals[2] = {10, 11};
    std::vector<EPtr> e_arr;
    std::list<EPtr> e_list;

    Graph<VValue, EValue> *g ;
};

TEST_F(GraphTest, add_edge) {
    EValue new_edge_value = 12;
    EPtr new_edge {std::make_shared<EType>(v_arr[0], v_arr[2], new_edge_value)};

    // No such edge in the graph before
    EXPECT_TRUE(g->add_edge(new_edge));

    // Edge already is a part of the graph
    EXPECT_FALSE(g->add_edge(new_edge));

    // Newly created edge connected the vertices
    EXPECT_TRUE(g->adjacent(v_arr[0], v_arr[2]));
}

TEST_F(GraphTest, adjacent) {
    EXPECT_TRUE(g->adjacent(v_arr[0], v_arr[1]));
    EXPECT_TRUE(g->adjacent(v_arr[2], v_arr[3]));

    EXPECT_FALSE(g->adjacent(v_arr[0], v_arr[2]));
    EXPECT_FALSE(g->adjacent(v_arr[0], v_arr[3]));
    EXPECT_FALSE(g->adjacent(v_arr[1], v_arr[2]));
    EXPECT_FALSE(g->adjacent(v_arr[1], v_arr[3]));

    EXPECT_FALSE(g->adjacent(v_arr[0], v_arr[0]));
}

TEST_F(GraphTest, num_vertices) {
    size_t expected_vertices_num = sizeof(v_ids) / sizeof(typeof(v_ids[-1]));

    ASSERT_EQ(g->num_vervices(), expected_vertices_num);
}

TEST_F(GraphTest, Edges) {
    auto v0_edges = g->edges(v_arr[0]);
    auto v2_edges = g->edges(v_arr[2]);

    ASSERT_TRUE(std::find(v0_edges.begin(), v0_edges.end(), e_arr[0]) != v0_edges.end());
    ASSERT_TRUE(std::find(v2_edges.begin(), v2_edges.end(), e_arr[1]) != v2_edges.end());
}
