import baseMath as bm


class modStep:

	def __init__(self):
		pass
	
	def calculate_distance(self,initial: bm.Point, final: bm.Point) -> bm.Point:
		return bm.Point((final.x - initial.x), (final.y - initial.y), (final.z - initial.z))
	
	def stepX(self,distance: bm.Point) -> str:
		if (distance.x > 0):
			# return "StepX\t"
			print("StepX\t")
		elif (distance.x < 0):
			# return "-StepX\t"
			print("-StepX\t")
	
	def stepY(self,distance: bm.Point) -> str:
		if (distance.y > 0):
			# return "StepY\t"
			print("StepY\t")
		elif (distance.y < 0):
			# return "-StepY\t"
			print("-StepY\t")
	
	def stepZ(self,distance: bm.Point) -> str:
		if (distance.z > 0):
			# return "StepZ\t"
			print("StepZ\t")
		elif (distance.z < 0):
			# return "-StepZ\t"
			print("-StepZ\t")
		
	def modCheck(self,point: int,i: int ) -> bool:
		if point == 0:
			return False
		elif i % point != 0:
			return False
		else:
			return True
	
	def isSingleStep(self,point: bm.Point) -> bool:
		if (point.x == 0 and point.y == 0 and point.z != 0 ):
			return True
		elif (point.x == 0 and point.y != 0 and point.z == 0):
			return True
		elif (point.x != 0 and point.y == 0 and point.z == 0):
			return True
		else:
			return False
	
	def singleStep(self,distance: bm.Point):
		if (distance.x == 0 and distance.y == 0 and distance.z != 0):
			self.stepZ(distance)
		elif (distance.x == 0 and distance.y != 0 and distance.z == 0):
			self.stepY(distance)
		elif (distance.x != 0 and distance.y == 0 and distance.z ==0):
			self.stepX(distance)
		# if(strlen(out) > 0)
		# 
		# 	print("\n")
		# 
	
	def tripleStep(self,distance: bm.Point, i:float):
	
		_x = bm.Point(0,distance.y,distance.z)
		_y = bm.Point(distance.x,0,distance.z)
		_z = bm.Point(distance.y,distance.x,0)

		bStepX = self.modCheck(self.calculateTimePulses(_x),i)
		bStepY = self.modCheck(self.calculateTimePulses(_y),i)
		bStepZ = self.modCheck(self.calculateTimePulses(_z),i)

		if ( bStepX and bStepY and bStepZ):
			self.stepX(distance)
			self.stepY(distance)
			self.stepZ(distance)
			print(" Branch 1:\t")
		elif (bStepX and bStepY and not bStepZ):
			self.stepX(distance)
			self.stepY(distance)
			print(" Branch 2:\t")
		elif (bStepX and not bStepY and bStepZ):
			self.stepX(distance)
			self.stepZ(distance)
			print(" Branch 3:\t")
		elif (bStepX and not bStepY and not bStepZ):
			self.stepX(distance)
			print(" Branch 4:\t")
		elif (not bStepX and bStepY and bStepZ):
			self.stepY(distance)
			self.stepZ(distance)
			print(" Branch 5:\t")
		elif (not bStepX and bStepY and not bStepZ):
			self.stepY(distance)
			print(" Branch 6:\t")
		elif (not bStepX and not bStepY and bStepZ):
			self.stepZ(distance)
			print(" Branch 7:\t")
		# if(strlen(out) > 0)
		# 	strcat(out, "\n")
		# 	print("%s", out)
	
	def calculateTimePulses(self, distance: bm.Point) -> float:
		
		if (distance.x != 0 and distance.y == 0 and distance.z == 0):
			return abs(distance.x)
		elif (distance.x != 0 and distance.y != 0 and distance.z == 0):
			return abs(distance.x * distance.y)
		elif (distance.x == 0 and distance.y != 0 and distance.z == 0):
			return abs(distance.y)
		elif (distance.x == 0 and distance.y == 0 and distance.z != 0):
			return abs(distance.z)
		elif (distance.x == 0 and distance.y != 0 and distance.z != 0):
			return abs(distance.y * distance.z)
		elif (distance.x != 0 and distance.y == 0 and distance.z != 0):
			return abs(distance.x * distance.z)
		elif (distance.x != 0 and distance.y != 0 and distance.z != 0):
			return abs(distance.x * distance.y * distance.z)
		elif (distance.x == 0 and distance.y == 0 and distance.z == 0):
			return 0.0
	
	def moveTo(self,distance: bm.Point,timePulse: float):
		print("\n\n-------Move List-------\n\n")
		# i = 0.0
		# for (i = 0 i < timePulse i++)
		for i in range(0,timePulse):

			if(self.isSingleStep(distance)):
				self.singleStep(distance)
			else:
				self.tripleStep(distance, i)
		print("\n-----------------------\n\n")
