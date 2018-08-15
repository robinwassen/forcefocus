/*
 * Copyright 2018 Robin Andersson <me@robinwassen.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "./forcefocus.h"

#include <windows.h>

namespace forcefocus {
  void FocusWindow(unsigned char* handleBuffer) {
    LONG_PTR handle = *reinterpret_cast<LONG_PTR*>(handleBuffer);
    HWND hwnd = (HWND)(LONG_PTR)handle;

    // To unlock SetForegroundWindow we need to imitate pressing the Alt key
    // This circumvents the ForegroundLockTimeout in Windows 10
    bool pressed = false;
    if ((GetAsyncKeyState(VK_MENU) & 0x8000) == 0) {
      pressed = true;
      keybd_event(VK_MENU, 0, KEYEVENTF_EXTENDEDKEY | 0, 0);
    }

    SetForegroundWindow(hwnd);
    SetFocus(hwnd);

    if (pressed) {
      keybd_event(VK_MENU, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
    }
  }
}  // namespace forcefocus
