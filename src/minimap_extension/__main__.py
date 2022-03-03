from .gameProtocol import GameProtocol
from .commands import commandHello, commandSaveLandmark
from .miniMap import minimap


if __name__ == '__main__':
    gameProtocol = GameProtocol()

    gameProtocol.register_command(command='/hello', callback=commandHello)
    gameProtocol.register_command(command='/saveLandmark', callback=commandSaveLandmark)
    
    gameProtocol.start()

    minimap.start()
