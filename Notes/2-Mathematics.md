# Mathematics

## Algebra

### Sum of Power

$$
\begin{aligned}
    \sum_{k=1}^n{k^2} &= \frac{1}{6}n(n+1)(2n+1)\\[2ex]
    \sum_{k=1}^n{k^3} &= \Big(\sum {k}\Big)^2 = \Big(\frac{1}{2}n(n+1)\Big)^2
\end{aligned}
$$

### Fast Exponentiation

Fast exponentiation is a common way to calculate exponentiation with fast time

$$
a^n=
\begin{cases}
    1 &n=0\\[1ex]
    a &n=1\\[1ex]
    (a^2)^{n/2} &n\text{ is even}\\[1ex]
    a(a^2)^{(n-1)/2} &n\text{ is odd}
\end{cases}
$$

```c++
double pow_recursive(double a, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    double t = pow(a, n / 2);
    return t * t * pow(a, n % 2);
}

double pow_non_recursive(double a, int n)
{
    double ret = 1;
    while (n)
    {
        if (n % 2 == 1)
            ret *= a;
        
        a *= a;
        n >>= 1;
    }
    return ret;
}
```

Theoretically, both modes should perform the same in $O(log(n))$, but the recursive way perform slower as it occupies more resources.

## Number Theory

### Greatest Common Divisor (GCD)

$\text{gcd(a, b)}$ denotes the function that find the greatest integer divides both $a$ and $b$, which has the following principles

1. $\text{gcd(a, b)}$ = $\text{gcd(a, b-a)}$
2. $\text{gcd(a, 0)} = a$
3. $\text{gcd(a, b)}$ is the smallest positive number in $\{ax+by|x,y\in \bold{Z}\}$

Using the principle 1

```cpp
int gcd(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
```

The running time of the program is $O(\log {(a+b)})$

> the modula operation `a % b` follows the sign of `a`

### Congruence and Modulo Operation

$$
x\equiv y\;(\text{mod}\; n)
$$

- The equation denotes that $x$ and $y$ have the same remainder for the divisor $n$

#### Multiplicative Inverse

$x^{-1}$ is the inverse of $x$ modulo $n$ if $xx^{-1}\equiv 1\;(\text{mod}\; n)$

## Combinatorics

### Binomial Coefficients

$$
\begin{pmatrix}
    n \\[1ex]
    k
\end{pmatrix}
$$

The number of ways to pick $k$ objects from $n$ distinguishable objects

- Solution 1: Using the formula

$$
\begin{pmatrix}
    n \\[1ex]
    k
\end{pmatrix} = \frac{n(n-1)\cdots(n-k+1)}{k!}
$$

- Solution 2: Use Pascal's triangle

### Fibonacci Sequence

$$
F_n=
\begin{cases}
    0 &n=0\\[1ex]
    1 &n=1\\[1ex]
    F_{n-1}+F_{n-2} &n\geq 2
\end{cases}
$$

#### Analytical Solution

$$
F_n = (1/\sqrt{5})(\phi^n-\bar{\phi}^n)
$$

> $\phi = (1+\sqrt{5})/2$, $\bar{\phi} = (1-\sqrt{5})/2$

The solution runs relatively slow since $\sqrt{5}$ is irrational, and the results become inexact when $n$ is large

#### Fast Exponentiation by Matrix

$$
\begin{bmatrix}
    F_{n+1}\\[1ex]
    F_n
\end{bmatrix} = 
\begin{bmatrix}
    1&1\\[1ex]
    1&0
\end{bmatrix} 
\begin{bmatrix}
    F_{n}\\[1ex]
    F_{n-1}
\end{bmatrix} = 
\begin{bmatrix}
    1&1\\[1ex]
    1&0
\end{bmatrix}^n
\begin{bmatrix}
    F_{1}\\[1ex]
    F_{0}
\end{bmatrix}
$$

The problem could be simply solved by the fast exponentiation of matrix power

## Geometry

### Some Principles

- Precision matters
  - avoid using floating-point numbers
  - use `double` instead of `float`
  - avoid division
  - introduce $\epsilon$ in equality tests
    - use `if (abs(x) < EPS)` instead of `if (x == 0)`
- No hacks
  - randomization, probabilistic methods and small perturbations won't help in most cases

### 2D Vector

For a vector $\vec{v} = (x, y)$

- length: $\sqrt{x^2+y^2}$
- counterclockwise rotation by $\theta$
$$
\begin{bmatrix}
    \cos\theta&-\sin\theta\\[1ex]
    \sin\theta&\cos\theta
\end{bmatrix} 
\begin{bmatrix}
    x\\[1ex]
    y
\end{bmatrix}
$$
- normal vectors: $(y, -x)$ and $(-y, x)$

### Line-Line Intersection

Have two lines $ax+by+c=0$ and $dx+ey+f=0$

$$
\begin{bmatrix}
    a&b\\[1ex]
    d&e
\end{bmatrix} 
\begin{bmatrix}
    x\\[1ex]
    y
\end{bmatrix}= -
\begin{bmatrix}
    c\\[1ex]
    f
\end{bmatrix}
$$

Where the solution could be find by left-multiply

$$
\begin{bmatrix}
    x\\[1ex]
    y
\end{bmatrix}= - \frac{1}{ae-bd}
\begin{bmatrix}
    e&-b\\[1ex]
    -d&a
\end{bmatrix} 
\begin{bmatrix}
    c\\[1ex]
    f
\end{bmatrix}
$$

### Area of a Triangle

For three points $A$, $B$, $C$, the area could be find by the cross product of $AB$ and $AC$

$$
2S = \Bigg|(B-A)\times (C-A)\Bigg|
$$

#### Cross Product

$$
(x_1, y_1)\times (x_2, y_2) = 
\Bigg|\begin{matrix}
    x_1&x_2\\[1ex]
    y_1&y_2
\end{matrix}\Bigg|
= x_1y_2-x_2y_1
$$

### Area of a Simple Polygon

For the convex $P$ which has vertices $P_1$, $P_2$, $\cdots$, $P_n$, the area could be simply find by the equation

$$
2S = \Bigg|\sum_{i=2}^{n-1}(P_{i+1}-P_1)\times (P_i-P_1)\Bigg|
$$