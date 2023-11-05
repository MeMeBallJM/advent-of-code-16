fn main() {
    let instructions = include_str!("input.txt");

    let mut sum = 0;
    let mut index = None;
    for (instruction, i) in instructions.chars().zip(1..) {
        if instruction == '(' {
            sum += 1;
        } else if instruction == ')' {
            sum += -1;
        }

        if sum == -1 {
            index = Some(i);
            break;
        }
    }

    if let Some(i) = index {
        println!("{i}");
    }
}
