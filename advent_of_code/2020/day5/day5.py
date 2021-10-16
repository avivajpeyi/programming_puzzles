import pandas as pd

TEST = "test_input.txt"
INPUT = "input.txt"

CHAR_ROWS = 7  # NUM_ROW = 2 ** CHAR_ROWS
CHAR_COLS = 3  # MAX_COL = 2 ** CHAR_COLS


def read_file(filename):
    lines = open(filename, "r").readlines()
    data = []
    for line in lines:
        line = line.strip()
        (r, c, s) = process_seat_code(line)
        data.append(dict(
            line=line,
            row_id=r,
            col_id=c,
            seat_id=s
        ))
    df = pd.DataFrame(data)
    return df.sort_values('seat_id')


def process_seat_code(code):
    row_str = code[:CHAR_ROWS]
    row_id = get_id(row_str, char_on="B", char_off="F")
    column_str = code[-CHAR_COLS:]
    column_id = get_id(column_str, char_on="R", char_off="L")
    seat_id = (row_id * 8) + column_id
    return row_id, column_id, seat_id


def get_id(code, char_on, char_off):
    code = code.replace(char_off, "0")
    code = code.replace(char_on, "1")
    return int(code, 2)


def process_task_1(data):
    return max(data.seat_id.values)


def process_task_2(data):
    min_seat, max_seat = min(data.seat_id), max(data.seat_id)
    seat_id = pd.DataFrame(dict(seat_id=[i for i in range(min_seat, max_seat+1)]))
    df = pd.merge(data, seat_id, on="seat_id", how="outer")
    empty_seat = df[df.isna().any(axis=1)]
    return empty_seat['seat_id'].values


def test():
    """
    BFFFBBFRRR: row 70, column 7, seat ID 567.
    FFFBBBFRRR: row 14, column 7, seat ID 119.
    BBFFBBFRLL: row 102, column 4, seat ID 820.
    """
    assert process_seat_code("BFFFBBFRRR") == (70, 7, 567)
    assert process_seat_code("FFFBBBFRRR") == (14, 7, 119)
    assert process_seat_code("BBFFBBFRLL") == (102, 4, 820)
    data = read_file(TEST)
    assert process_task_1(data) == max(567, 119, 820)
    # assert process_task_2(data) == 0


def main():
    data = read_file(INPUT)
    print(f"Task 1: {process_task_1(data)}")
    print(f"Task 2: {process_task_2(data)}")


if __name__ == "__main__":
    test()
    main()
