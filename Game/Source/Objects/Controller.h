//
// Copyright (c) 2022 Jimmy Lord
//
// This software is provided 'as-is', without any express or implied warranty.  In no event will the authors be held liable for any damages arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.

#pragma once

class Controller
{
public:
    enum Mask
    {
        Up      = 1<<0,
        Down    = 1<<1,
        Left    = 1<<2,
        Right   = 1<<3,
        Action  = 1<<4,
        CamLeft = 1<<5,
        CamRight= 1<<6,
        CamUp   = 1<<7,
        CamDown = 1<<8,
        DigDown = 1<<9,
        DigUp   = 1<<10
    };

    Controller();
    virtual ~Controller();

    void StartFrame();
    void OnEvent(fw::Event* pEvent);

    bool IsHeld(Mask mask);
    bool WasPressed(Mask mask);
    bool WasReleased(Mask mask);

protected:
    unsigned int m_Flags = 0;
    unsigned int m_OldFlags = 0;
};
