from time import sleep
from src.minimap_extension.gameProtocol import GameProtocol

x = 10000
y = 10000
step = 1000


while True:
    sleep(2)
    GameProtocol.call_remote_command('/updateMyselfPosition', [x, y, 1], remote_port=8081)
    x += step
    y += step
