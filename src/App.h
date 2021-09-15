#pragma once

#include <MainWindow.h>
#include <memory>

class App : public wxApp
{
public:
    App() = default;
    ~App();

    bool OnInit() override;
    int OnExit() override;
};
