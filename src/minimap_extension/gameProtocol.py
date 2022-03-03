import socket
from threading import Thread
from typing import Callable


class GameProtocol(Thread):
    def __init__(self, host='127.0.0.1', port=8081, buffer_size=1024):
        super(GameProtocol, self).__init__(daemon=True)
        self.host = host
        self.port = port
        self.buffer_size = buffer_size

        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server.bind((self.host, self.port))

        self.commands = {}

    def run(self):
        print(f'Server starts at {self.host}:{self.port}')
        self.server.listen(20)
        
        while True:
            sock, addr = self.server.accept()
            with sock:
                print(f'Connected by {addr}')
                while True:
                    message = sock.recv(self.buffer_size)
                    if not message:
                        break
                    message = message.decode(encoding='utf8')
                    self._execute_task(message);

    def register_command(self, command, callback: Callable):
        self.commands[command] = callback

    def _execute_task(self, message: str):
        command, arguments = self._parse_message(message)
        self._run_command(command, arguments)

    def _run_command(self, command: str, arguments: list):
        if command not in self.commands.keys():
            print(f'Unsupported command {command}')
            return
        else:
            arguments_str = ' '.join(arguments)
            print(f'Receive command {command} {arguments_str}')
            self.commands[command](arguments)

    def _parse_message(self, message: str):
        command_parts = message.strip().split(' ')
        command, arguments = command_parts[0], command_parts[1:]

        return command, arguments

    @staticmethod
    def call_remote_command(command: str, arguments: list, remote_host='127.0.0.1', remote_port=8080):
        arguments_str = ' '.join([str(argument) for argument in arguments])
        message = command + ' ' + arguments_str

        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client:
            client.connect((remote_host, remote_port))
            client.sendall(bytes(message, encoding='utf8'))
