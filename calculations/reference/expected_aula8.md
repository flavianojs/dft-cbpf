# Aula 8 — expected numbers (hands-on, electron density of silicon)

QE 6.7 (apt, Ubuntu 24.04), serial. `src/silicon/pw.scf.silicon.in`: LDA, Si.pz-vbc, 30 Ry,
6x6x6, a = 10.26 bohr. pp.x of the same version.

| step | expected |
| --- | --- |
| scf | E = -15.85039422 Ry (about 1 s) |
| bands at Gamma only | eigenvalues -5.88, 6.06 (x3), 8.61 (x3), 9.34 eV |
| pp.x, plot_num = 0, (110) plane | n from 0.0008 (at the nuclei) to 0.086 electrons/bohr^3 (near the bond center) |
| integral of n over the cubic cell | 32.00 electrons |
| Gamma, bands 2-4, summed: n at bond center / max on the bond | 1.00 |
| Gamma, bands 5-7, summed: n at bond center / max on the bond | 0.06 |

Every pp.x run takes less than 2 s. The project has no expected numbers here: it is graded.
