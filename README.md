# IsingModel-C

## Aim

**Aim:** Develop simple Ising Model using C.

## Ising model

### About

The Ising model, named after the physicists Ernst Ising and Wilhelm Lenz, 
is a mathematical model of ferromagnetism in statistical mechanics.

[Description](https://en.wikipedia.org/wiki/Ising_model#Two_dimensions)

## Usage

### Test

To execute test version, first `make test`. After compilation just run `./result.out`.  
Default parameters you can find at `main.c` in `#define TESTING` section.

### Your own parameters

If you want run program with you parameters, execute `make` and run the program with following arguments:
```
--temperature    | -T               Value of temperature
--row-number     | -nr              Row number in lattice
--column-number  | -nc              Column number in lattice
--iterations     | -nm              Number of iterations
```

## TODO

1. [x] Clear screen after execution;
2. [x] Use `argv` to scan variables;
3. [ ] Make real number of iterations;
