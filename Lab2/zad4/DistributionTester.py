import math
import numpy as np

class DistributionTester:
    def __init__(self) -> None:
        self.elements = []

    def printPercentiles(self, filler):
        if self.elements:
            self.elements = []
        filler(self.elements)
        for i in range(10, 100, 10):
            print(f"{i}th percentile: {self.elements[round(i / 100 * len(self.elements)) - 1]}")

    def findPercentile(self, n, func):
        if not self.elements:
            print("No elements")
            return -1
        
        return func(n)

def elementPercentile(tester: DistributionTester, percentile: int):
    return tester.findPercentile(percentile, lambda x: round(x * len(tester.elements) / 100 + 0.5))

def betweenPercentile(tester: DistributionTester, percentile: int):
    def func(percentile):
        elements = tester.elements
        sorted_elements = sorted(elements)

        N = len(sorted_elements)

        for i in range(1, N - 1):
            pvi = 100 * (i - 0.5) / N
            pvi_1 = 100 * (i + 0.5) / N
            if percentile >= pvi and percentile <= pvi_1:
                return round(sorted_elements[i] + N * (percentile - pvi) * (sorted_elements[i+1] - sorted_elements[i]) / 100)

    return tester.findPercentile(percentile, func)

def addSequentially(tester: DistributionTester, start: int, end: int, step: int):
    def addFunc(l):
        for i in range(start, end, step):
            l.append(i)
    tester.printPercentiles(addFunc)

def addRandomly(tester: DistributionTester, mean: int, variance: int, n: int):
    def addFunc(l):
        random_list = np.random.normal(mean, variance, n)
        for i in random_list:
            l.append(round(i))
    tester.printPercentiles(addFunc)

def addFibonacci(tester: DistributionTester, n: int):
    def addFunc(l):
        if n == 1:
            l.append(1)
            return
        if n == 2:
            l.extend([1, 1])
            return
        l.extend([1, 1])
        for i in range(2, n):
            l.append(l[i-2] + l[i-1])

    tester.printPercentiles(addFunc)

def main():
    tester = DistributionTester()
    addSequentially(tester, 10, 50, 1)
    addRandomly(tester, 5, 2, 20)
    addFibonacci(tester, 20)

    print(elementPercentile(tester, 50))
    print(betweenPercentile(tester, 80))

main()