#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

namespace Window
{
    const int MAX_X = 30;
    const int MAX_Y = 40;
    class Pane
    {
    public:
        Pane();
        ~Pane();
        void size(int x, int y);
        void move(int x, int y);
        void show();
    private:\
        static int count;
               int x;
               int y;
    };
//  #5  USING directive and USING declaration:
    int value1 = 20;
    int value2 = 40;
}

int Window::Pane::count = 0;
Window::Pane::Pane() : x(0), y(0) {}
Window::Pane::~Pane() {}

void Window::Pane::size(int x, int y)
{
    if (x < Window::MAX_X && x > 0)
        Pane::x = x;
    if (y < Window::MAX_Y && y > 0)
        Pane::y = y;
}

void Window::Pane::move(int x, int y)
{
    if (x < Window::MAX_X && x > 0)
        Pane::x = x;
    if (y < Window::MAX_Y && y > 0)
        Pane::y = y;
}

void Window::Pane::show()
{
    std::cout << "\nx " << Pane::x;
    std::cout << "\ny " << Pane::y << std::endl;
}

#endif