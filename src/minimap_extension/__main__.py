from .gameProtocol import GameProtocol
from .testCommand import commandHello


if __name__ == '__main__':
    gameProtocol = GameProtocol()

    gameProtocol.register_command(command='/hello', callback=commandHello)
    gameProtocol.start()

    x = input()
    print(f'{x} and main thread ex')
