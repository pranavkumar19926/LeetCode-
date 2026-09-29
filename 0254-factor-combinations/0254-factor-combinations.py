class Solution:

    def ans(self, num, start, path, anss):

        for i in range(start, int(num ** 0.5) + 1):

            if num % i == 0:

                path.append(i)

                self.ans(num // i, i, path, anss)

                path.pop()

        if path:
            anss.append(path + [num])


    def getFactors(self, n: int) -> list[list[int]]:

        anss = []

        self.ans(n, 2, [], anss)

        return anss