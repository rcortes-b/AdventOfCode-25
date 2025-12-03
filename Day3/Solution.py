
class Solution:
	def __init__(self, data):
		self.totalJoltage = 0
		self.totalJoltageBonus = 0
		self.isSecond = False
		self.run(data)
		self.runBonus(data)
		self.showResolution()

	def run(self, data):
		for banks in data:
			joltage = "00"
			size = len(banks) - 1
			self.isSecond = False
			for i, battery in enumerate(banks):
				if battery > joltage[0]  and i < size:
					joltage = banks[i] + joltage[1]
					self.isSecond = True
				elif self.isSecond is True:
					joltage = joltage[0] + banks[i]
					self.isSecond = False
				elif battery > joltage[1]:
					joltage = joltage[0] + banks[i]
			self.totalJoltage += int(joltage)

	def runBonus(self, data):
		for banks in data:
			batteries = "000000000000"
			batteries, i = self.getMaxValues(banks, batteries)
			size = len(banks)
			while (i < size):
				batteries = self.updateBatteries(batteries, size - i, banks[i])
				i += 1
			self.totalJoltageBonus += int(batteries)
				
	def updateBatteries(self, batteries, gap, c):
		size = len(batteries)
		i = 1
		while (i < size):
			if (batteries[i] < c and gap > (size - i)):
				batteries = batteries[:i] + "".join(c) + batteries[i + 1:]
				batteries = self.fillWithZeros(batteries, i + 1)
				return batteries
			elif (batteries[i] < c and gap == (size - i)):
				batteries = batteries[:i] + "".join(c) + batteries[i + 1:]
				batteries = self.fillWithZeros(batteries, i + 1)
				return batteries
			i += 1
		return batteries
				
	def fillWithZeros(self, batteries, index):
		batteries = batteries[:index]
		while (index < 12):
			batteries += "0"
			index += 1
		return batteries
		
	def getMaxValues(self, bank, batteries):
		max = '0'
		size = len(bank)
		i = 0
		max_index = 0
		while (i < size):
			c = bank[i]
			if c > max and i <= (size - 12):
				max_index = i
				max = c
				batteries = max + "00000000000"
			i += 1
		return batteries, max_index + 1


	def showResolution(self):
		print("Total joltage is: ", self.totalJoltage)
		print("total joltage of bonus is: ", self.totalJoltageBonus, '\n')