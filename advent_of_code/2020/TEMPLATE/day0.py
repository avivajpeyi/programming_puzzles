TEST = "test_input.txt"
INPUT = "input.txt"


def read_file(filename):
    return open(filename, "r").readlines()


def process_task_1(data):
    return len(data)


def process_task_2(data):
    return len(data)


def test():
    data = read_file(TEST)
    assert process_task_1(data) == 0
    assert process_task_2(data) == 0


def main():
    data = read_file(INPUT)
    print(f"Task 1: {process_task_1(data)}")
    print(f"Task 2: {process_task_2(data)}")


if __name__ == "__main__":
    test()
    main()
