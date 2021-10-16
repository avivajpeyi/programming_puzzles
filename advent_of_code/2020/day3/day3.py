import subprocess
import sys
import time

import numpy as np

ANIMATION_TIME = 0.1


class Forest:
    def __init__(self, file):
        self.file = file
        self.grid = []
        self.repeat_idx = 0
        self.num_rows = 0
        self.r = dict(x=0, y=0)
        self.reset()

    def reset(self):
        self.grid = [list(l.strip()) for l in open(self.file).readlines()]
        self.repeat_idx = len(self.grid[0])
        self.num_rows = len(self.grid)
        self.r = dict(x=0, y=0)

    def __str__(self):
        return "\n".join([
            "\n",
            "GRID:",
            self.grid_str,
            "-" * self.repeat_idx,
            f'Pos = {self.r}',
            f'N crashes: {self.num_crashes}',
            f'N open: {self.num_open}',
            f'N total rows: {self.num_rows}'
        ])

    def __repr__(self):
        return self.__str__()

    @property
    def num_crashes(self):
        return self.grid_str.count('X')

    @property
    def grid_str(self):
        return "\n".join(["".join(i) for i in self.grid])

    @property
    def num_open(self):
        return self.grid_str.count('O')

    def take_step(self, right, down):
        self.r['x'] += right
        self.r['y'] += down
        self.r['x'] = self.r['x'] % self.repeat_idx

    def update_grid(self):
        current_location = self.grid[self.r['y']][self.r['x']]
        if current_location == '.':
            self.grid[self.r['y']][self.r['x']] = 'O'
        elif current_location == '#':
            self.grid[self.r['y']][self.r['x']] = 'X'
        else:
            self.grid[self.r['y']][self.r['x']] = '?'

    def traverse(self, right, down, animate=None):
        while (self.r['y'] + down < self.num_rows):
            self.take_step(right, down)
            self.update_grid()
            if animate:
                sys.stdout.write(str(self))
                sys.stdout.flush()
                time.sleep(ANIMATION_TIME)
                subprocess.call('clear', shell=True)
        sys.stdout.write(str(self) + "\nout!!")
        sys.stdout.flush()


def read_file(in_file) -> Forest:
    return Forest(in_file)


def process_forest_task_1(forest):
    forest.traverse(right=3, down=1)
    return forest.num_crashes


def process_forest_task_2(forest):
    """:

    Right 1, down 1.
    Right 3, down 1. (This is the slope you already checked.)
    Right 5, down 1.
    Right 7, down 1.
    Right 1, down 2.

    :param forest:
    :type forest:
    :return:
    :rtype:
    """
    crashes = []
    for r, d in [
        (1, 1),
        (3, 1),
        (5, 1),
        (7, 1),
        (1, 2)
    ]:
        forest.reset()
        forest.traverse(right=r, down=d)
        crashes.append(forest.num_crashes)
        forest.reset()
    return np.product(crashes)


def test():
    forest = read_file("test_input.txt")
    assert process_forest_task_1(forest) == 7
    task_2_crashes = process_forest_task_2(forest)
    # assert task_2_crashes == [2, 7, 3, 4, 2], task_2_crashes
    assert task_2_crashes == 336


def main():
    forest = read_file("input.txt")
    print(f"Task 1: {process_forest_task_1(forest)}")
    print(f"Task 2: {process_forest_task_2(forest)}")


if __name__ == "__main__":
    # test()
    main()
