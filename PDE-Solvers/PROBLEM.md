# Finite Difference PDE Solvers — Heat & Wave Equations

Two specific-purpose finite-difference solvers. Each has its initial
condition hardcoded for the problem below; adapting either to a different
problem requires editing the source directly (the relevant lines are noted
in each section). Both programs print results to 4 decimal places.

---

## 1. Heat Equation (`SSSS_Heat_Eqn.cpp`)

### Problem Statement

$$\frac{\partial u}{\partial t} = \frac{\partial^2 u}{\partial x^2}$$

- Initial condition: $u(x, 0) = \sin(\pi x)$, for $0 \le x \le 1$
- Boundary conditions: $u(0, t) = 0$, $u(1, t) = 0$, for $t > 0$

Find:
1. $u(0.5, t)$ for $0 \le t \le 2$
2. $u(x, 0.5)$ for $0 \le x \le 1$

under a suitable spatial subdivision.

### Method

Explicit **Bendre–Schmidt scheme**:

$$u_{i+1,j} = \lambda\left(u_{i,j-1} + u_{i,j+1}\right) + (1-2\lambda)\,u_{i,j}, \qquad \lambda = \frac{ck}{h^2}$$

The program fixes $\lambda = 1/2$ by setting $k = h^2/(2c)$ once the spatial
subdivision `m` (and hence $h$) is entered. At $\lambda = 1/2$ the leading
$O(h^2)$ truncation-error term cancels, giving $O(h^4)$ local accuracy.

### Analytic Solution (for verification)

$$u(x,t) = \sin(\pi x)\, e^{-\pi^2 t}$$

Error should shrink roughly as $h^4$ as `m` is increased.

### Verification Run

```
c = 1
xi ui = 0 0
xf uf = 1 0
tf = 1
Spatial subdivision m = 10
```
Gives $h = 0.1$, $k = 0.005$, $n = 200$.

**Option 3**, $t = 0.5$ — $u(x,0.5) = \sin(\pi x)\cdot 0.007193$:

| x | exact |
|---|---|
| 0.0 | 0.0000 |
| 0.1 | 0.0022 |
| 0.2 | 0.0042 |
| 0.3 | 0.0058 |
| 0.4 | 0.0068 |
| 0.5 | 0.0072 |
| 0.6 | 0.0068 |
| 0.7 | 0.0058 |
| 0.8 | 0.0042 |
| 0.9 | 0.0022 |
| 1.0 | 0.0000 |

**Option 1**, spot-check $u(0.5, t) = e^{-\pi^2 t}$:

| t | exact |
|---|---|
| 0.2 | 0.1389 |
| 0.4 | 0.0193 |
| 0.6 | 0.0027 |
| 0.8 | 0.0004 |
| 1.0 | 0.0001 |

Expect agreement to within ~$\pm0.0001$–$0.0002$.

### Notes

- Query $x$ and $t$ values that are exact multiples of $h$ and $k$
  respectively, so they fall on the computational grid.
- To change the initial condition, edit the `u[0][j]` assignment.

---

## 2. Wave Equation (`SSSS_Wave_Eqn.cpp`)

### Problem Statement

$$\frac{\partial^2 u}{\partial t^2} = c^2\,\frac{\partial^2 u}{\partial x^2}$$

- Boundary conditions: $u(0, t) = 0$, $u(1, t) = 0$, for $t > 0$
- Initial velocity: $\left.\dfrac{\partial u}{\partial t}\right|_{t=0} = 0$
- Initial displacement: $u(x, 0) = \sin^3(\pi x)$

Find:
1. $u(0.5, t)$ for $0 \le t \le 1$
2. $u(x, 1.0)$ for $0 \le x \le 1$

using a suitable step size.

### Method

Explicit central-difference scheme:

$$u_{i+1,j} = \lambda^2\left(u_{i,j-1} + u_{i,j+1}\right) + 2(1-\lambda^2)\,u_{i,j} - u_{i-1,j}, \qquad \lambda = \alpha = \frac{ck}{h}$$

First time row ($i=1$), from the zero initial-velocity condition:

$$u_{1,j} = \frac{1}{2}\left[\lambda^2\left(u_{0,j-1} + u_{0,j+1}\right) + 2(1-\lambda^2)\,u_{0,j}\right]$$

Stability requires $\alpha \le 1$; the program rejects any $h, k$ pair for
which $\alpha > 1$. At $\alpha = 1$ the scheme is exact (it reduces to
d'Alembert's formula), so grid-point results can be checked directly against
the closed-form solution.

### Analytic Solution (for verification)

Using $\sin^3(\pi x) = \tfrac{3}{4}\sin(\pi x) - \tfrac{1}{4}\sin(3\pi x)$:

$$u(x,t) = \frac{3}{4}\sin(\pi x)\cos(\pi t) - \frac{1}{4}\sin(3\pi x)\cos(3\pi t)$$

### Verification Run

```
c = 1
xi ui = 0 0
xf uf = 1 0
tf = 1
ut = 0
h k = 0.1 0.1
```
Gives $\alpha = 1$, $m = 10$, $n = 10$.

**Option 2**, $x = 0.5$ — $u(0.5,t) = 0.75\cos(\pi t) + 0.25\cos(3\pi t)$:

| t | exact |
|---|---|
| 0.0 | 1.0000 |
| 0.1 | 0.8602 |
| 0.2 | 0.5295 |
| 0.3 | 0.2031 |
| 0.4 | 0.0295 |
| 0.5 | 0.0000 |
| 0.6 | −0.0295 |
| 0.7 | −0.2031 |
| 0.8 | −0.5295 |
| 0.9 | −0.8602 |
| 1.0 | −1.0000 |

**Option 3**, $t = 1.0$ — $u(x,1) = -0.75\sin(\pi x) + 0.25\sin(3\pi x)$:

| x | exact |
|---|---|
| 0.0 | 0.0000 |
| 0.1 | −0.0295 |
| 0.2 | −0.2031 |
| 0.3 | −0.5295 |
| 0.4 | −0.8602 |
| 0.5 | −1.0000 |
| 0.6 | −0.8602 |
| 0.7 | −0.5295 |
| 0.8 | −0.2031 |
| 0.9 | −0.0295 |
| 1.0 | 0.0000 |

Expect exact agreement to all 4 printed decimals (possibly off by 1 in the
last digit, since the source uses the truncated constant `3.1416` in place
of full double-precision $\pi$).

### Notes

- Use $h, k$ values (e.g. $h=k=0.1$) for which the queried $x$ and $t$ are
  exact multiples, so they fall on the grid.
- $\alpha = c \cdot k / h$ must satisfy $\alpha \le 1$.
- To change the initial condition, edit the `u[0][j]` and `u[1][j]`
  assignments.
