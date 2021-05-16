# space-impact-sfml

A basic space impact game made with sfml

Keybindings:

- A-D for moving player ship
- Space for shooting player ship cannon
- R for restarting the game after player ship is destroyed

Added:

- Spider ships lock on player then shoots
- Spider ships can make escape manuevers if their gun is reloading and player shoots it's gun.
- Spider ships can decide to make an escape manuever to right or left. Possibilty is %50, %50

Note: If game is not working or can't find resource files; follow these steps:

- 1. click on project name(at solution explorer) "OyunProgOdev2"
- 2. Go to View(At menu bar)
- 3. Go to Property Pages
- 4. On pop-up screen, Configuration Properties->Debugging->Working Directory
- 5. Add "$(SolutionDir)..\Dependencies\bin\" to Working Directory
- 6. Have fun!

Known Bugs:

- Spider ships may get confused and stop locking on player ship after escape manuever
- After player ship is destroyed, explosion effect may trigger when a random enemy laser/ship hits player ship.

Group Members:

- g171210380 Yasin DERE
- g161210053 Emre MUTLU
- g171210080 Süleyman Behlül UYSAL
