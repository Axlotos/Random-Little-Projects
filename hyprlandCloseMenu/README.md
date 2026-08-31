# Hyprland Close Menu

## Made for Hyprland users only
## This tool doesnt work on anything other than Hyprland

By default Hyprland doesn't have a log in screen and pressing super + L (I made it Super and L by default it's Super and M on Arch at least) closes all your windows and Hyprland.  
If you accidently press Super and L while having a bunch of windows open it can be very annoying.  
This tool is a window that pops up when you press Super + L asking if you are sure you would like to close Hyprland.

First try to run
```
gcc main.c -lSDL3 -o hyprlandCloseMenu
```

If it doesn't print anything then you succesfully compiled Hyprland Close Menu and you can move on to the setup section
If it tells you that you don't have SDL3 then read the section about installing SDL3.  
If it tells you that you don't have gcc just install it with your system's package manager such as `sudo pacman -S gcc` on Arch and try the command again.

## SDL3 Installation

You have to have SDL3 installed to use Hyprland Close Menu.  
And to have SDL3 you need cmake.  
You can just install it with your system's package manager such as `sudo pacman -S cmake` on Arch.  
Run these commands to download the SDL3 source code and compile it.
```
git clone https://github.com/libsdl-org/SDL
cd SDL
cmake -B build # this makes a folder called build and makes it ready for the build
cmake --build build # this actually builds it and puts it in the build folder
sudo cmake --install build # this takes the build folder and installs it
sudo ldconfig # this restarts all of your libraries to activate SDL
```

## Setup

Copy the compiled binary to /usr/bin (you will need to sudo cp it)  
Then open up ~/.config/hypr/hyprland.lua (this is on the new versions of Hyprland so if you don't have hyprland.lua then uhh idk)  
Go to the section that has a bunch of functions that set up your keybindings.

Mine looks like

```
---------------------
---- KEYBINDINGS ----
---------------------

local mainMod = "SUPER" -- Sets Super key as main modifier

-- Example binds, see https://wiki.hypr.land/Configuring/Basics/Binds/ for more
hl.bind(mainMod .. " + K", hl.dsp.exec_cmd(terminal))
local closeWindowBind = hl.bind(mainMod .. " + C", hl.dsp.window.close())
-- closeWindowBind:set_enabled(false)
hl.bind(mainMod .. " + L", hl.dsp.exec_cmd("hyprlandCloseMenu"))
hl.bind(mainMod .. " + E", hl.dsp.exec_cmd(fileManager))
hl.bind(mainMod .. " + B", hl.dsp.exec_cmd(browser))
hl.bind(mainMod .. " + H", hl.dsp.window.float({ action = "toggle" }))
hl.bind(mainMod .. " + R", hl.dsp.exec_cmd(menu))
hl.bind(mainMod .. " + V", hl.dsp.exec_cmd("code"))
hl.bind(mainMod .. " + P", hl.dsp.window.pseudo())
hl.bind(mainMod .. " + J", hl.dsp.layout("togglesplit"))    -- dwindle only

-- Move focus with mainMod + arrow keys
hl.bind(mainMod .. " + left",  hl.dsp.focus({ direction = "left" }))
hl.bind(mainMod .. " + right", hl.dsp.focus({ direction = "right" }))
hl.bind(mainMod .. " + up",    hl.dsp.focus({ direction = "up" }))
hl.bind(mainMod .. " + down",  hl.dsp.focus({ direction = "down" }))
```

On this line

```
hl.bind(mainMod .. " + L", hl.dsp.exec_cmd("hyprlandCloseMenu"))
```

Look at the end. It says hyprlandCloseMenu.  
It would usually be a super long command so to make it run Hyprland Close Menu just replace that command with hyprlandCloseMenu.
Now when you press Super and L (or whatever yours is like Super and M) it will ask you if you are sure.