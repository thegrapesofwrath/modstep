class File:
	def __init__(self,filename = None):
		self.filename = filename
		self.filedata = []
	
	def read(self):
		with open(self.filename) as f:
			self.filedata = f.readlines()
		self.filedata = [line.strip() for line in self.filedata]
