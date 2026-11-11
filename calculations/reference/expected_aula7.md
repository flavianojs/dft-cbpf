# Aula 7 — expected results

All numbers from Quantum ESPRESSO 6.7 (the version `apt` installs on Colab), running
`notebooks/aula7_handson.ipynb` on a fresh clone. Times are on a 2-core machine, serial;
Colab can be up to 2× slower.

## Section 3 — silicon bands (Si.pz-vbc, 40 Ry, SCF 8×8×8 shifted, a = 10.26 bohr)

```
pw.x       si_scf         ~4 s     E = -15.85306732 Ry
pw.x       si_bands       ~9 s     number of k points= 132
bands.x    pp_bands       ~3 s     corners at x = [0.0, 0.866, 1.866, 2.2196, 2.2196, 3.2802]
```

| quantity | LDA (this run) | experiment |
|---|---|---|
| VBM | at Γ | at Γ |
| CBM | 0.85 of the way from Γ to X | ≈ 0.85 |
| indirect gap | 0.52 eV | 1.17 eV |
| direct gap at Γ | 2.56 eV | ≈ 3.4 eV |
| valence-band width | 11.93 eV | ≈ 12.5 eV |

## Section 4 — silicon DOS and PDOS (nscf 16×16×16 centered, 145 k points, nbnd = 12)

```
pw.x       si_nscf        ~20 s
dos.x      pp_dos_tetra   ~16 s
dos.x      pp_dos_gauss   ~1 s
electrons below the VBM: 8.00
projwfc.x  pp_projwfc     ~5 s
Atom #   1: total charge =   3.9629, s =  1.1434,
Atom #   1: total charge =   3.9629, p =  2.8195, ...
Spilling Parameter:   0.0093
```

## Section 5 — the silicon atom (ld1.x, all electrons, LDA PZ)

| | eV |
|---|---|
| −ε_3p, neutral atom (3p²) | 4.18 |
| −ε_3p at 3p^1.5 (Slater transition state) | 7.77 |
| I = E(Si⁺) − E(Si) | 7.84 |
| I, experiment | 8.15 |

Janak check (internal points f = 1.75, 1.5, 1.25): dE/df = −5.94, −7.79, −9.74 eV;
ε_3p = −5.92, −7.77, −9.73 eV.

## Section 6 — bcc iron (src/fe/pw.scf.fe.in: PBE, 45/360 Ry, 12×12×12 shifted, MV 0.01 Ry)

```
FM: E = -247.76382329 Ry,  M = 2.34 muB,  |M| = 2.49 muB
atom:    1    charge:   14.4239    magn:    2.4062    constr:    0.0000
NM: E = -247.71594175 Ry
E(FM) - E(NM) = -651 meV/atom
seed 0.00: M =  0.00 muB,  E - E(FM) =   651.5 meV
seed 0.05: M =  2.34 muB,  E - E(FM) =     0.0 meV
```

| ecutwfc (Ry) | M (μB) | E(FM) − E(NM) (meV/atom) |
|---|---|---|
| 30 | 2.81 | −899 |
| 45 | 2.34 | −651 |
| 60 | 2.29 | −651 |

Spin DOS (nscf 16×16×16, tetrahedra_opt, nbnd = 20): E_F = 17.411 eV; d-band centers
−1.86 eV (up) and +0.07 eV (down); exchange splitting 1.93 eV.

Whole notebook: about 4 min here.
