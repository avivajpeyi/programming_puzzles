import pandas as pd


def read_file(in_file):
    lines = open(in_file).readlines()
    data = []
    for line in lines:  # "2-9 c: ccccccccc"
        split_line = line.split(" ")  # ['2-9', 'c:', 'ccccccccc']
        nums = split_line[0].split("-")
        password = split_line[-1].strip()
        char_requirement = split_line[1][0]
        count_of_char = password.count(char_requirement)
        min_num = int(nums[0])
        max_num = int(nums[1])
        data.append(dict(
            password=password,
            char_requirement=char_requirement,
            min_num=min_num,
            max_num=max_num,
            counts=count_of_char,
            char_at_min=password[min_num - 1],
            char_at_max=password[max_num - 1],
            counts_valid=min_num <= count_of_char <= max_num
        ))
    return pd.DataFrame(data)


def process_data_task_1(data):
    return sum(data['counts_valid'])


def process_data_task_2(data):
    data['char_min_match'] = data['char_at_min'] == data['char_requirement']
    data['char_max_match'] = data['char_at_max'] == data['char_requirement']
    data['valid'] = data['char_min_match'] ^ data['char_max_match']
    return sum(data['valid'])


def test():
    test_data = read_file("test_input.txt")
    assert process_data_task_1(test_data) == 2
    assert process_data_task_2(test_data) == 1


def main():
    data = read_file("input.txt")
    print(f"Task 1: {process_data_task_1(data)}")
    print(f"Task 2: {process_data_task_2(data)}")


if __name__ == "__main__":
    test()
    main()
