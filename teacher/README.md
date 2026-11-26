# teacher_version

This branch is `main` plus the instructor material:

- `notebooks/aula8_handson_solucao.ipynb`: the Aula 8 notebook solved (section 5 runs the whole project;
  the material is read from the environment variable `MATERIAL`, default `C`; set `MATERIAL = "Al"` or `"MgO"` in the cell to change it).
- `teacher/gabarito_aula8.md`: answer key (in Portuguese): tutorial numbers, model answers to the questions,
  reference values of the project for Al, C and MgO, and grading suggestions.

Everything was checked with QE 6.7 (apt). To update this branch after changes on `main`: `git merge main`.
