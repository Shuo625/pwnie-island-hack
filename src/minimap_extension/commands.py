from .utils import strToFloatToInt
from .miniMap import minimap


def commandHello(arguments: list):
    print(f'hello {arguments[0]}')


def commandSaveLandmark(arguments: list):
    minimap.drawLandmark(arguments[0], 
                         strToFloatToInt(arguments[1]), 
                         strToFloatToInt(arguments[2]), 
                         strToFloatToInt(arguments[3]))

def commandShowEggs(arguments: list):
    minimap.drawEgg(arguments[0], 
                         strToFloatToInt(arguments[1]), 
                         strToFloatToInt(arguments[2]), 
                         strToFloatToInt(arguments[3]))

def commandUpdateMyselfPosition(arguments: list):
    minimap.updateMyselfPosition(strToFloatToInt(arguments[0]), 
                                 strToFloatToInt(arguments[1]), 
                                 strToFloatToInt(arguments[2]))

