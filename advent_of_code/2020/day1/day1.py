def read_file(in_file="input.txt"):
    lines = open(in_file).readlines()
    return [int(i) for i in lines]


def process_data_task_1(data):
    return {x + y: x * y for x in data for y in data}[2020]


def process_data_task_2(data):
    return {x + y + z: x * y * z for x in data for y in data for z in data}[2020]


def test():
    test_data = read_file("test_input.txt")
    assert process_data_task_1(test_data) == 514579
    assert process_data_task_2(test_data) == 241861950


def main():
    data = read_file()
    print(f"Task 1: {process_data_task_1(data)}")
    print(f"Task 2: {process_data_task_2(data)}")


if __name__ == "__main__":
    test()
    main()
