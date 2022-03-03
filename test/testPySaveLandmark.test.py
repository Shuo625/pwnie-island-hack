from src.minimap_extension.gameProtocol import GameProtocol


GameProtocol.call_remote_command('/saveLandmark', ['house', 10000, 10000, 1], remote_port=8081)
