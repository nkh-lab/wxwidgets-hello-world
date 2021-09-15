#include "MainWindow.h"

#include <iostream>

MainWindow::MainWindow(
    wxWindow* parent,
    wxWindowID id,
    const wxString& title,
    const wxPoint& pos,
    const wxSize& size,
    long style,
    const wxString& name)
    : wxFrame(parent, id, title, pos, size, style, name)
{
}

MainWindow::~MainWindow()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
