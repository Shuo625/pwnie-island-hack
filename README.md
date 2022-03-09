# pwnie-island-hack

A hack of pwnie island game


### Setup

Make a directory called *build* at this directory which will contain all of compiled object files and libraries.

Make a link file called *game* linking to the directory that contains the executable file of game using command `ln -s`.

Download necessary python libraries using `sudo apt-get install python3-tk`, `sudo apt-get install idle3`.

### Getting Started

Compile Codes
```bash
make all
```

Run the minimap (start the minimap before starting game)
```bash
make minimap
```

Run the game with Hack Lib
```bash
make rungame
```

Use the commands below in the chat box of game

### Commands

- /startServer # start the server at the game side to receive message from map side
- /saveLandmark name # save a landmark to map
- /showEggs # show all of eggs on the map
- /showLandmark # show all of landmarks saved before
- /teleportToLandmark name # teleport to landmark saved before by name
- /setWalkSpeed arg # set walk speed
- /setJumpSpeed arg # set jump speed
- /setJumpHoldTime arg # set jump hold time

### Minimap Extension

- Minimap will show the movement of player in real time
- You can click on the button of landmark or egg to teleport

### Game Protocol

Message Format: command ...args

#### Main Game supports:

- /teleport x: float y: float z: float
- /hello name: str # for test

#### Minimap Extension supports:

- /saveLandmark name: str x: float y: float z: float
- /showEggs name: str x: float y: float z: float
- /updateMyselfPosition x: float y: float z: float
- /hello name: str # for test
