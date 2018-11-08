class Solution:
    def slidingPuzzle(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        answer = '123450'
        d = {
            ''.join(str(i) for i in board[0]) + ''.join(str(i) for i in board[1]): 0
        }
        done = {

        }
        while d.keys():

            k = min(d, key=d.get)

            done[k] = True

            c = d[k]
            del d[k]

            if k == answer:
                return c

            if k[0] == '0' or k[3] == '0':
                f = k[3] + k[1:3] + k[0] + k[4:6]
                if not d.get(f) and not done.get(f):
                    d[f] = c + 1

            if k[0] == '0' or k[1] == '0':
                f = k[1] + k[0] + k[2:6]
                if not d.get(f) and not done.get(f):
                    d[f] = c + 1

            if k[1] == '0' or k[4] == '0':
                f = k[0] + k[4] + k[2:4] + k[1] + k[5]
                if not d.get(f) and not done.get(f):
                    d[f] = c + 1

            if k[1] == '0' or k[2] == '0':
                f = k[0] + k[2] + k[1] + k[3:]
                if not d.get(f) and not done.get(f):
                    d[f] = c + 1

            if k[3] == '0' or k[4] == '0':
                f = k[0:3] + k[4] + k[3] + k[5]
                if not d.get(f) and not done.get(f):
                    d[f] = c + 1

            if k[4] == '0' or k[5] == '0':
                f = k[0:4] + k[5] + k[4]
                if not d.get(f) and not done.get(f):
                    d[f] = c + 1

            if k[2] == '0' or k[5] == '0':
                f = k[0:2] + k[5] + k[3:5] + k[2]
                if not d.get(f) and not done.get(f):
                    d[f] = c + 1

        return -1

