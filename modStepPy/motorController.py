import lib.Rpi.RPi.GPIO as gpio
import time

class stepperMotor:
	gpio.setmode(gpio.BCM)

	def __init__(self,stepPin,directionPin,engagePin):
		self.stepPin = stepPin
		self.directionPin = directionPin
		self.engagePin = engagePin
		self.engaged = False
		self.delay = 0
		self.steps = 0
		self.Forward = True
		self.step = False
	
	def initializeMotor(self):
		gpio.setup(self.stepPin,gpio.OUT)
		gpio.setup(self.directionPin,gpio.OUT)
		gpio.setup(self.engagePin,gpio.OUT)
	
	def toggleEngage(self):
		if self.engaged == True:
			self.engaged = False
			gpio.output(self.engagePin,self.engaged)
		else:
			self.engaged = True
			gpio.output(self.engagePin,self.engaged)
	
	def toggleDirection(self):
		if self.Forward == True:
			self.Forward = False
			gpio.output(self.directionPin,self.Forward)
		else:
			self.Forward = True
			gpio.output(self.directionPin,self.Forward)
	
	def toggleStep(self,delay=False):
		self.step = True
		gpio.output(self.stepPin,self.step)
		if delay:
			time.sleep(delay)
		else:
			time.sleep(self.delay)
		self.step = False
		gpio.output(self.stepPin,self.step)
		
	def singleStep(self,backwards=False,delay=False):

		if backwards:
			self.toggleDirection()
		self.toggleEngage()
		self.toggleStep(delay)





