//
// Created by mkarpetsp on 20.04.20.
//

#ifndef AVERAGE_SHORTEST_PATH_VERTICE_H
#define AVERAGE_SHORTEST_PATH_VERTICE_H

template <typename ID>
class Vertice {
public:
    Vertice() = delete;
    explicit Vertice(ID id, const void* canvas = nullptr): _id(id), _canvas(canvas) {};

    ID get_id() { return _id; };
    void set_id(ID id) { this->_id = id; }

    const void *get_canvas() { return _canvas; }

private:
    ID _id;
    const void* _canvas;
};


#endif //AVERAGE_SHORTEST_PATH_VERTICE_H
