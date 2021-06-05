import mc

from mc import drones, world


# drone army:
def createArmy(team, count):
    for i in range(count):
        if team == "a":
            drones.createDrone(0, 0, i, team)
        else:
            drones.createDrone(15, 0, i, team)


createArmy("a", 5)
createArmy("b", 5)

dr = drones.list()[0]
print(dir(dr))

# ['__eq__', '__format__', '__ge__',
#  '__getattribute__', '__gt__', '__hash__',
#  '__init__', '__le__', '__lt__', '__module__',
#  '__ne__', '__new__', '__repr__', '__setattr__',
#  '__str__', 'breakBlock', 'destroy', 'dropItem',
#  'equip', 'getBlockInFront', 'getInventory', 'getPos',
#  'inventoryContains', 'item', 'lookTo', 'move',
#  'moveForward', 'pickItem', 'placeBlock', 'putItem',
#  'rename', 'setParticle', 'shootArrow', 'startDrawing',
#  'stopDrawing', 'takeItem', 'turn', 'turnLeft', 'turnRight', 'unequip']