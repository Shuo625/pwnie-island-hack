from src.minimap_extension.gameProtocol import GameProtocol


GameProtocol.call_remote_command('/hello', ['shuo'], remote_port=8080)
GameProtocol.call_remote_command('/hello', ['linah'], remote_port=8080)
