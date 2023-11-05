fn main() {
    let instructions = include_str!("input.txt");

    let mut sum = 0;
    for instruction in instructions.chars() {
        if instruction == '(' {
            sum += 1;
        } else if instruction == ')' {
            sum += -1;
        }
    }

    println!("{sum}");
}
