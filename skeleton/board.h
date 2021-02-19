#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "pieces.h"

#define SIZE        8

struct EnumClassHash {
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

class Board {
 private:
    std::vector<std::vector<Piece*>> *board;
    void add_piece(Piece *piece);
    void add_piece(Piece *piece, Position position);

 public:
    Position w_king, b_king;

    Board();
    ~Board();

    bool is_piece_at(Position position);
    Piece* get_piece_at(Position position);
    void set_piece_at(Piece *piece, Position position);

    void print_board();
};

/*
    Capture:    LSB set
    Castle:     second LSB set
    Promotion:  third LSB set
*/

class Transition {
 public:
    std::string move_string;
    Position start, end;
    Piece *taken_piece;
    bool capture, promotion, castle, enPassant;

    Transition(std::string move_string, bool p, bool c, bool e, Piece* tp);
};
