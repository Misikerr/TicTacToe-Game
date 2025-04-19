

---

# 🎮 Tic Tac Toe (C++ Console Game)

This is a simple console-based Tic Tac Toe game developed in C++. It offers both **single-player** (against AI) and **two-player** game modes. The game also includes a clear user interface, rules display, and input validation for a smooth gameplay experience.12

---

## 🛠 Features

- ✅ 3x3 grid-based classic Tic Tac Toe game
- ✅ Two-player mode
- ✅ Single-player mode vs. basic AI
- ✅ Input validation to prevent invalid or occupied moves
- ✅ Game rules section
- ✅ Console-clearing for better user experience
- ✅ Automatic winner detection or draw condition
- ✅ Clean and readable UI using ASCII art and formatting

---

## 🧑‍💻 How to Play

### Game Modes:

1. **Start New Game**: Two-player mode. Each player takes turns placing X or O.
2. **Single Player**: Play against a basic AI that randomly picks valid positions.
3. **View Game Rules**: Displays the rules of Tic Tac Toe.
4. **Exit**: Exits the program.

### Rules:

- The game is played on a 3x3 board.
- Players take turns placing `X` and `O`.
- The first player to get 3 marks in a row (horizontally, vertically, or diagonally) wins.
- If all cells are filled without a winner, the game ends in a **draw**.

---
## 📋 Sample Menu Display
When you run the game, you'll see a menu like this:

                     _______________________
                    |                       |
                    |      TIC TAC TOE      |
                    |_______________________|
                    |1. Start New Game      |
                    |2. Single player       |
                    |3. View Game Rules     |
                    |4. Exit                |
                    *************************
                      Enter your choice:
## 🔳 Sample Game Board (toeBox)
                     _______________________
                    |                       |
                    |      TIC TAC TOE      |
                    |_______________________|
                    |***********************|
                    |*|     |      |      |*|
                    |*|  1  |  2   |  3   |*|
                    |*|_____|______|______|*|
                    |*|     |      |      |*|
                    |*|  4  |  5   |  6   |*|
                    |*|_____|______|______|*|
                    |*|     |      |      |*|
                    |*|  7  |  8   |  9   |*|
                    |*|     |      |      |*|
                     ***********************
This board updates dynamically as players make their moves.

---

## 🚀 Getting Started

### Compilation

Make sure you have a C++ compiler installed.

**On Linux/macOS:**

```bash
g++ -o tic_tac_toe tic_tac_toe.cpp
./tic_tac_toe
```

**On Windows:**

```bash
g++ -o tic_tac_toe.exe tic_tac_toe.cpp
tic_tac_toe.exe
```

---

## 📁 File Structure

```
tic_tac_toe.cpp    # Main game source code
README.md          # This file
```

---

## 🤖 AI Behavior

The AI plays as `O` and makes **random valid moves**. It does not use any strategy (e.g., Minimax), making it a fun but beatable opponent.

---

## 🧹 Future Improvements

- Implement smarter AI using Minimax algorithm
- Add scoring and match history
- Export scores to a file
- Add difficulty levels
- GUI version with graphics

---

## 👨‍💻 Author

- Developed by **Misiker Genene(Rio)** (a passionate software engineering student)
- Project goal: Practice C++ fundamentals and game logic implementation

---

## 📜 License

This project is open-source and free to use for educational purposes.

---
