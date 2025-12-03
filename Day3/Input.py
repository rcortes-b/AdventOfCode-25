

class Input:
	def __init__(self, path):
		file = open(path, "r")
		content = file.read()
		self.split = content.split('\n')
		file.close()
	
	def getData(self):
		return self.split
	
