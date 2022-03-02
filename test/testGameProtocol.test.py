from src.minimap_extension.gameProtocol import GameProtocol


GameProtocol.call_remote_command('/hello', ['shuo'], remote_port=8081)
