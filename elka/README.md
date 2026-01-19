*This project has been created as part of the 42 curriculum by lucpelle & samarkar.*

# Push Swap

## Description

Push Swap is a sorting algorithm project designed to sort data on a stack using the minimum number of operations.
It involves two stacks (`a` and `b`) and a set of allowed operations to reorder integers efficiently.

- Sort integers using **stack operations only**.
- Optimize for the **fewest number of moves**.
- Handle large sets of numbers **with efficient algorithms**.
- Check for **valid input** (no duplicates, only integers within limits).
- Implement various sorting strategies based on **disorder metric**.


## Instructions

### Compilation

The project can be compiled easily with **Makefile**:
```bash
make
```
This will create the executable:
```bash
./push_swap
```
Other useful Makefile commands:
```bash
make clean
make fclean
make re
```

**Optional strategy selector**:

| Option         | Description |
|----------------|-------------|
| `--simple`     | Forces the use of your **O(n²) algorithm**. |
| `--medium`     | Forces the use of your **O(n√n) algorithm**. |
| `--complex`    | Forces the use of your **O(n log n) algorithm**. |
| `--adaptive`   | Forces the use of your **adaptive algorithm based on disorder**. *(Default if no selector is given)* |

## Algorithm and Data Structure

Push Swap uses **two stacks** (`a` and `b`) and selects the sorting strategy based on the **disorder of the input** and the number of elements.

The program computes a **disorder metric** to estimate how unsorted the input stack is. This metric can guide the **adaptive strategy**, deciding whether a simple, medium, or complex algorithm will be more efficient.

### Sorting Strategies

- **Simple (`--simple` / small sets):**  
  - Iteratively **find the minimum element** in stack `a` and **push it to stack `b`**.  
  - Repeat until all elements are moved, then push them back to stack `a` in order.  
  - This is an **O(n²) algorithm** optimized for very small inputs.

- **Medium (`--medium` / medium sets):**  
  - Divide the input into **chunks** of sorted indices.  
  - Push elements from stack `a` to stack `b` according to their chunk.  
  - Rotate stacks as needed to minimize moves when reinserting elements back to `a`.  
  - This is an **O(n√n) algorithm** balancing efficiency and simplicity.

- **Complex (`--complex` / large sets):**  
  - Use **Radix Sort** on the indices of the elements.  
  - Push and rotate elements between `a` and `b` based on their binary representation.  
  - Efficiently sorts large sets in **O(n log n)** time.

- **Adaptive (`--adaptive` / default):**  
  - Compute the **disorder metric** of the input stack.  
  - Select **simple, medium, or complex** algorithm automatically based on the level of disorder.

The program always uses **stack operations only** (`sa`, `pb`, `ra`, etc.) and aims to **minimize the total number of moves**.

## Resources

- Linux man pages (malloc, free, write, exit).
- Stack and sorting algorithm tutorials in C.
- 42 Push Swap subject and PDF guidelines.
- AI Assistance: All code was manually written; AI was used only for documentation support.