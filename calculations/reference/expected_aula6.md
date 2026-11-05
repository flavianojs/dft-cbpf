# Aula 6 — expected results

All numbers from Quantum ESPRESSO 6.7 (the version `apt` installs on Colab), with
`src/silicon/pw.scf.silicon.in` and `Si.pz-vbc.UPF`. `pw.scf.silicon.out` in this folder was
produced with QE 7.5 and gives the same total energy to every printed digit.

## Silicon SCF (input as given: ecutwfc = 30 Ry, 6×6×6 centered mesh, a = 10.26 bohr)

```
     total energy              =     -15.84818306 Ry
     total energy              =     -15.85011056 Ry
     total energy              =     -15.85037780 Ry
!    total energy              =     -15.85039422 Ry
```

## ecutwfc scan (6×6×6 centered, a = 10.26 bohr), E − E(60 Ry) in meV/atom

| ecutwfc (Ry) | 12 | 16 | 20 | 24 | 28 | 32 | 36 | 40 | 48 |
|---|---|---|---|---|---|---|---|---|---|
| ΔE | 310.49 | 97.11 | 40.23 | 17.42 | 10.51 | 6.69 | 4.29 | 2.55 | 0.63 |

At 30 Ry (the input value): 8.4 meV/atom.

## k-mesh scan (ecutwfc = 30 Ry), |E − E(16×16×16 shifted)| in meV/atom

| n | 2 | 4 | 6 | 8 | 10 | 12 |
|---|---|---|---|---|---|---|
| centered (n n n 0 0 0) | 1291.2 | 95.8 | 12.3 | 2.02 | 0.39 | 0.084 |
| shifted (n n n 1 1 1) | 82.9 | 1.40 | 0.040 | 0.0065 | 0.0027 | 0.0010 |

Irreducible k points: 6³ centered 16, 6³ shifted 28, 8³ centered 29, 12³ centered 72, 16³ shifted 408.

## Lattice parameter (ecutwfc = 40 Ry, 8×8×8 shifted, cubic fit of 9.9–10.6 bohr)

a0 = 10.208 bohr = 5.402 Å (experiment: 5.431 Å). Same a0 with 60 Ry.
vc-relax: 10.205 bohr.

## Plane waves at Γ

725 at 30 Ry, 2085 at 60 Ry (ratio 2.88; 2^(3/2) = 2.83).
