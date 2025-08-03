# UNO-Twist

UNO-Twist is a graphical, interactive version of the classic UNO card game, built in C++ using SDL2 for graphics and audio. The game features a human vs. computer experience, complete with sound effects, music, and a visually rich interface.

## Features

- **Classic UNO Gameplay**: Play against a computer opponent with all standard UNO rules.
- **Graphical User Interface**: Card graphics, backgrounds, and interactive menus.
- **Sound and Music**: Includes background music, sound effects for card flips, wins, and losses.
- **Multiple Backgrounds**: Choose between different game backgrounds.
- **Rule Display**: In-game access to UNO rules.

## How to Play

1. **Start the Game**: Run the compiled executable. The main menu allows you to start the game, choose backgrounds, or view the rules.
2. **Gameplay**: 
   - Click on your cards to play them.
   - Draw cards from the bank if you can't play.
   - Special cards (Wild, Draw Four, etc.) are supported.
   - The first player to empty their hand wins.
3. **End Game**: The game displays a win or loss screen depending on the outcome.

## Controls

- **Mouse**: All interactions (playing cards, choosing backgrounds, navigating menus) are done via mouse clicks.

## Build Instructions

### Prerequisites

- C++ compiler (e.g., g++)
- SDL2, SDL2_image, SDL2_mixer libraries

### Compilation

On **Windows** (as per the original instructions):

```sh
g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
```

On **Linux** (example, adjust as needed):

```sh
g++ *.cpp -lSDL2 -lSDL2_image -lSDL2_mixer -o uno-twist
```

### Running

- On Windows: `./a.exe`
- On Linux: `./uno-twist`

## Project Structure

- `main.cpp` - Entry point, initializes and runs the game loop.
- `game.cpp/hpp` - Handles game state, rendering, and event loop.
- `UNO.cpp/hpp` - Core UNO game logic, card management, and rules.
- `Player.cpp/hpp`, `Human.cpp/hpp`, `PC.cpp/hpp` - Player classes and logic.
- `Card.cpp/hpp`, `Numbered.cpp/hpp`, `Non_Numbered.cpp/hpp`, `Non_Coloured.cpp/hpp` - Card types and logic.
- `Graphics.cpp/hpp`, `drawing.hpp` - Rendering utilities.
- `Sound.cpp/hpp` - Sound and music management.
- `assets.png/svg`, `*.mp3`, `*.wav`, `*.png` - Game assets (cards, backgrounds, sounds).
- `How to Compile.txt` - Original build instructions.

## Known Issues

- The game is not fully finished and may contain bugs.
- Some features or rules may not be fully implemented.
