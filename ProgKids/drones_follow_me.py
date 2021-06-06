import mc

from mc import drones, world, player

# create drone:
dronee = drones.createDrone(0,0,0, "dronee")


while True:
	x_d, y_d, z_d = dronee.getPos()
	x_p, y_p, z_p = player.getPos()
	if x_d < x_p:
		dronee.lookTo('EAST')
		dronee.moveForward(1)
	elif x_d > x_p:
		dronee.lookTo("WEST")
		dronee.moveForward(1)
	if z_d < z_p:
		dronee.lookTo('SOUTH')
		dronee.moveForward(1)
	if z_d > z_p:
		dronee.lookTo('NORTH')
		dronee.moveForward(1)