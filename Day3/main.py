import sys
from time import time
from Solution import Solution
from Input import Input

FILE_MAP_SOLUTION = "map.txt"
FILE_MAP_EXAMPLE = "map_example.txt"

def main():
	inputExample = Input(FILE_MAP_EXAMPLE)
	inputSolution = Input(FILE_MAP_SOLUTION)

	dataExample = inputExample.getData()
	dataSolution = inputSolution.getData()

	Solution(dataExample)
	startTime = time() * 1000
	Solution(dataSolution)
	endTime = time() * 1000
	print("The program lasted ", (round(endTime - startTime, 3)), "ms")

main()