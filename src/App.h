/*
 * Copyright (C) 2022 https://github.com/nkh-lab
 *
 * This is free software. You can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 3 as published by the Free Software Foundation.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY.
 */

#pragma once

#include <memory>

#include <wx/app.h>
#include <wx/timer.h>

class App : public wxApp
{
public:
    App();
    ~App();

    bool OnInit() override;
    int OnExit() override;
    void OnInitCmdLine(wxCmdLineParser& parser) override;
    bool OnCmdLineParsed(wxCmdLineParser& parser) override;

    void OnTestModeTimer(wxTimerEvent& event);

private:
    bool test_mode_;
    std::unique_ptr<wxTimer> test_mode_timer_;
};
