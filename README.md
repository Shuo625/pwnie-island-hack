# pwnie-island-hack
A hack of pwnie island game


### Setup
Make a directory called *build* at this directory which will contain all of compiled object files and libraries.

Make a link file called *game* linking to the directory that contains the executable file of game using command `ln -s`.

### Usage
Compile Codes
```bash
make all
```

Run the game with Hack Lib
```bash
make rungame
```

### Game Protocol

Message Format: command ...args

#### Main Game supports:

- /teleport x: float y: float z: float
- /hello name: str # for test

#### Minimap Extension supports:

- /savePosition name: str x: float y: float z: float
- /updateMyselfPosition x: float y: float z: float
- /updateEnemyPosition number: int x: float y: float z: float
- /hello name: str # for test