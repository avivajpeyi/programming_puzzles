import re

TEST = "test_input.txt"
TEST_2_VALID = "test_valid_input_task2.txt"
TEST_2_INVALID = "test_invalid_input_task2.txt"
INPUT = "input.txt"

KEYS = {
    'byr',
    'iyr',
    'eyr',
    'hgt',
    'hcl',
    'ecl',
    'pid',
}


def is_passport_valid(p):
    """
    byr (Birth Year) - four digits; at least 1920 and at most 2002.
    iyr (Issue Year) - four digits; at least 2010 and at most 2020.
    eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
    hgt (Height) - a number followed by either cm or in:
    If cm, the number must be at least 150 and at most 193.
    If in, the number must be at least 59 and at most 76.
    hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
    ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
    pid (Passport ID) - a nine-digit number, including leading zeroes.
    cid (Country ID) - ignored, missing or not.
    """
    try:
        yrs_valid = (
                1920 <= int(p['byr']) <= 2002 and
                2010 <= int(p['iyr']) <= 2020 and
                2020 <= int(p['eyr']) <= 2030
        )
        if p['hgt'][-2:] == 'in':
            hgt_valid = 59 <= int(p['hgt'][0:-2]) <= 76
        else:  # p['hgt'][-2:] == 'cm':
            hgt_valid = 150 <= int(p['hgt'][0:-2]) <= 193

        hcl_valid = re.compile('^#[a-f0-9]{6}$').match(p['hcl'])
        ecl_valid = p['ecl'] in ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']
        pid_valid = re.compile('^[0-9]{9}$').match(p['pid'])

        return yrs_valid and hgt_valid and hcl_valid and ecl_valid and pid_valid
    except Exception:
        return False

def read_file(file_name):
    lines = open(file_name, 'r').readlines()
    passports = []
    current_passport = {}
    for line in lines:
        if line != '\n':  # Still processing same passport
            fields = line.split()
            current_passport.update({
                f.split(":")[0]: f.split(":")[1]
                for f in fields
            })
        else:  # Passport has been processed
            passports.append(current_passport)
            current_passport = {}
    passports.append(current_passport)
    return passports


def process_task1(passports):
    valid = 0
    for passport in passports:
        if set(passport.keys()).issuperset(KEYS):
            valid += 1
    return valid


def process_task2(passports):
    valid = 0
    for passport in passports:
        if set(passport.keys()).issuperset(KEYS) and is_passport_valid(passport):
            valid += 1
    return valid


def test():
    assert process_task1(read_file(TEST)) == 2
    assert process_task2(read_file(TEST_2_INVALID)) == 0
    assert process_task2(read_file(TEST_2_VALID)) == 4


def main():
    data = read_file(INPUT)
    print(f"task 1: {process_task1(data)}")
    print(f"task 2: {process_task2(data)}")


if __name__ == "__main__":
    test()
    main()
