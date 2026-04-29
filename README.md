# 42 Piscine — drocha-h

This repository holds everything I wrote during the 42 São Paulo Piscine: daily C modules, shell scripting assignments, weekend Rush projects, and my personal exam-prep practice files. It's not a polished library — it's a record of the learning curve, including the rough edges.

---

## Structure

```
42-piscine/
├── c00 – c07      # Daily C modules (exercises)
├── shell00        # Shell basics
├── shell01        # Shell scripting
├── rush00         # Weekend Rush 00
├── rush01         # Weekend Rush 01 — Skyscraper puzzle
├── rush02         # Weekend Rush 02 — Number-to-words converter
├── practice/      # Personal exam practice (exam02 & exam03)
└── eu/            # Signed ethics agreement (42 code of conduct)
```

---

## C Modules

Each module introduced a new layer of C, building on the previous one. The progression made sense — by the time we got to `malloc`, it didn't feel like magic anymore.

| Module | Focus | Key exercises |
|--------|-------|---------------|
| **c00** | Basic I/O, conditionals | `ft_putchar`, `ft_putnbr`, `ft_print_comb` |
| **c01** | Pointers & arrays | `ft_swap`, `ft_div_mod`, `ft_rev_int_tab`, `ft_sort_int_tab` |
| **c02** | String basics | `ft_strcpy`, `ft_strcapitalize`, `ft_str_is_*` validators |
| **c03** | String manipulation | `ft_strcmp`, `ft_strcat`, `ft_strstr`, `ft_strlcat` |
| **c04** | Number/string conversion | `ft_putnbr`, `ft_atoi` |
| **c05** | Recursion | `ft_fibonacci`, `ft_sqrt`, iterative vs. recursive factorial/power |
| **c06** | `argc` / `argv` | `ft_print_params`, `ft_rev_params`, `ft_sort_params` |
| **c07** | Dynamic memory allocation | `ft_strdup`, `ft_range`, `ft_ultimate_range` |

### A few things that stood out

**c01** was the first real turning point. Understanding the difference between `int *a` and `int **a` — and actually *using* it to build `ft_div_mod` and `ft_ultimate_div_mod` — made pointers click.

**c05** was where recursion stopped being intimidating. Writing both the iterative and recursive versions of the same function side by side (`ft_iterative_factorial` vs `ft_recursive_factorial`) made the trade-offs obvious.

**c07** meant dealing with `malloc` for the first time with no safety net. `ft_ultimate_range` allocates an integer array and returns it through a double pointer — it forced me to think about ownership and who is responsible for freeing memory.

---

## Shell Modules

### shell00 — Shell Basics
File permissions, tar archives, git basics, and the `ls` output format. Not glamorous, but understanding `chmod` and how git tracks changes from the command line turned out to be essential for every Rush project after this.

### shell01 — Shell Scripting

| File | What it does |
|------|--------------|
| `print_groups.sh` | Lists all groups the current user belongs to |
| `find_sh.sh` | Finds all `.sh` files in the current directory and prints their names without the extension |
| `count_files.sh` | Counts files and directories separately in the current path |
| `MAC.sh` | Prints the MAC address of the network interface |

---

## Rush Projects

Rush projects were 48-hour weekend group challenges. No internet, no Stack Overflow — just the man pages and the team.

### Rush 00
A pattern-printing problem. The goal was to print a bordered rectangle of a given size using specific characters. Simpler than the later rushes but a good warm-up for thinking about edge cases under pressure.

### Rush 01 — Skyscraper Puzzle
A 4×4 grid solver for the Skyscraper puzzle. Given clues about how many buildings are visible from each side of the grid, the program finds a valid arrangement using recursive backtracking.

The trickiest part was getting the backtracking right — specifically, making sure a failed branch actually undid its changes before trying the next value. One bug was a hardcoded character instead of a loop variable; another was a premature `return` that broke the backtracking entirely. Both were subtle and took real debugging to find.

### Rush 02 — Number to Words (EN / PT / FR)
The most complex project of the Piscine. Given a number (up to billions), the program converts it into written words — in English, Portuguese, or French — by reading from an external dictionary file.

**Architecture highlights:**
- Dictionary parsing with custom key-value structs (`t_dict`)
- Language auto-detection from dict contents (`t_lang` enum: `LANG_EN`, `LANG_PT`, `LANG_FR`)
- Chunked number conversion (groups of 3 digits) via `t_convert_ctx`
- Separate conversion logic per language for teens, tens, and hundreds
- Dynamic output buffer (`t_buf`) to build the result string
- `stdin` mode for piped input

The header (`rush02.h`) ended up with over 40 function prototypes across 15+ source files. The main challenge was keeping the three language grammars consistent while sharing as much conversion logic as possible.

---

## Exam Practice

The `practice/` folder is where I drilled exercises outside of the daily modules to prepare for the exams.

### exam02 practice
Exercises at the level of the second in-piscine exam — working with strings, pointer manipulation, and basic output without any standard library functions beyond `write`.

| Exercise | Description |
|----------|-------------|
| `aff_a.c` | Print lowercase letters |
| `do_op.c` | Perform arithmetic based on string operator argument |
| `ft_putptr.c` | Print a pointer address in hex |
| `ft_str_is_printable.c` | Check if all chars in a string are printable |
| `ft_str_is_uppercase.c` | Check if all chars are uppercase |
| `ft_strncmp.c` | Compare two strings up to n characters |
| `ft_strncpy.c` | Copy up to n characters from source to destination |
| `ft_swap_case.c` | Swap case of every character in a string |
| `is_palindrome.c` | Check if a string reads the same backwards |
| `only_alphabet.c` | Print only alphabetic characters from a string |
| `rev_print.c` | Print a string in reverse |

### exam03 practice
Higher-difficulty exercises involving `malloc`, string transformations, and more complex algorithms.

| Exercise | Description |
|----------|-------------|
| `ft_split.c` | Split a string into an array of words (malloc required) |
| `ft_itoa.c` | Convert an integer to its string representation |
| `ft_atoi.c` | Convert a string to an integer |
| `ft_strdup.c` | Duplicate a string using malloc |
| `ft_strrev.c` | Reverse a string in place |
| `ft_range.c` | Allocate and return an array of integers from min to max |
| `inter.c` | Print characters present in both strings (no duplicates) |
| `union.c` | Print all unique characters from both strings in order |
| `expand_str.c` | Expand spaces in a string |
| `repeat_alpha.c` | Repeat each letter by its alphabetic position |
| `rstr_capitalizer.c` | Capitalize the last letter of each word |
| `fizzbuzz.c` | Classic FizzBuzz |
| `palindrome.c` | Check for palindrome |
| `search_and_replace.c` | Replace all occurrences of a char in a string |
| `tab_mult.c` | Print a multiplication table |
| `ulstr.c` | Swap case of every character |
| `aff_last_param.c` | Print the last command-line argument |
| `aff_z.c` | Print uppercase letters |
| `rev_print.c` | Print arguments in reverse order |

---

## Languages

- **C** — 90.5%
- **Shell** — 9.0%
- **Makefile** — 0.5%

---

## Notes

All C code was written to comply with the **42 Norm**: functions capped at 25 lines, no more than 4 variables per function, no `for` loops, no `printf`, no ternary operators. It's a constraint that teaches you to think carefully about how you structure logic before you start typing.

The `eu/aceito.txt` file is the signed ethics agreement — a commitment to the school's values and rules. It felt like a good thing to keep in the repo as a reminder of what the Piscine is actually about.

---

*42 São Paulo — Piscine 2026 | drocha-h*
