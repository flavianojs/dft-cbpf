# DFT course (CBPF) — hands-on material

Hands-on sessions of the practical half of the DFT course of the CBPF graduate program,
run with [Quantum ESPRESSO](https://www.quantum-espresso.org) on Google Colab.

The GitHub links below (Aula 6) no longer work: use the copy `dft-cbpf.zip` given in class.

## Layout

```
src/silicon/pw.scf.silicon.in       silicon SCF input (do not edit: copy it)
src/fe/pw.scf.fe.in                 bcc iron, spin-polarized (Aula 7)
src/pseudos/Si.pz-vbc.UPF           norm-conserving LDA pseudopotential for Si
src/pseudos/Fe.pbe-spn-rrkjus_psl.1.0.0.UPF   ultrasoft PBE pseudopotential for Fe
src/qe_fix.c                        fix for the pw.x crash on Ubuntu 24.04 (Colab)
calculations/reference/             reference outputs to compare with yours
calculations/aula6/, aula7/        created by you during the classes
notebooks/aula6_handson.ipynb       Aula 6 notebook
notebooks/aula7_handson.ipynb       Aula 7 notebook
slides das aulas/                   lecture slides (PDF)
```

## Aula 6 — getting started

1. Open the notebook in Colab:
   [Open aula6_handson.ipynb in Colab](https://colab.research.google.com/github/flavianojs/dft-cbpf/blob/main/notebooks/aula6_handson.ipynb)
2. Run section 1 (installs Quantum ESPRESSO 6.7 with `apt`, about 1 min).
3. Run section 2: it mounts your Google Drive and clones this repository into
   `MyDrive/dft-cbpf`. Your inputs and outputs are saved there and survive between sessions.
4. Follow the notebook. The first calculation is done by hand, in the Colab Terminal.

In a new session, re-run sections 1 and 2 (the clone is skipped if the folder already exists).

Expected numbers for every step are in `calculations/reference/expected_aula6.md`.

## Aula 7 — bands, DOS and magnetism

The course files are now distributed as `dft-cbpf.zip` (this folder), not through GitHub.

1. Put `dft-cbpf.zip` at the top level of your Google Drive ("My Drive").
2. Open `aula7_handson.ipynb` in Colab (from Drive: right click → Open with → Google Colaboratory).
3. Run section 1. The install cell writes the Ubuntu 24.04 fix itself; the Drive cell unpacks
   the zip with `unzip -n`: only files you do not have yet are extracted, nothing you already
   have (your Aula 6 notebook, your calculations) is overwritten. Without a `dft-cbpf` folder,
   it creates the whole folder.

Expected numbers: `calculations/reference/expected_aula7.md`.

## Credits

Inputs, pseudopotential and reference output come from the tutorial
[coteo-cbpf/Quantum-Espresso-tutorial](https://github.com/coteo-cbpf/Quantum-Espresso-tutorial),
licensed under [CC BY 4.0](http://creativecommons.org/licenses/by/4.0/).
The Si pseudopotential `Si.pz-vbc.UPF` is from the Quantum ESPRESSO pseudopotential library;
`Fe.pbe-spn-rrkjus_psl.1.0.0.UPF` is from PSLibrary (A. Dal Corso), as distributed with the tutorial.
