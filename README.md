# **Arcade**

Arcade is a gaming platform: a program that lets the user choose a game to play and keeps a register of
player scores.
To be able to deal with the elements of your gaming plate-
form at run-time, your graphics libraries and your games
must be implemented as dynamic libraries, loaded at run-
time.

## **Requirements**

### **Libraries**
- NDK++ (arcade_ndk++.so)
- aa-lib (arcade_aalib.so)
- libcaca (arcade_libcaca.so)
- Allegro5 (arcade_allegro5.so)
- Xlib (arcade_xlib.so)
- GTK+ (arcade_gtk+.so)
- SFML (arcade_sfml.so)
- Irrlicht (arcade_irrlicht.so)
- OpenGL (arcade_opengl.so)
- Vulkan (arcade_vulkan.so)
- Qt5 (arcade_qt5.so)
- SDL (arcade_sdl2.so)
- nCurses (arcade_ncurses.so)

### **Games Libraries**
- Snake (arcade_snake.so)
- Nibbler (arcade_nibbler.so)
- Pacman (arcade_pacman.so)
- Qix (arcade_qix.so)
- Centipede (arcade_centipede.so)
- Solarfox (arcade_solarfox.so)

## **How to build**

To build Arcade, follow these steps:

    ∼/B-OOP-400> mkdir ./build
    ∼/B-OOP-400> cd ./build/
    ∼/B-OOP-400> cmake .. -G “Unix Makefiles” -DCMAKE_BUILD_TYPE=Release
    ∼/B-OOP-400> cmake --build .
    ∼/B-OOP-400> cd ..
    ∼/B-OOP-400> ls ./arcade ./lib/

## **Libraries Graphic**


Arcade includes 3 graphic libraries:

- SFML
- SDL
- NCURSES

### **Game**

Arcade includes 3 game libraries:

- Nibbler
- Snake
- Pacman

## **Usage**

    To use Arcade, run the following command:

    ∼/B-OOP-400> ./arcade lib

    Options

        lib: lib you want to use when you load the arcade game

    Commands

        P: pause
        R: Restart the games
        S: Change Speed
        A: Scoreboard
        G: change game in game
        L: change lib in game
        RIGHT_ARROW: move right
        LEFT_ARROW: move left
        UP_ARROW: move up
        DOWN_ARROW: move down

## **Documentation**

To run (for it to work you must have doxygen on your machine !)

    ∼/B-OOP-400> make doc
___________________________________________________________________________________________________________________________________________________
to clean

    ∼/B-OOP-400> make cleandoc

## **Contributors**

- Lucas Mechin: lucas.mechin@epitech.eu
- Victor Doucet: victor.doucet@epitech.eu
### **Group's leader**
- Hugo Mouraud: hugo.mouraud@epitech.eu

## **Linked groups**
### **Group 1**
- Justin Thibault: justin.thibault@epitech.eu
- Hugo Martins-Gandra: hugo.martins-gandra@epitech.eu
- Ethan Saux: ethan.saux@epitech.eu
### **Group 2**
- Tony Tran: tony.tran@epitech.eu
- Alexandre Jankovic: alexandre.jankovic@epitech.eu
- Zacharie Lacombe: zacharie.lacombe@epitech.eu