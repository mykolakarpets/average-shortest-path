//
// Created by mkarpetsp on 20.04.20.
//

#include <gtest/gtest.h>

#include "../src/Vertice.h" // TODO: fix

class VerticeTest: public ::testing::Test {
protected:
    void SetUp() override {
        canvas = new int();
    }

    void TearDown() override {
        delete canvas;
    }

    typedef int VerticeIDType;
    VerticeIDType id = 10;
    int *canvas;
};

TEST_F(VerticeTest, create) {
    Vertice<VerticeIDType> v(id, canvas);

    ASSERT_EQ(v.get_id(), id);
    ASSERT_EQ(v.get_canvas(), canvas);
    ASSERT_EQ((int *)(v.get_canvas()), canvas);
}

TEST_F(VerticeTest, int_id_get_set) {
    Vertice<int> v(id, canvas);
    int new_id = 11;

    v.set_id(new_id);

    ASSERT_EQ(v.get_id(), new_id);
}
