import mc
from mc import world, drones

# Дрон-преподаватель учит дрона-малыша маневрировать между
# стенами. Помоги Малышу выйти из лабиринта

# Подсказка: существует множество способов помочь Малышу
# выбраться. Для этого можно воспользоваться функциями из
# документации (Раздел "drones")
# getBlockInFront, turnRight, moveForward(1) и другие

# Функция для создания лабиринта. Может оказаться сложноватой
# для самостоятельного изучения. Поэтому расскажу о ней на уроке
def buildMaze(x0, y0, z0):
	builderDrone = drones.createDrone(x0, y0, z0, "Teacher")
	for len in range(2, 12, 2):
		for j in range(2):
			x1, y1, z1 = builderDrone.getPos()
			builderDrone.moveForward(len)
			builderDrone.turnRight()
			world.setCuboid(x0, 0, z0, x1, y1, z1, 1)
			x0, z0 = x1, z1


# ЗАДАНИЕ
# Допиши функцию так, чтобы малыш вышел из лабиринта невредимым

def homeWork(x, y, z):
	myDrone = drones.createDrone(x0 - 1, y0, z0 + 1, "Малыш")
	myDrone.turnRight()
	myDrone.turnRight()
	while True:
		block = myDrone.getBlockInFront()
		if block == 1:
			myDrone.breakBlock()
		myDrone.moveForward(1)

x0, y0, z0 = 0, 0, 0
buildMaze(x0, y0, z0)
homeWork(x0, y0, z0)
