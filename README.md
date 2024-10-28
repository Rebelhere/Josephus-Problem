
# Josephus Problem Solver with Graphical Visualization

This project provides a graphical simulation of the Josephus problem using C++ and SFML for visual rendering. In the Josephus problem, people stand in a circle and are eliminated at regular intervals until only one survivor remains. This program visualizes each elimination step and highlights the final survivor with a graphical user interface (GUI).

## Problem Statement

The Josephus problem is a classic counting problem where:
1. **N** people stand in a circle, waiting to be eliminated.
2. Counting starts at a randomly selected person and proceeds clockwise.
3. Every **k-th** person is eliminated until only one person remains, who is declared the survivor.

### Features

- **Graphical Visualization**: Using SFML, each person is represented as a sprite that visually shows the elimination process.
- **Sound Effects**: Each elimination and victory display includes sound effects for an engaging experience.
- **User Input**: The program accepts the number of people (**N**) and the step count (**K**) as input from the user.
- **Customizable Radius**: The circle size adjusts based on the number of people to maintain readability.

## Getting Started

### Prerequisites

- **C++11** or newer.
- **SFML Library**: You need to install SFML (Simple and Fast Multimedia Library) for graphics, window handling, and audio.
  
  To install SFML, use:
  ```bash
  sudo apt-get install libsfml-dev  # For Debian/Ubuntu
  brew install sfml                 # For macOS
  ```

### Installation

1. Clone the repository:

    ```bash
    git clone <https://github.com/Rebelhere/Josephs-Problem>
    cd JosephusProblemSolver
    ```

2. Ensure you have the necessary assets in the same directory as the executable:
    - `1.mp3`: Background music during the simulation.
    - `2.mp3`: Sound effect for each elimination.
    - `3.mp3`: Sound effect for the winner display.
    - `alive.png`: Image to represent alive participants.
    - `dead.png`: Image to represent eliminated participants.
    - `winner.jpg`: Image to represent the final survivor.
    - `1.ttf`: Font file for displaying text.

### Building the Project

Compile the code with SFML:

```bash
g++ josephus.cpp -o josephus -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
```

Run the program:

```bash
./josephus
```

## Usage

1. **Start the program** and enter values for:
   - **N**: The number of people in the circle.
   - **K**: The interval for elimination (every k-th person will be removed).
2. The graphical window will open, displaying the participants in a circle.
3. The elimination process will start, with each elimination shown in the GUI and accompanied by a sound.
4. Once only one participant remains, they will be highlighted as the survivor with a congratulatory message and sound effect.

## Code Overview

### Key Files and Functions

- **Queue Class**: Custom queue implementation used to manage the circle of participants.
  - `Enqueue(T val)`: Adds a participant to the queue.
  - `Dequeue()`: Removes a participant from the queue.
  - `kill()`: Executes the elimination process by removing every k-th person.
  - `josephproblem(RenderWindow& window)`: Manages the Josephus process and updates the GUI.

- **printwindow**: Displays the current state of the circle, marking each person as either alive or dead.

- **printwinner**: Displays the winning participant after all others are eliminated.

### Graphics and Audio

- **Sprites**: The program uses `alive.png` and `dead.png` for participants. The survivor is shown with `winner.jpg`.
- **Sound Effects**: 
  - Elimination events play the sound from `2.mp3`.
  - Background music plays from `1.mp3`.
  - Winner announcement plays `3.mp3`.

## Example

For **N = 7** and **K = 3**:
- The program displays a circle of 7 participants.
- Each 3rd person is eliminated in clockwise order until only one remains.
- The GUI updates in real-time, showing the elimination sequence and final winner.

## Future Enhancements

- **Adjustable Parameters**: Add user controls for adjusting speed and volume.
- **Different Elimination Animations**: Introduce more visual effects for eliminations.

## Contributing

Feel free to open issues or submit pull requests for improvements or bug fixes.

## Collaboration Guidelines

We welcome contributions from the open-source community. If you'd like to collaborate on this project, please adhere to the following guidelines:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Implement your changes and commit them with descriptive messages.
4. Push your branch to your fork and submit a pull request.

### Feel free to reach out if you have any questions or suggestions !
