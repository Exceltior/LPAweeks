# LPAweeks
Exercícios de Laboratórios de Programação Avançada - Universidade de Coimbra

Este é o repositório de vários trabalhos de LPA, realizados no âmbito da licenciatura de Engenharia Informática, na Universidade de Coimbra. Os exemplos seguem vários tipos de progração como: Branch and Bound, Dinâmica, Recursividade simples, Greedy, Knapsack.

**LPA_W1.c**

* Task

Given a plan of topics to study (which includes precedences) and Joca's willingness of shortening the study time according to the rules mentioned above, you should implement an algorithm computes the study plan per day and returns:
  the maximum number of topics that he has to study in a single day
  the number of days that he will be desperate, i.e. the number of topics to study in each of those days is more than the maximum he can handle.

*Input

The first line contains three integers: the number of topics (m), the number of precedences (n) and the maximum number of topics that Jocas can study in a single day. Then, n lines follow. Each line has two integers, a and b, where a is the topic that must be studied before topic b.

*Output

For each test case, print the maximum number of topics that Jocas has to study in a single day and the number of days that he will be desperate, in a single line.

**LPA_W2.c**

*Task

Given the initial state and the maximum number of spins allowed, the goal is to make a program that will determine the shortest sequence of spins that reach the target.

The first line contains one integer: the maximum number of spins (n). Then, 2 lines follow, each with 2 integers describing the initial state.

*Output

For each test case, print the shortest sequence of moves to reach the target in a single line. Each spin is coded with a letter, indicating the spinning direction (R=right; L=left; U=up; D=down) and a number, indicating the column (if spin is U or D) or the row (if spin is R or L).

Since there may be more than one shortest sequence, the program should choose the one that is lexicographically smaller (means that D1 < D2 < L1 < L2 < R1 < R2 < U1 < U2).

**LPA_W3.c**

*Task

Given a sequence of balls, make a program that will determine the largest score that is possible to obtain.

*Input

The first line contains the number of test cases (t) in the same file. Information about the test cases follows in the following 2t lines. Each test case is described by 2 lines: the first contains the number of balls (n) and the sequence of n integers, each corresponding to the color of each ball.

*Output

For each test case, print the largest score.

**LPA_W4.c**

*Task

Given a matrix of profits, determine the largest sum of profits that is possible to obtain for a given interval of ages and incomes.

*Input

The first line of each test case describes the size of the matrix with two positive integers: number of lines (R), followed by the number of columns (C). The number of cells n is at most 250 000. Then R lines follow, each of which containing C profit values.

*Output

Output the largest sum of profits (which is always positive).

**LPA_W5.c**

*Task

Given the maximum size of the batch (c), the processing (T) and recovery (T') times as well as the information about the arriving time of each pair of shoes, determine the earliest time to finish the last batch. Assume that T = T' and that there is no need to take into account the recovery time after the processing of the last batch.

*Input

Each test case is a single line. The first three integers are c, n and T. Then, n positive integers follows, each of which corresponds to the arriving time of a pair of shoes (this data may not be ordered). Then, other test case may follow.

*Output

For each test case, print the earliest time to process the last batch.
