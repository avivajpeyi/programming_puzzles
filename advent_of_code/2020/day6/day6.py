TEST = "test_input.txt"
INPUT = "input.txt"


def read_file(filename):
    lines = open(filename, 'r').readlines()
    groups = []
    current_group = []
    for line in lines:
        if line != '\n':  # Still processing same group
            line = line.split().pop()
            current_group.append({char for char in line})
        else:  # group has been processed
            groups.append(current_group)
            current_group = []
    groups.append(current_group)
    return groups


def process_task_1(groups):
    total = 0
    for group in groups:
        group_set = set().union(*group)
        total += len(group_set)
    return total


def process_task_2(groups):
    total = 0
    for group in groups:
        group_set = set.intersection(*group)
        total += len(group_set)
    return total


def test():
    data = read_file(TEST)
    assert process_task_1(data) == 11
    assert process_task_2(data) == 6


def main():
    data = read_file(INPUT)
    print(f"Task 1: {process_task_1(data)}")
    print(f"Task 2: {process_task_2(data)}")


if __name__ == "__main__":
    test()
    main()
