# Odd Even Game
A console game in C++ where the player (ODD) plays against the computer (EVEN) by filling a matrix with the numbers 0 and 1.

> [!NOTE]
> Project was created in May 2022, but everything was messed up in one `.cpp` file, so it has been refactored and upgraded in September 2025.

## Rules

- Player (ODD Player) and computer (EVEN Player) take turns filling the NxN matrix with numbers 0 or 1.
- After filling in all the cells, the sums are calculated of:
  - Each line
  - Each column  
  - Main diagonal
  - Side diagonal
- The winner is determined by the number of even (EVEN) and odd (ODD) sums.
- If the ODD sum is greater, the player wins; otherwise, the computer wins.

## Functionality

- **New Game**: Creating a new game with a choice of matrix size (3x3 to 10x10)
- **Download Game**: Continuing a saved game from a file
- **Pause**: Ability to pause the game (press 'P' during a turn)
- **Save progress**: Automatic saving when paused
- **Best Results**: Review of the best results

## Project structure
```bash
OddEven/
├── CMakeLists.txt    # Assembly file
└── src/
    ├── main.cpp          # Main program file
    ├── Display.h/.cpp    # Class for displaying menus and results
    ├── Player.h/.cpp     # Player class
    ├── Array2D.h/.cpp    # Matrix class
    ├── MyGame.h/.cpp     # The main logic of the game
    └── utils.h/.cpp      # Support functions
```

## Installation
```bash
git clone https://github.com/Sarmatae685/odd-even-game.git
```


## Compilation and launch
### Using CMake
```bash
# 1. Change to the main project directory (where CMakeLists.txt is located)
cd ./odd-even-game/OddEven

# 2. Create a folder for the build
mkdir build

# 3. Go to /build
cd build

# 4. Run cmake (.. points to OddEven/, where CMakeLists.txt is located)
cmake ..

# 5. Compile project
make

# 6. Launch game
./OddEven
```

### CMake in one line
```bash
cd ./odd-even-game/OddEven && mkdir -p build && cd build && cmake .. && make && ./OddEven
```

### Cleaning compiled files:
```bash
make clean
```


### Manual compilation
```bash
# Install compiler (if not installed):
sudo apt install g++        # Ubuntu/Debian
sudo dnf install gcc-c++    # Fedora
sudo pacman -S gcc          # Arch Linux

# Switch to /src
cd ./src

# Compile project
g++ main.cpp Display.cpp Player.cpp Array2D.cpp MyGame.cpp utils.cpp \
    -o game -std=c++11 -Wall

# Run game (Linux/MacOS)
./game

# For Windows
game.exe
```
