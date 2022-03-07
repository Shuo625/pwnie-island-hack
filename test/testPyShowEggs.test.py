from src.minimap_extension.gameProtocol import GameProtocol


GameProtocol.call_remote_command('/showEggs', ['egg', 20000, 20000, 1], remote_port=8081)