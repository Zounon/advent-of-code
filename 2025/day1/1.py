def part1(input):
    dial = 50
    count = 0

    for instruction in input:
        direction = -1 if instruction[0] == "L" else 1
        distance = int(instruction[1:])

        dial += direction * distance

        while dial < 0 or dial > 99:
            if dial < 0:
                dial += 100
            elif dial > 99:
                dial -= 100

        if dial == 0:
            count += 1

    # print(f"count is {count}")
    return count


def part2(input):
    dial = 50
    count = 0
    last_dial = dial

    for instruction in input:
        direction = -1 if instruction[0] == "L" else 1
        distance = int(instruction[1:])

        full_rotations = distance // 100
        count += full_rotations

        remaining_rotation = distance % 100

        dial += direction * remaining_rotation

        if last_dial != 0 and dial < 0 or dial > 100:
            count += 1

        dial = dial % 100

        if dial == 0:
            count += 1

        last_dial = dial
        # print(f'\t{dial} {count}')

    # print(f"count is {count}")
    return count


def main():
    with open("./input") as file:
        input = file.readlines()

    print(f"Answer to part1 is {part1(input)}")
    print(f"Answer to part2 is {part2(input)}")


if __name__ == "__main__":
    main()
